//in main.cpp
#include <iostream>
#include "shape.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

//compile with g++ main.cpp rectangle.cpp shape.cpp triangle.cpp circle.cpp
//here uint32_t is modern C++ way of writing unsigned integer whose size is 4 bytes
uint32_t display_main_menu();
void process_main_menu_choice(uint32_t choice_no);

int main(){
    uint32_t menu_choice_no;
    while (true)
    {
        menu_choice_no = display_main_menu();
        process_main_menu_choice(menu_choice_no);
        //if menu choice was exit the the program will end
        if(menu_choice_no == 4){
            break;
        }
    }
}
/*
    function that will prompt the user to select a 
    choice i.e, a number between 1-4 form the keyboard and 
    return that choice. This choice will then later be used 
    to diplay the area of choosen shape or exit out of the program.
*/
uint32_t display_main_menu(){
    std::cout << "*****Main-Menu******" << std::endl;
    std::cout << "Calculate Area for: " << std::endl;
    std::cout << "1.Rectangle: " << std::endl;
    std::cout << "2.Triangle: " << std::endl;
    std::cout << "3.Circle: " << std::endl;
    std::cout << "4.Exit" << std::endl;;

    uint32_t choice_no = 0;
    std::cout <<"****ENTER YOUR CHOICE NUMBER****" << std::endl;
    while(true){
        //forcing user to enter a number type and not other types like char or string
        while(!(std::cin >> choice_no)){
            std::cin.clear(); //clear previous input
            std::cin.ignore(123, '\n');
            std::cout << "You need to enter a number." << std::endl;
        }
        if(choice_no >= 1 && choice_no <= 4){
            break;
        }
        std::cerr << "Enter a choice number betweeen 1 and 4" << std::endl;
    }
    return choice_no;
}
/*
    This function will process the user selected choice in pervious menu and will
    prompt the user to input the desired dimensions for the choosen shape and
    will display the area for that shape before returning to main menu.
*/
void process_main_menu_choice(uint32_t choice_no){
    if(choice_no == 1){
        //process for a rectangle
        shape* rect  = new rectangle();
        rect->set_data();
        rect->display_area();
        std::cout << "********************" << std::endl;
    }else if(choice_no == 2){
        //process for a triangle
        shape* tri = new triangle();
        tri->set_data();
        tri->display_area();
        std::cout << "********************" << std::endl;
    }else if(choice_no == 3){
        //process for a circle
        shape* circ = new circle();
        circ->set_data();
        circ->display_area();
        std::cout << "********************" << std::endl;
    }
    else if(choice_no == 4){
        //if user chooses to exit the program
        std::cout << "Thank you! Have a nice day. :)" << std::endl;
    }else{
        std::cerr << "Error: Unexpected behaviour. Terminating program prematurely. Reporting incident" << std::endl;
        exit(0);
    }
}

