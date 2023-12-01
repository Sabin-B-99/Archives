//In administrative.cpp
#include "administrative.hpp"

administrative::administrative()
:department_name("")
{
}

administrative::administrative(const std::string& dep_name)
:department_name(dep_name)
{
}

void administrative::display_info(){
    std::cout << "Tasks assigned by " << department_name << " to " << name << " are: " << std::endl;
    for(size_t i = 0; i < tasks_assigned.size(); i++){
        std::cout << tasks_assigned[i] << std::endl;
    }
}

void administrative::add_assigned_tasks(){
    std::cout << "Enter tasks to assign to " << name << std::endl;
    std::cout << "Enter 999 to quit" << std::endl;
    std::string tasks;
    while(true){
        std::getline(std::cin,tasks); 
        if(tasks.compare("999") == 0){
            break;
        }
        this->tasks_assigned.emplace_back(tasks);
    }
}