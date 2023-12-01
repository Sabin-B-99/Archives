//in main.cpp
#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "shape.hpp"
double calculate_total_area(shape& rect, shape& circ);
void get_rect_dimens(double& length, double& breadth);
void get_circle_dimens(double& radius);
void get_input(double& side_input);
//compile with g++ main.cpp circle.cpp rectangle.cpp shape.cpp
int main(){
    double rect_length;
    double rect_breadth;
    double circ_diameter;
    
    get_rect_dimens(rect_length, rect_breadth);
    get_circle_dimens(circ_diameter);

    shape* rect = new rectangle(rect_length, rect_breadth);
    shape* circ = new circle(circ_diameter);

    std::cout << "Area of the basketball court is: " << calculate_total_area(*rect, *circ) << " sq. Units" << std::endl;    
}

/*
    Function that will claculate the combined area
    of a rectangle and a semicircle, which if combined \
    properly will shape as a basketball court
*/
double calculate_total_area(shape& rect, shape& circ){
    return rect.findArea() + ( circ.findArea() / 2);
}

/*
    function that will set the dimensions of the 
    desired rectangle object according to user input. Function will
    prompt the user to enter the dimesnsions for the desired 
    rectangle object
*/
void get_rect_dimens(double& length, double& breadth){
    std::cout << "Please enter the length of the rectangle" << std::endl;
    get_input(length);
    std::cout << "Please enter the breadth of the rectangle" << std::endl;
    get_input(breadth);
}
/*
    function that will set the dimensions of the 
    desired circle object according to user input. Function will
    prompt the user to enter the diameter for the desired 
    circle.
*/
void get_circle_dimens(double& diameter){
    std::cout << "Please enter the diameter of the circle" << std::endl;
    get_input(diameter);
}

/*
    Function that will get the input from the terminal.
    This function will force the user to enter an int or 
    double value. Doing this will ensure type saftey as well 
    as prevent the whole program from crashing if the user 
    inputs a char or string variable instead of int or double 
    variable type 
*/
void get_input(double& side_input){
    while(!(std::cin >> side_input)){
        std::cin.clear(); //clear previous input
        std::cin.ignore(123, '\n'); //flushes the new line character remaining in the input buffer
        std::cout << "You need to enter a number." << std::endl;
    }
}