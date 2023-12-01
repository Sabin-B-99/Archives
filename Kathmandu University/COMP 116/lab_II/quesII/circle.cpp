//in circle.cpp
#include <iostream>
#include "circle.hpp"
circle::circle()
:radius(0)
{
}
circle::circle(double radius)
:radius(radius)  
{
}

//function that displays the area of the given circle
void circle::display_area(){
    std::cout << "Area of a circle: " << this->radius * this->radius * 3.14 << std::endl;
}
//function that sets radius of a given circle
void circle::set_data(){
    std::cout << "******************" << std::endl;
    std::cout << "Enter radius of circle" << std::endl;
    get_input(this->radius);
}