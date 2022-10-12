
#ifndef _ATM_H_
#define _ATM_H_

#include "CommonHeader.h"
#include <string>

class ATM
{
private:
	std::string m_strIPAddr;
	std::string m_strPortNum;
public:
	void DefaultSetting();
	unsigned int ATMWork();
};

#endif _ATM_H_