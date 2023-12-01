//in tea.hpp
/*
    Author: Sabin Badal
    Date: 10/8/2020

    Description:
    Class that simulates a tea which is made up of tea leaves. 
    and sugar 
*/
#pragma once
#include <iostream>
#include "beverage.hpp"
class tea : public beverage{
    private:
    double cost_of_tea_leaves;
    
    public:
    tea(double cost_of_water, double cost_of_sugar, double cost_of_tea_leaves);

    void compute_cost();
    
};