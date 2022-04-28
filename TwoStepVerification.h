#ifndef __TwoStepVerification_h
#define __TwoStepVerification_h

#include<string>
#include "User_module.h"


class TwoStepVerification : public User
{
    public:
    std::string pin_number;
    std::string correct_pin();
};

#endif
