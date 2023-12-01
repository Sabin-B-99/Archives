//in hamPiz.cpp
#include "hamPiz.hpp"
hamPiz::hamPiz()
:pizza("Ham Pizza", 150)
{
}

/*
    Function that will return the current price of the Ham pizza
*/
double hamPiz::getPrice(){
    return price;
}

/*
    Function that will display the price of Ham pizza to the 
    output console
*/
void hamPiz::displayPrice(){
    std::cout << "************************************" << std::endl;
    std::cout << "Price of " << name << " is " << price << std::endl;
    std::cout << "************************************" << std::endl;
}
