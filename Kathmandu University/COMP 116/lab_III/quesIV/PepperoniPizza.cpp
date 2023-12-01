//in PepperoniPizza.cpp
#include "PepperoniPizza.hpp"
PepperoniPizza::PepperoniPizza(int price)
:Pizza(price)
{
}

/*
    Function that will display the price of pepperoni pizza to the 
    output console once the pizza has been order.
*/
void PepperoniPizza::orderPizza(){
    std::cout << "You have ordered Pepperoni Pizza. Price: "  << price  << std::endl;
}