//in rectangle.hpp
#pragma once
#include "shape.hpp"
/*
    Author: Sabin Badal
    Date: 10/7/2020
    
    Description:
    Class the extends(inherits) the shape class
    in order to simulate a rectangle and 
    perform related operations
*/
class rectangle : public shape{
    private: 
    double length;
    double breadth;
    public:
        rectangle();
        rectangle(double length, double breadth);
        void display_area();
        void set_data();
};
