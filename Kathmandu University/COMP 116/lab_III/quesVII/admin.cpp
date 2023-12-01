//in admin.cpp
#include "admin.hpp"
admin::admin(const std::string& name, const std::string& password, int phone_num)
:phone_num(phone_num), user(name, password)
{
}

/*
    Function that checks wether the usename and password as well 
    as the phone number of a admin of a apllication is correct or
    not. If the credintials are correct then the admin will be 
    given access to the application. Otherwise, he/she will be asked
    to enter correct credentials.
*/
void admin::authenticate(){
    std:: cout << "Please enter your username and password." << std::endl;
    std::string username;
    std::string pass;
    int number;
    std:: cout << "Username: ? " << std::endl;
    std::cin >> username;
    std:: cout << "Password: ? " << std::endl;
    std::cin >> password;
    std::cout << "Enter your official phone number, admin" << std::endl;
    std::cin >> number; 

    if(this->name.compare(username) == 0 && this->password.compare(password) == 0 && this->phone_num == number){
        std::cout << "Welcome!" << std::endl;
    }else{
        std::cout << "Sorry. Wrong credentials" << std::endl;  
    }
}