//in main.cpp
#include <iostream>
#include "shape.hpp"
#include "Triangle.hpp"
#include "Rectangle.hpp"


unsigned int display_main_menu();
void process_main_menu_choice(unsigned int choice_no);

int main(){
    unsigned int menu_choice_no;
    while (true)
    {
        menu_choice_no = display_main_menu();
        process_main_menu_choice(menu_choice_no);
        //if menu choice was exit the the program will end
        if(menu_choice_no == 3){
            break;
        }
    }
}
/*
    function that will prompt the user to select a 
    choice i.e, a number between 1-3 form the keyboard and 
    return that choice. This choice will then later be used 
    to diplay the area of choosen shape or exit out of the program.
*/
unsigned int display_main_menu(){
    std::cout << "*****Main-Menu******" << std::endl;
    std::cout << "Calculate Area for: " << std::endl;
    std::cout << "1.Rectangle: " << std::endl;
    std::cout << "2.Triangle: " << std::endl;
    std::cout << "3.Exit" << std::endl;;

    unsigned int choice_no = 0;
    std::cout <<"****ENTER YOUR CHOICE NUMBER****" << std::endl;
    while(true){
        //forcing user to enter a number type and not other types like char or string
        while(!(std::cin >> choice_no)){
            std::cin.clear(); //clear previous input
            std::cin.ignore(123, '\n');
            std::cout << "You need to enter a number." << std::endl;
        }
        if(choice_no >= 1 && choice_no <= 3){
            break;
        }
        std::cerr << "Enter a choice number betweeen 1 and 3" << std::endl;
    }
    return choice_no;
}
/*
    This function will process the user selected choice in pervious menu and will
    prompt the user to input the desired dimensions for the choosen shape and
    will display the area for that shape before returning to main menu.
*/
void process_main_menu_choice(unsigned int choice_no){
    if(choice_no == 1){
        //process for a rectangle
        shape* rectangle  = new Rectangle();
        rectangle->set_data();
        rectangle->display_area();
        rectangle->~shape();
        std::cout << "********************" << std::endl;
    }else if(choice_no == 2){
        //process for a triangle
        shape* triangle = new Triangle();
        triangle->set_data();
        triangle->display_area();
        triangle->~shape();
        std::cout << "********************" << std::endl;
    }else if(choice_no == 3){
        //if user chooses to exit the program
        std::cout << "Thank you! Have a nice day. :)" << std::endl;
    }else{
        /*
            99.99 percent sure that the program will never reach this portion
            without changing above client functions.
            If it does reach here then I need to revise understanding of this language :)
        */
        std::cerr << "Error: Unexpected behaviour. Terminating program prematurely. Reporting incident" << std::endl;
        exit(0);
    }
}

