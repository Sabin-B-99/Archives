//in circle.hpp
/*
    Author: Sabin Badal
    Date: 10/8/2020
    
    Description:
    Class that simulates a circle shape whose 
    area can be figured out with the help of the findArea 
    function of this class.

    The diameter of the circle is represented by the single data member 
    present in the genric shape class that this circle class inherits.
*/
#pragma once
#include "shape.hpp"
#include <iostream>
class circle : public shape{

public:
circle();
circle(double diameter);
double findArea();
};