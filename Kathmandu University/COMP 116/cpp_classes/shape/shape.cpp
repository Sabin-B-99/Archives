//in shape.cpp
#include "shape.hpp"
#include <iostream>
/*
    default constructor that will 
    initialzie all the member variables of the 
    shape class as 1
*/
shape::shape()
:side_one(1), side_two(1)
{
}

//parameterized constructor
shape::shape(double side_one, double side_two)
:side_one(side_one), side_two(side_two)
{
}

//destructor
shape::~shape(){    
}

/*
    function that will set the dimensions of the 
    desired shape according to user input. Function will
    prompt the user to enter the dimesnsions for the desired 
    shape and will the set the member variables are the user 
    input values
*/
void shape::set_data(){
    std::cout << "******************" << std::endl;
    std::cout << "Enter longer dimension (length/base)" << std::endl;
    get_input(this->side_one);
    std::cout << "Enter shorter dimension (breadth/height)" << std::endl;
    get_input(this->side_two);
}
/*
    Function that will get the input from the terminal.
    This function will force the user to enter an int or 
    double value. Doing this will ensure type saftey as well 
    as prevent the whole program from crashing if the user 
    inputs a char or string variable instead of int or double 
    variable type 
*/
void shape::get_input(double& side_input){
    while(!(std::cin >> side_input)){
        std::cin.clear(); //clear previous input
        std::cin.ignore(123, '\n'); //flushes the new line character remaining in the input buffer
        std::cout << "You need to enter a number." << std::endl;
    }
}
