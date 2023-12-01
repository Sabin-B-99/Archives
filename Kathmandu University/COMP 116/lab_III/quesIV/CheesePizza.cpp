//in CheesePizza.cpp
#include "CheesePizza.hpp"
CheesePizza::CheesePizza(int price)
:Pizza(price)
{
}

/*
    Function that will display the price of clam pizza to the 
    output console once the pizza has been order.
*/
void CheesePizza::orderPizza(){
    std::cout << "You have ordered Cheese Pizza. Price: "  << price  << std::endl;
}