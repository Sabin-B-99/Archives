//in main.cpp
#include <iostream>
#include "mushroomPiz.hpp"
#include "hamPiz.hpp"
#include "cheesePiz.hpp"
//compile with g++ main.cpp cheesePiz.cpp hamPiz.cpp mushroomPiz.cpp pizza.cpp
/*
    Driver program that creates three pizza objects and 
    displays their respective prices
*/
int main(){
    pizza* pizI = new mushroomPiz();
    pizza* pizII = new hamPiz();
    pizza* pizIII = new cheesePiz();

    
    pizI->displayPrice();
    pizII->displayPrice();
    pizIII->displayPrice();
}