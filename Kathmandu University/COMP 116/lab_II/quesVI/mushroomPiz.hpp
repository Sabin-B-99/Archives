//in mushroomPiz.hpp
/*
    Author: Sabin Badal
    Date: 10/7/2020
    
    Description:
    Class that can be used to find the price of 
    Mushroom pizza and display the price in the
    console screen.
*/
#pragma once
#include <iostream>
#include "pizza.hpp"
class mushroomPiz : public pizza{
    public:
    mushroomPiz();
    double getPrice();
    void displayPrice();
};