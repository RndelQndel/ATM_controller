
#include "Network.h"
#include <sys/socket.h>

#pragma comment(lib, "ws2_32")
#pragma warning(disable:4996)

void Network::SetIPPort( const std::string &strIP, const std::string &strPort )
{
    m_strIPAddr = strIP;
    m_strPort = strPort;
}