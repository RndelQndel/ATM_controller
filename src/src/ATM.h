
#ifndef _ATM_H_
#define _ATM_H_

#include "CommonHeader.h"
#include "Network.h"
#include "CardReader.h"
#include <string>
#include <memory>

class ATM
{
private:
	std::shared_ptr<ATM> m_pInstance;
	Network m_cNetwork;
	CardReader m_cCardReader;
	std::string m_strIPAddr;
	std::string m_strPortNum;
public:
	ATM( std::shared_ptr<ATM> const& atm )
	{
		m_strIPAddr.clear();
		m_strPortNum.clear();

		m_pInstance = atm;
	}
	~ATM()
	{
		m_strIPAddr.clear();
		m_strPortNum.clear();

		m_pInstance = nullptr;
	}

	std::shared_ptr<ATM> GetATM( void ) { return( m_pInstance ); }
	Network* GetNetwork( void ) { return( &m_cNetwork ); }

	void DefaultSetting();
	unsigned int ATMWork();
};

#endif _ATM_H_