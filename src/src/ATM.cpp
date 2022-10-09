#include "ATM.h"
#include <unistd.h>

Information g_Info;

int main()
{
	using namespace std;
	string answer;

	cout << "==========================" << endl;
	cout << "INPUT PRE SETTING" << endl;
	cout << "IP ADDR : ";
	cin >> answer;
	g_Info.ip_addr = answer;
	cout << "Port Num : ";
	cin >> answer;
	g_Info.port = answer;
	cout << "==========================" << endl;

	while(true)
	{
		string card_num, pin_num;
		cout << "START the ATM SYSTEM" << endl;
		cout << endl;
		cout << "Input Card Number : ";
		cin >> card_num;
		cout << "Input PIN Number : ";
		cin >> pin_num;

		// communicate to server

		// success to balance, deposit, withdraw

		break;
	}

	return( 0 );
}
