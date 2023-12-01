//in circle.cpp
#include "circle.hpp"

circle::circle()
:radius(0)
{
}

circle::circle(double radius)
:radius(radius)
{
}

//function to retrieve the total surface area of the circle form user
void circle::getRadius(){
    std::cout << "Enter radius of the circle" << std::endl;
    get_input(this->radius);
}
//function that claculates and returns area of the circle
double circle::area(){
    return 3.14 * this->radius * this->radius;
}
//function that displays the area of the circle to the output screen
void circle::display(){
    std::cout << "The area of the circle is " << area() << " sq. units" << std::endl;
}

/*
    Function that will get the input from the terminal.
    This function will force the user to enter an int or 
    double value. Doing this will ensure type saftey as well 
    as prevent the whole program from crashing if the user 
    inputs a char or string variable instead of int or double 
    variable type 
*/
void circle::get_input(double& side_input){
    while(!(std::cin >> side_input)){
        std::cin.clear(); //clear previous input
        std::cin.ignore(123, '\n'); //flushes the new line character remaining in the input buffer
        std::cout << "You need to enter a number." << std::endl;
    }
}