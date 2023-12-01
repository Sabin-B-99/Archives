//in cylinder.hpp
/*
    Author: Sabin Badal
    Date: 10/7/2020
    
    Description:
    Class that can is extended from circle base class and represents 
    a simple cylindrical shape. Through help of this class the area of
    the cylinder can be figured out.

    Data members of this class represents the height of the cylinder.
    And first constructor argument of this class initalizes its base class
    whose radius is as provided in that first argument.
*/
#pragma once
#include <iostream>
#include "circle.hpp"
class cylinder : public circle{
    private:
    double height;

    public: 
    cylinder();
    cylinder(double radius, double height);
    void getHeight();
    void getRadius();
    double area();
    void display();
};