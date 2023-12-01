//in cylinder.cpp
#include "cylinder.hpp"

cylinder::cylinder()
:height(0) , circle()
{ 
}

cylinder::cylinder(double radius,double height)
:height(height), circle(radius)
{
}

//function to retrieve the height of the cylinder from user
void cylinder::getHeight(){
    std::cout << "Enter height of the cylinder" << std::endl;
    get_input(this->height);
}

//function to retrieve the radius of the base of the cylinder from user
void cylinder::getRadius(){
    std::cout << "Enter the radius of circular base of cylinder" << std::endl;
    get_input(radius);
}

//function that claculates and returns total suface area of the cylinder
double cylinder::area(){
    return (2 * 3.14 * radius * radius) + (2 * 3.14 * radius * this->height);
}

//function that displays total surface area of the cylinder to the screen.
void cylinder::display(){
    std::cout << "The surface area of the cylinder is " << area() << " sq. units" << std::endl;
}