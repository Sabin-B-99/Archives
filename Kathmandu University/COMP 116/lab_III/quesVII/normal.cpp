//in normal.cpp
#include "normal.hpp"
normal::normal(const std::string& name, const std::string& password)
:user(name, password)
{
}


/*
    Function that checks wether the usename and password 
    of a normal user of a apllication is correct or
    not. If the credintials are correct then the normal user will be 
    given access to the application. Otherwise, he/she will be asked
    to enter correct credentials.
*/
void normal::authenticate(){
    std:: cout << "Please enter your username and password." << std::endl;
    std::string username;
    std::string pass;
    std:: cout << "Username: ? " << std::endl;
    std::cin >> username;
    std:: cout << "Password: ? " << std::endl;
    std::cin >> password;

    if(this->name.compare(username) == 0 && this->password.compare(password) == 0){
        std::cout << "Welcome!" << std::endl;
    }else{
        std::cout << "Sorry. Wrong credentials" << std::endl;  
    }
}