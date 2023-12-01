//in main.cpp
#include <iostream>
#include <iostream>
#include "point.hpp"

//client program
int main(){

    point* p1 = new point(3,5);

    point* p2 = new point();
    p2->input_points();

    double distance = point::get_distance(*p1, *p2);
    
    std::cout << "Eucledian Distance between given points " << distance << std::endl;
}