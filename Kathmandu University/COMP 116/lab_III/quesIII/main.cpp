//in main.cpp
#include <iostream>
#include "coffee.hpp"
#include "tea.hpp"
#include "beverage.hpp"
//compile with g++ main.cpp coffee.cpp tea.cpp beverage.cpp
/*
    Client Program that initailizes members of coffee class and tea
    class and displays their respective prices.
*/
int main(){
    beverage* bvrgC = new coffee(5,5,10);
    beverage* bvrgT = new tea(5,5,5);
    bvrgC->compute_cost();
    bvrgT->compute_cost(); 
}