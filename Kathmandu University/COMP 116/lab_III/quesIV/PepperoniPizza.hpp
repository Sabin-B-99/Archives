//in PepperoniPizza.hpp
/*
    Author: Sabin Badal
    Date: 10/8/2020
    
    Description:
    Class that can be used to find the price of 
    pepperoni pizza and this class can also be used 
    to order the this type of pizza
*/
#pragma once
#include <iostream>
#include "Pizza.hpp"

class PepperoniPizza : public Pizza{
    public:
    PepperoniPizza(int price);
    void orderPizza();
};