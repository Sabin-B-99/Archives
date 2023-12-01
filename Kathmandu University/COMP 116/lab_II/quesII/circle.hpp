//in circle.hpp
#pragma once
/*
    Author: Sabin Badal
    Date: 10/7/2020
    
    Description:
    Class the extends(inherits) the shape class
    in order to simulate a circle and 
    perform related operations
*/
#include <iostream>
#include "shape.hpp"
class circle : public shape{
    private: 
    double radius;
    
    public:
    circle();
    circle(double radius);
    void display_area();
    void set_data();
};
