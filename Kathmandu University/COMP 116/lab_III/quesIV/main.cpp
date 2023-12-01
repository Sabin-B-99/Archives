//in main.cpp
#include <iostream>
#include "PepperoniPizza.hpp"
#include "ClamPizza.hpp"
#include "CheesePizza.hpp"

unsigned int display_main_menu();
void process_main_choice(unsigned int choice);

//compile with g++ main.cpp CheesePizza.cpp PepperoniPizza.cpp ClamPizza.cpp Pizza.cpp
int main(){
    unsigned int user_choice = display_main_menu();
    process_main_choice(user_choice);
}

/*
    Function that display the main menu of the console application 
    through which user can interact to order the type of pizza they 
    want. Function will return a unsigned integer number which represents
    the type of pizza they have orderd.
*/
unsigned int display_main_menu(){
    std::cout << "Welcome to Domino's Pizza. Enter your choice." << std::endl;
    std::cout << "1. Cheese Pizza" << std::endl;
    std::cout << "2. Pepperoni Pizza" << std::endl;
    std::cout << "3. Clam Pizza" << std::endl;

    unsigned int user_choice = 0;
    std::cout << "Enter your choice: ";
    while (true)
    {
        std::cin >> user_choice;
        if (user_choice >= 1 && user_choice <= 3)
        {
            break;
        }
        std::cout << "Only three types of pizza are currently available" << std::endl;
        std::cout << "Please enter a correct choice number(1-3)." << std::endl;
        std::cout << "1. Cheese Pizza 2. Pepperoni Pizza 3. Clam Pizza " << std::endl;
    }
    return user_choice;
}
/*
    Once the pizza has been orderd through the main menu 
    the number represnting the pizza choice in the main menu 
    will be passed as argument in this function. And this function
    will display the price of the pizza representd by the passed 
    number.
*/
void process_main_choice(unsigned int choice){
    if(choice == 1){
        Pizza* cheesPiz = new CheesePizza(160);
        cheesPiz->orderPizza();
    }else if (choice == 2)
    {
        Pizza* pepPiz = new PepperoniPizza(140);
        pepPiz->orderPizza();
    }else if(choice == 3)
    {
        Pizza* clmPiz = new ClamPizza(120);
        clmPiz->orderPizza();
    }else{
        std::cerr << "Ssomething went wrong! Order Discarded. Reporting Incident." << std::endl;
    }
}