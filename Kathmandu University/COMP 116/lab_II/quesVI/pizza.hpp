//in pizza.hpp
/*
    Author: Sabin Badal
    Date: 10/7/2020

    Description:
    Abstract class that simulates a Pizza. And throug this class the 
    price of pizza can be known. 
*/
#pragma once
#include <iostream>
class pizza{
    protected:
    std::string name;
    double price;

    public:
    pizza(std::string name, double price);
    virtual void displayPrice() =0;

    protected:
    virtual double getPrice() =0;
};