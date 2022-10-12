#include "ATM.h"

void ATM::DefaultSetting()
{
	using namespace std;

	cout << "==========================" << endl;
	cout << "INPUT PRE SETTING" << endl;
	cout << "IP ADDR : ";
	cin >> m_strIPAddr;
	cout << "Port Num : ";
	cin >> m_strPortNum;
	cout << "==========================" << endl;
}

unsigned int ATM::ATMWork()
{
	using namespace std;

	unsigned int unState = ATM_STATE::ATM_STATE_INIT;
	std::string card_num;
	unsigned long long pin_num;

	cout << "START the ATM SYSTEM" << endl;
	cout << endl;
	cout << "Input Card Number : ";
	cin >> card_num;
	cout << "Input PIN Number : ";
	cin >> pin_num;

	m_cCardReader.SetCardNum( card_num );
	m_cCardReader.SetPinNum( pin_num );
	// Card Num with Pin Num to Server

	// Get Response

	// 



	return( unState );
}