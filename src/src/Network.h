
#ifndef _NETWORK_H_
#define _NETWORK_H_

#include "CommonHeader.h"
#include <unistd.h>
#include <string>
#include <memory>
#include <vector>

typedef std::vector<std::string> VEC_BANK_ACCOUNT;
typedef std::shared_ptr<VEC_BANK_ACCOUNT> SHR_PTR;

class Network
{
private:
    std::string m_strIPAddr;
    std::string m_strPort;

    long long StringToLongLong( const std::string& strValue );
public:
    void SetIPPort( const std::string &strIP, const std::string &strPort );
    SHR_PTR LoginCardPinNum( const std::string& strCardNum, const unsigned long long& ullPin );
    std::string Balance( const std::string& AccountNum );
    std::string Deposit( const std::string& AccountNum, const long long& value );
    std::string Withdraw( const std::string& AccountNum, const long long& value );
};

#endif