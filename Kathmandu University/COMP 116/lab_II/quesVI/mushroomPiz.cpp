//in mushroomPiz.cpp
#include "mushroomPiz.hpp"

mushroomPiz::mushroomPiz()
:pizza("Mushroom Pizza", 200)
{
}

/*
    Function that will return the current price of the Mushroom pizza
*/
double mushroomPiz::getPrice(){
    return price;
}


/*
    Function that will display the price of Mushroom pizza to the 
    output console
*/
void mushroomPiz::displayPrice(){
    std::cout << "************************************" << std::endl;
    std::cout << "Price of " << name << " is " << price << std::endl;
    std::cout << "************************************" << std::endl;
}