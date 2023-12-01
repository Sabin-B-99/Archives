//in normal.hpp
#pragma once
#include "user.hpp"

/*
    Author: Sabin Badal
    Date: 10/8/2020

    Description:
    Class that tries to simulate a user of a certain application
    with a unique username and password. This class can be used to
    authenticate username and password of normal user of a application. 
*/
class normal: public user{
    public:
    normal(const std::string& name, const std::string& password);
    void authenticate();
};