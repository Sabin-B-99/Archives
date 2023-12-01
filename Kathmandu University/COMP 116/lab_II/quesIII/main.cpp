//in main.cpp
#include <iostream>
#include "circle.hpp"
#include "cylinder.hpp"
//compile with g++ circle.cpp cylinder.cpp main.cpp
int main(){
    std::cout << "************Area of circle***********" << std::endl;
    circle* circ = new circle();
    circ->getRadius();
    circ->display();
    std::cout << "**************************************" << std::endl;
    std::cout << "***********Area of cylinder***********" << std::endl;
    cylinder* cilind = new cylinder();
    cilind->getRadius();
    cilind->getHeight();
    cilind->display();
    std::cout << "**************************************" << std::endl;
}