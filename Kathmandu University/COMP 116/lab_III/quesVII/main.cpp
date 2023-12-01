//in main.cpp
#include <iostream>
#include "user.hpp"
#include "normal.hpp"
#include "admin.hpp"
//compile with g++ main.cpp admin.cpp normal.cpp user.cpp

unsigned int display_main_menu();
void login(user& user);

int main(){
    user* adminI = new admin("KUAdmin", "KUDoCSE", 12345);
    user* userI = new normal("badalSabin", "KU123");

    unsigned int user_choice = display_main_menu();
   
    if(user_choice == 1){
        login(*adminI);
    }else if( user_choice == 2){
        login(*userI);
    }else{
        std::cerr << "Something went wrong. Reporting Incident." << std::endl;
    }
}

/*
    Function that display the main menu of the console application 
    through which user or admin can login to the system by providing 
    correct credentials to the system. But, first the user have to make
    it known to the system wheter he/she is an admin or a normal user by 
    choosing one of the two option in the main-menu. Function will return 
    a unsigned integer number which represents whether a user is admin or
    normal user.
*/
unsigned int display_main_menu(){
    std::cout << "Welcome to the application. Who are you? " << std::endl;
    std::cout << "1. Admin" << std::endl;
    std::cout << "2. Normal User" << std::endl;
    
    unsigned int user_choice = 0;
    std::cout << "Enter your choice: ";
    while (true)
    {
        std::cin >> user_choice;
        if (user_choice == 1 || user_choice == 2)
        {
            break;
        }
        std::cout << "Please enter a correct choice number(1-2)." << std::endl;
        std::cout << "1. Admin 2. Normal User" << std::endl;
    }
    return user_choice;
}

//function that will ask user or admin to provide correct credentials.
void login(user& user){
    user.authenticate();
}
