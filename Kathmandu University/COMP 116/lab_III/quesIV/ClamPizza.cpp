//in ClamPizza.cpp
#include "ClamPizza.hpp"
ClamPizza::ClamPizza(int price)
:Pizza(price)
{
}
/*
    Function that will display the price of clam pizza to the 
    output console once the pizza has been order.
*/
void ClamPizza::orderPizza(){
    std::cout << "You have ordered Clam Pizza. Price: "  << price  << std::endl;
}