//in rectangle.cpp
#include "rectangle.hpp"

/*
    default constructor for the class
    rectangle that will set its all member 
    variables to 1 
*/
rectangle::rectangle()
:length(1), breadth(1)
{
}
//parameterized constructor
rectangle::rectangle(int length, int breadth)
:length(length), breadth(breadth)
{
}
//mutator method for the class rectangle
void rectangle::setSize(int length, int breadth){
    this->length = length;
    this->breadth = breadth;
}

/*
    method that returns the area of the given
    rectangle
*/
int rectangle::getArea(){
    return (this->length * this->breadth);
}

/*
    method that returns the perimeter of the given
    rectangle
*/
int rectangle::getPerimeter(){
    return (2 * (this->length + this->breadth));
}