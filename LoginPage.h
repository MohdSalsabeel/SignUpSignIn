#ifndef __LoginPage_h
#define __LoginPage_h

#include<string>
#include "User_module.h"

// This is Login Page declarationa

class LoginPage : public User
{
    public:
    std::string login();
};

#endif
