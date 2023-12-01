//in point.cpp
#include "point.hpp"
/*
    default constructor for the class point
    initialzies the member variable to 0, 0 
    i.e, the origin
*/
point::point()
:x(0), y(0)
{
}

//paramaterized constructor
point::point(const double& x, const double& y)
:x(x), y(y)
{
}

/*
    function that calculates the eucledian distance
    between two ponts p1 and p2
*/
double point::get_distance(const point& p1, const point& p2){
    return (sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2)));
}

/*
    function that prompts user to input his/her desired points.
    These input points will be set as values for member variables
    for point class
*/
void point::input_points(){
    std::cout << "Enter points: (x, y) " << std::endl; 
    force_num_input(this->x);
    force_num_input(this->y);
}

/*
    Function that will get the input from the terminal.
    This function will force the user to enter an int or 
    double value. Doing this will ensure type saftey as well 
    as prevent the whole program from crashing if the user 
    inputs a char or string variable instead of int or double 
    variable type 
*/
void point::force_num_input(double& x_or_y){
    while(!(std::cin >> x_or_y)){
        std::cin.clear(); //clear previous input
        std::cin.ignore(123, '\n'); //flushes the new line character remaining in the input buffer
        std::cout << "You need to enter a number." << std::endl;
    }
}


