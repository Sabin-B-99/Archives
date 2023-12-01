//in rectangle.hpp
/*
    Author: Sabin Badal
    Date: 10/8/2020
    
    Description:
    Class that simulates a rectangle shape whose 
    area can be figured out with the help of the findArea 
    function of this class.

    The only data member present in this class represents the length
    of the rectangle and breadth is represented by the single data member 
    present in the genric shape class that this rectangle class inherits.
*/
#include "shape.hpp"
#include <iostream>
class rectangle : public shape{
private:
double length;

public:
rectangle();
rectangle(double length, double breadth);
double findArea();
};