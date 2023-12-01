//In academic.cpp
#include "academic.hpp"

academic::academic()
:designation("")
{
}

academic::academic(const std::string& designation)
:designation(designation)
{
}

void academic::display_info(){
    std::cout << designation << " " << name << " teaches following courses" << std::endl;
    display_course_taught();
    std::cout << designation << " " << name << " teaches in following departments" << std::endl;
    display_depart_taught();
}

void academic::add_course_taught(){
    std::cout << "Enter courses taught by " << name << std::endl;
    std::cout << "Enter 999 to quit" << std::endl;
    std::string course_taught;
    while(true){
        std::getline(std::cin,course_taught); 
        if(course_taught.compare("999") == 0){
            break;
        }
        this->course_taught.emplace_back(course_taught);
    }
}

void academic::add_depart_taught(){
    std::cout << "Enter departments in which " << name  << " teaches." << std::endl;
    std::cout << "Enter 999 to quit" << std::endl;
    std::string depart_taught;
    while(true){
        std::getline(std::cin,depart_taught); 
        if(depart_taught.compare("999") == 0){
            break;
        }
        this->depart_taught.emplace_back(depart_taught);
    }
}

void academic::display_course_taught(){
    for (size_t i = 0; i < course_taught.size(); i++)
    {
        std::cout << course_taught[i] << std::endl;
    }   
}

void academic::display_depart_taught(){
    for (size_t i = 0; i < depart_taught.size(); i++)
    {
        std::cout << depart_taught[i] << std::endl;
    }
}