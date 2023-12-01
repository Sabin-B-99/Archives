//in rectangle.cpp
#include "rectangle.hpp"
#include <iostream>
rectangle::rectangle()
:length(0), breadth(0)
{
}
rectangle::rectangle(double length, double breadth)
:length(length), breadth(breadth)  
{
}

//function that displays the area of the given rectangle
void rectangle::display_area(){
    std::cout << "Area of a rectangle: " << this->length * this->breadth << std::endl;
}

//function that sets dimensions of a given rectangle
void rectangle::set_data(){
    std::cout << "******************" << std::endl;
    std::cout << "Enter length of rectangle" << std::endl;
    get_input(this->length);
    std::cout << "Enter breadth of rectangle" << std::endl;
    get_input(this->breadth);
}