// Common Header

#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>

namespace ATM_VALUE{
    namespace ATM_STATE{
        constexpr unsigned int ATM_STATE_INIT        = 0;
        constexpr unsigned int ATM_STATE_RUNNING     = 1;
        constexpr unsigned int ATM_STATE_STOP        = 2;
    };

    namespace ATM_SERVICE{
        constexpr unsigned int ATM_SERVICE_NONE      = 0;
        constexpr unsigned int ATM_SERVICE_BALANCE   = 1;
        constexpr unsigned int ATM_SERVICE_DEPOSIT   = 2;
        constexpr unsigned int ATM_SERVICE_WITHDRAW  = 3;
    };
};

#endif
