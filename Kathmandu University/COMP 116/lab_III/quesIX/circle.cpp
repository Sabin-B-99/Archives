//in circle.cpp
#include "circle.hpp"
circle::circle()
:shape(0)
{
}

/*
    Patamerized constructor that initalzies the 
    data member of the parent shape class. This data member 
    of the parent shape class represents the diameter of the circle
    object.
*/
circle::circle(double diameter)
:shape(diameter)
{
}


/*
    Function that returns a the area of a give circle object.
*/
double circle::findArea(){
    double radius = side1 / 2;
    return (3.14 * radius * radius);  
}