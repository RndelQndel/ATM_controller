#include "CommonHeader.h"
#include "ATM.h"

int main( void )
{
    unsigned int unAtmState = ATM_VALUE::ATM_STATE::ATM_STATE_INIT;
    ATM atm;    

    atm.DefaultSetting();

    while( unAtmState != ATM_VALUE::ATM_STATE::ATM_STATE_STOP )
    {
        unAtmState = atm.ATMWork();
    }

    return ( 0 );
}