//in CheesePizza.hpp
/*
    Author: Sabin Badal
    Date: 10/8/2020
    
    Description:
    Class that can be used to find the price of 
    cheese pizza and this class can also be used 
    to order the this type of pizza
*/
#pragma once
#include <iostream>
#include "Pizza.hpp"

class CheesePizza : public Pizza{
    public:
    CheesePizza(int price);
    void orderPizza();
};