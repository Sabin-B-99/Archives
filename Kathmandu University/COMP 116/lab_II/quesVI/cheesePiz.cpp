//in cheesePiz.cpp
#include "cheesePiz.hpp"

cheesePiz::cheesePiz()
:pizza("Cheese Pizza", 100)
{
}

/*
    Function that will return the current price of the Cheese pizza
*/
double cheesePiz::getPrice(){
    return price;
}

/*
    Function that will display the price of Cheese pizza to the 
    output console
*/
void cheesePiz::displayPrice(){
    std::cout << "************************************" << std::endl;
    std::cout << "Price of " << name << " is " << price << std::endl;
    std::cout << "************************************" << std::endl;
}
