//in Pizza.hpp
/*
    Author: Sabin Badal
    Date: 10/8/2020

    Description:
    Abstract class that simulates a Pizza. And throug this class the 
    price of pizza can be known. 
*/
#pragma once
#include <iostream>
class Pizza{
    protected:
    int price;

    public:
    Pizza(int price);
    virtual void orderPizza() = 0;
};