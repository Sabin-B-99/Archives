//in coffee.hpp
/*
    Author: Sabin Badal
    Date: 10/8/2020

    Description:
    Class that simulates a coffee which is made up of coffee powder. 
    and sugar 
*/
#pragma once
#include <iostream>
#include "beverage.hpp"
class coffee : public beverage{
    private:
    double cost_of_coffee_powder;
    
    public:
    coffee(double cost_of_water, double cost_of_sugar, double cost_of_coffee_powder);

    void compute_cost();
    
};