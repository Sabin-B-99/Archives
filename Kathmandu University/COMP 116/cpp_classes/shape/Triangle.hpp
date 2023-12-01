//in triangle.hpp
#ifndef _TRIANGLE_HPP
#define _TRIANGLE_HPP
#include "shape.hpp"
/*
    class the extends(inherits) the shape class
    in order to simulate a triangle and 
    perform related operations
*/
class Triangle : public shape{
    public:
        Triangle();
        Triangle(double base,double height);
        void display_area();
};
#endif