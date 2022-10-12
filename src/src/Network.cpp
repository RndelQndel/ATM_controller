
#include "Network.h"
#include <sys/socket.h>
#include <cstdlib>
#include <algorithm>

#pragma comment(lib, "ws2_32")
#pragma warning(disable:4996)

int Network::StringToInt( const std::string& strValue )
{
    int nValue = stoi(strValue);
    return( nValue );
}

void Network::SetIPPort( const std::string &strIP, const std::string &strPort )
{
    m_strIPAddr = strIP;
    m_strPort = strPort;
}

SHR_PTR Network::LoginCardPinNum( const std::string& strCardNum, const unsigned long long& ullPin )
{
    SHR_PTR pvec = std::make_shared<VEC_BANK_ACCOUNT>();

    BankAccount a, b, c, d;

    a.AccountNum = "123-45678-910";
    b.AccountNum = "234-56789-101";
    c.AccountNum = "345-67891-012";
    d.AccountNum = "456-78910-123";

    pvec->push_back(a);
    pvec->push_back(b);
    pvec->push_back(c);
    pvec->push_back(d);

    return( pvec );
}

std::string Network::Balance( const std::string& AccountNum )
{
    return( "5000" );
}

std::string Network::Deposit( const std::string& AccountNum, const int& value )
{
    int balance = StringToInt("5000");
    balance += value;
    std::string temp = std::to_string(balance);
    return( temp );
}

std::string Network::Withdraw( const std::string& AccountNum, const int& value )
{
    int balance = StringToInt("5000");
    balance -= value;
    std::string temp = std::to_string(balance);
    return( temp );
}