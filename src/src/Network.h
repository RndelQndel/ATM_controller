
#ifndef _NETWORK_H_
#define _NETWORK_H_

#include "CommonHeader.h"
#include <unistd.h>
#include <string>
#include <memory>
#include <vector>

struct BankAccount
{
    std::string AccountNum;
};

typedef std::vector<BankAccount> VEC_BANK_ACCOUNT;
typedef std::shared_ptr<VEC_BANK_ACCOUNT> SHR_PTR;

class Network
{
private:
    std::string m_strIPAddr;
    std::string m_strPort;
    int         m_fd = 0;
public:
    void SetIPPort( const std::string &strIP, const std::string &strPort );
    SHR_PTR LoginCardPinNum( const std::string& strCardNum, const unsigned long long& ullPin );

};

#endif