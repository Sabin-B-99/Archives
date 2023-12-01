//in triangle.cpp
#include "triangle.hpp"
#include <iostream>

triangle::triangle()
:base(0), height(0)
{
}

triangle::triangle(double base, double height) 
:base(base), height(height){
}

//function that displays the area of the given rectangle
void triangle::display_area(){
    std::cout << "Area of triangle: " << static_cast<double> (this->base * this->height) / 2 << std::endl;
}

/*
    function that will set the dimensions of the 
    desired shape according to user input. Function will
    prompt the user to enter the dimesnsions for the desired 
    shape and will the set the member variables are the user 
    input values
*/
void triangle::set_data(){
    std::cout << "******************" << std::endl;
    std::cout << "Enter base length of triangle" << std::endl;
    get_input(this->base);
    std::cout << "Enter height of triangle" << std::endl;
    get_input(this->height);
}