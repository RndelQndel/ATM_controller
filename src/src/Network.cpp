
#include "Network.h"
#include <sys/socket.h>
#include <cstdlib>
#include <algorithm>

#pragma comment(lib, "ws2_32")
#pragma warning(disable:4996)

struct BankAccount{
    std::string AccountNum;
    long long   Balance;
};

std::vector<BankAccount> g_vecAccount = {
    { "123-45678-910", 5000 },
    { "234-56789-101", 100000000 },
    { "345-67891-012", 2000 },
    { "456-78910-123", 24500 },
    { "567-89101-234", 77978234000 },
    { "678-91012-345", 423000 },
    { "789-10123-456", 100 },
};

long long Network::StringToLongLong( const std::string& strValue )
{
    long long nValue = stoll(strValue);
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

    for( auto it: g_vecAccount )
    {
        pvec->push_back( it.AccountNum );
    }

    return( pvec );
}

std::string Network::Balance( const std::string& AccountNum )
{
    std::string temp = "";
    auto target = g_vecAccount.begin();
    for( ;target != g_vecAccount.end(); target++ )
    {
        if( 0 == target->AccountNum.compare(AccountNum) )
            break;
    }

    if( target == g_vecAccount.end() )
        return( temp );

    temp = std::to_string(target->Balance);
    return( temp );
}

std::string Network::Deposit( const std::string& AccountNum, const long long& value )
{
    std::string temp = "";
    auto target = g_vecAccount.begin();
    for( ;target != g_vecAccount.end(); target++ )
    {
        if( 0 == target->AccountNum.compare(AccountNum) )
            break;
    }

    if( target == g_vecAccount.end() )
        return( temp );

    target->Balance += value;
    temp = std::to_string(target->Balance);
    return( temp );
}

std::string Network::Withdraw( const std::string& AccountNum, const long long& value )
{
    std::string temp = "";
    auto target = g_vecAccount.begin();
    for( ;target != g_vecAccount.end(); target++ )
    {
        if( 0 == target->AccountNum.compare(AccountNum) )
            break;
    }

    if( target == g_vecAccount.end() )
        return( temp );

    target->Balance -= value;
    temp = std::to_string(target->Balance);
    return( temp );
}