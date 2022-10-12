
#ifndef _CARD_READER_H_
#define _CARD_READER_H_

#include "CommonHeader.h"
#include <string>

class CardReader
{
private:
    std::string m_strCardNum;
    unsigned long long m_ullPin = 0;
public:
    CardReader() : m_ullPin( 0 )
    {
        m_strCardNum.clear();
    }
    ~CardReader()
    {
        m_ullPin = 0;
        m_strCardNum.clear();
    }

    void SetCardNum( std::string &CardNum ) { m_strCardNum = CardNum; }
    std::string GetCardNum( void ) { return m_strCardNum; }

    void SetPinNum( unsigned long long ullPin ) { m_ullPin = ullPin; }
    unsigned long long GetPinNum( void ) { return m_ullPin; }
};

#endif