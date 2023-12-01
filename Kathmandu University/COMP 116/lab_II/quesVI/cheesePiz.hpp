//in cheesePiz.hpp
/*
    Author: Sabin Badal
    Date: 10/7/2020
    
    Description:
    Class that can be used to find the price of 
    Cheese pizza and display the price in the
    console screen.
*/
#pragma once
#include <iostream>
#include "pizza.hpp"
class cheesePiz : public pizza{
    public:
    cheesePiz();
    double getPrice();
    void displayPrice();
};