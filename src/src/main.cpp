#include "CommonHeader.h"
#include "ATM.h"

int main( void )
{
    unsigned int unAtmState = ATM_STATE::ATM_STATE_INIT;
    std::shared_ptr<ATM> pAtm = std::make_shared<ATM>();
    ATM ATM( pAtm );

    pAtm->DefaultSetting();

    while( unAtmState != ATM_STATE::ATM_STATE_STOP )
    {
        unAtmState = pAtm->ATMWork();
    }

    pAtm = nullptr;

    return ( 0 );
}