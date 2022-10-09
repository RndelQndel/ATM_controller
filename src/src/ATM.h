#include <iostream>
#include <cstring>
#include <cstdlib>

struct Information
{
	std::string ip_addr;
	std::string port;
};

enum Status {
	STATUS_PRE_INPUT = 1,
	STATUS_CARD_INPUT = 2,
	STATUS_PIN_INPUT =3,
	STATUS_SELECT_ACCOUNT = 4,
	STATUS_BALANCE = 5,
	STATUS_DEPOSIT = 6,
	STATUS_WITHDRAW = 7
};
