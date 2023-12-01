//in main.cpp
#include <iostream>
#include "rectangle.hpp"

//client program
int main(){
    rectangle* rect_one = new rectangle();
    rect_one->setSize(3,4);

    rectangle* rect_two = new rectangle(5, 6);

    std::cout << "*****For First Rectangle*****" << std::endl;
    std::cout << "Area = " << rect_one->getArea() << " units" << std::endl;
    std::cout << "Perimeter = " <<  rect_one->getPerimeter() << " units" << std::endl;

    std::cout << "*****For second rectangle Rectangle*****" << std::endl;
    std::cout << "Area = " << rect_two->getArea() << " units" << std::endl;
    std::cout << "Perimeter = " <<  rect_two->getPerimeter() << " units" << std::endl;


}