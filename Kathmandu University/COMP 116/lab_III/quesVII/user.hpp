//in user.hpp
/*
    Author: Sabin Badal
    Date: 10/8/2020

    Description:
    Abstract class that tries to simulate a user of a certain application
    with a unique username and password. This abstract class can be extended
    and used to authenticate username and password of a certain types of users
    namely, admin and normal users of the application. 
*/
#pragma once
#include <iostream>
class user{
    protected:
    std::string name;
    std::string password;
    public:
    user(const std::string& name, const std::string& password);
    virtual void authenticate() =0;
};