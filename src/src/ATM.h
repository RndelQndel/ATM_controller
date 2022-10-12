
#ifndef _ATM_H_
#define _ATM_H_

#include "CommonHeader.h"
#include "Network.h"
#include "CardReader.hpp"
#include <string>
#include <memory>

class ATM
{
private:
	Network m_cNetwork;
	CardReader m_cCardReader;
	std::string m_strIPAddr;
	std::string m_strPortNum;

	void GetExit( std::string& exit );
	void GetCardPin();
	void GetService( unsigned int& unService );
	std::string PrintBankAccount( const SHR_PTR pvecBank );

public:
	ATM( )
	{
		m_strIPAddr.clear();
		m_strPortNum.clear();
	}
	~ATM()
	{
		m_strIPAddr.clear();
		m_strPortNum.clear();
	}

	Network* GetNetwork( void ) { return( &m_cNetwork ); }

	void DefaultSetting();
	unsigned int ATMWork();
};

#endif