//in shape.hpp
/*
    Author: Sabin Badal
    Date: 10/8/2020
    
    Description:
    Class that can be extended by its child class and this class 
    represents a generic shape whose area can be figured out.
*/
#pragma once
#include <iostream>
class shape
{
protected:
    double side1;
public:
    shape();
    shape(double side1);
    virtual double findArea() =0;
};
