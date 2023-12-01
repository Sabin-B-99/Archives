//in rectangle.cpp
#include "rectangle.hpp"
#include <iostream>
/*
    default constructor that will call the default constructor
    of its parent class and initializes its members accordingly
*/
Rectangle::Rectangle()
:shape()
{
}
/*
    parameterized constructor that will call the parameterized constructor
    of its parent class and initializes its members accordingly
*/
Rectangle::Rectangle(double side_one, double side_two)
:shape(side_one,side_two)    
{
}

//function that displays the area of the given rectangle
void Rectangle::display_area(){
    std::cout << "Area of a rectangle: " << this->side_one * this->side_two << std::endl;
}