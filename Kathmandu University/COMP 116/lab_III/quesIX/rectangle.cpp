//in rectangle.cpp
#include "rectangle.hpp"
rectangle::rectangle()
:length(0), shape(0)
{
}

rectangle::rectangle(double length, double breadth)
:length(length), shape(breadth)
{
}

/*
    Function that returns a the area of a give rectangle object.
*/
double rectangle::findArea(){
    return this->length * side1;
}