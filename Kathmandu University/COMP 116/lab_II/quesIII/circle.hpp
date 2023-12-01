//in circle.hpp
/*
    Author: Sabin Badal
    Date: 10/7/2020
    
    Description:
    Class that represents a circle shape. Data member
    of this class represents the raduis of a circle.

    Member function of this class can be used to retrive
    area, get radius input form the usera nd disply the
    calculated radius to the output screen.
*/
#pragma once
#include <iostream>
class circle{
    protected:
    double radius;
    
    public:
    circle();
    circle(double radius);
    virtual void getRadius();
    virtual double area();
    virtual void display();

    protected:
    void get_input(double& num_input);
};