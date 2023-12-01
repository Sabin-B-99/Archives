//in triangle.hpp
#pragma once
#include "shape.hpp"
/*
    Author: Sabin Badal
    Date: 10/7/2020
    
    Description:
    Class the extends(inherits) the shape class
    in order to simulate a triangle and 
    perform related operations
*/
class triangle : public shape{
    private:
    double base;
    double height;
    public:
        triangle();
        triangle(double base,double height);
        void display_area();
        void set_data();
};