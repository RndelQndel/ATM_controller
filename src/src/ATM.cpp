#include "ATM.h"

using namespace std;

void ATM::GetExit( std::string& exit )
{
	cout << endl << "==========================" << endl;
	cout << "Want to Exit? [y/n]" << endl;
	cin >> exit;
	cout << "==========================" << endl << endl;
}

std::string ATM::PrintBankAccount( const SHR_PTR pvecBank )
{
	if( 0 == pvecBank->size() )
	{
		cout << "====No Account====" << endl;
		return( "" );
	}

	cout << endl << "Print Account" << endl;
	unsigned int unIndex = 0;
	for( auto it : *pvecBank )
	{
		cout << ++unIndex << ". " << it << endl;
	}

	do{
		cout << endl << "Select Bank Accout :";
		cin >> unIndex;
	}
	while( unIndex <=0 || pvecBank->size() < unIndex );

	auto it = pvecBank->at( unIndex - 1 );

	return( it );
}

void ATM::GetCardPin()
{
	std::string card_num;
	unsigned long long pin_num;

	cout << "=====Thank you=====" << endl;
	cout << "START the ATM SYSTEM" << endl << endl;
	cout << "Input Card Number : ";
	cin >> card_num;
	cout << "Input PIN Number : ";
	cin >> pin_num;

	m_cCardReader.SetCardNum( card_num );
	m_cCardReader.SetPinNum( pin_num );
}

void ATM::GetService( unsigned int& unService )
{
	do
	{
		cout << endl << "==========================" << endl;
		cout << "0. Exit" << endl;
		cout << "1. Balance" << endl;
		cout << "2. Deposit" << endl;
		cout << "3. Withdraw" << endl;
		cout << "Select a Service : ";
		cin >> unService;
	} while ( unService < 0 || 3 < unService );
}

void ATM::DefaultSetting()
{
	cout << endl << "==========================" << endl;
	cout << "INPUT PRE SETTING" << endl;
	cout << "IP ADDR : ";
	cin >> m_strIPAddr;
	cout << "Port Num : ";
	cin >> m_strPortNum;
	cout << "==========================" << endl << endl;
}

unsigned int ATM::ATMWork()
{
	unsigned int unService = ATM_VALUE::ATM_SERVICE::ATM_SERVICE_NONE;
	unsigned int unState = ATM_VALUE::ATM_STATE::ATM_STATE_RUNNING;
	unsigned int unValue = 0;
	std::string exit = "n", AccountNum, Response;

	GetExit(exit);

	if( 0 == exit.compare("y") )
		return( ATM_VALUE::ATM_STATE::ATM_STATE_STOP );

	GetCardPin();
	SHR_PTR pvecBank = m_cNetwork.LoginCardPinNum( m_cCardReader.GetCardNum(), m_cCardReader.GetPinNum() );
	AccountNum = PrintBankAccount( pvecBank );
	pvecBank = nullptr;

	GetService( unService );
	switch( unService )
	{
		case ATM_VALUE::ATM_SERVICE::ATM_SERVICE_BALANCE :
		{
			cout << "=======BALANCE=======" << endl;
			cout << "Balance : ";
			Response = m_cNetwork.Balance( AccountNum );
			break;
		}
		case ATM_VALUE::ATM_SERVICE::ATM_SERVICE_DEPOSIT :
		{
			cout << "=======DEPOSIT=======" << endl;
			cout << "Enter the Value : ";
			cin >> unValue;
			cout << endl << "Balance : ";
			Response = m_cNetwork.Deposit( AccountNum, unValue );
			break;
		}
		case ATM_VALUE::ATM_SERVICE::ATM_SERVICE_WITHDRAW :
		{
			cout << "=======WITHDRAW=======" << endl;
			cout << "Enter the Value  : ";
			cin >> unValue;
			cout << endl << "Balance : ";
			Response += m_cNetwork.Withdraw( AccountNum, unValue );
			break;
		}
		default :
		{
			Response = "=========EXIT=========";
			break;
		}
	}

	cout << Response << endl;
	cout << "Thank you" << endl;

	return( unState );
}