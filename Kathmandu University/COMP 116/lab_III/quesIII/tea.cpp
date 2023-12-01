//in tea.cpp
#include "tea.hpp"
/*
    Parameterized constructor whose first two arguments will initialize the member 
    vairbles of beverage class which is the parent class of tea class. The third and
    final argument of this constructor initialzies the member variable of tea class
    itself, which represents cost of tea leaves
*/
tea::tea(double cost_of_water, double cost_of_sugar, double cost_of_tea_leaves)
:cost_of_tea_leaves(cost_of_tea_leaves), beverage(cost_of_water, cost_of_sugar)
{
}
/*
    Function that will compute the total cost of a given tea.
*/
void tea::compute_cost(){
    double final_price = cost_of_water + cost_of_sugar + this->cost_of_tea_leaves;
    std::cout << "****************RECIEPT*****************" << std::endl;
    std::cout << "The price for your tea is: Rs." << final_price << std::endl;
    std::cout << "**********Have a nice day!**************" << std::endl;
}