//in rectangle.hpp
#pragma once
#include "shape.hpp"
/*
    class the extends(inherits) the shape class
    in order to simulate a rectangle and 
    perform related operations
*/
class Rectangle : public shape{
    public:
        Rectangle();
        Rectangle(double length, double breadth);
        void display_area();
};