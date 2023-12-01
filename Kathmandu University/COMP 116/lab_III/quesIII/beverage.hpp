//in beverage.hpp
/*
    Author: Sabin Badal
    Date: 10/8/2020

    Description:
    Class that simulates a beverage which is made up mainly of water 
    and sugar 
*/
#pragma once
#include <iostream>
class beverage
{
protected:
    double cost_of_water;
    double cost_of_sugar;
public:
    beverage(double cost_of_water, double cost_of_sugar);
    virtual void compute_cost() =0;
};
