//in coffee.cpp
#include "coffee.hpp"
/*
    Parameterized constructor whose first two arguments will initialize the member 
    vairbles of beverage class which is the parent class of tea class. The third and
    final argument of this constructor initialzies the member variable of coffee class
    itself, which represents cost of coffee powder.
*/
coffee::coffee(double cost_of_water, double cost_of_sugar, double cost_of_coffee_powder)
:cost_of_coffee_powder(cost_of_coffee_powder), beverage(cost_of_water, cost_of_sugar)
{
}
/*
    Function that will compute the total cost of a given coffee.
*/
void coffee::compute_cost(){
    double final_price = cost_of_water + cost_of_sugar + this->cost_of_coffee_powder;
    std::cout << "******************RECIEPT**************" << std::endl;
    std::cout << "The price for your coffee is: Rs." << final_price << std::endl;
    std::cout << "***********Have a nice day!************" << std::endl;
}