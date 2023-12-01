//in Triangle.cpp
#include "Triangle.hpp"
#include <iostream>
/*
    default constructor that will call the default constructor
    of its parent class and initializes its members accordingly
*/
Triangle::Triangle()
:shape()
{
}
/*
    parameterized constructor that will call the parameterized constructor
    of its parent class and initializes its members accordingly
*/
Triangle::Triangle(double side_one, double side_two) 
:shape(side_one, side_two){
}

//function that displays the area of the given rectangle
void Triangle::display_area(){
    std::cout << "Area of Triangle: " << static_cast<double> (this->side_one * this->side_two) / 2 << std::endl;
}