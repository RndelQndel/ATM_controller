#include "CommonHeader.h"
#include "ATM.h"

int main( void )
{
    unsigned int unAtmState = ATM_STATE::ATM_STATE_INIT;
    ATM catm;

    catm.DefaultSetting();

    while( unAtmState != ATM_STATE::ATM_STATE_STOP )
    {
        unAtmState = catm.ATMWork();
    }

    return ( 0 );
}