//in admin.hpp
/*
    Author: Sabin Badal
    Date: 10/8/2020

    Description:
    Class that tries to simulate a user of a certain application
    with a unique username and password. This class can be used to
    authenticate username and password of admin of a application.
    A admin needs to provide more information to the system to be 
    authenticated and this more information is represeted by the 
    admin's phone number. 
*/
#pragma once    
#include "user.hpp"
#include <iostream>
class admin: public user{
    private:
    int phone_num;
    public:
    admin(const std::string& name, const std::string& password, int phone_num);
    void authenticate();
};