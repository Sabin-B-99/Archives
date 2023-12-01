#include "department.h"

department::department(int id, const std::string& name, int start_year, const std::string& address, int department_id, const std::vector<int>& sub_code_taught, double salary)
    : employee(id,name,start_year,address), department_id(department_id), sub_code_taught(sub_code_taught), salary(salary)
{
    std::cout << "Derived class constructor" << std::endl;
}

void department::display_info() const{
    std::cout <<"*******EMPLOYEE INFORMATION*************" << std::endl;
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Address: " << this->address << std::endl;
    std::cout << "Department id: " << this->department_id << std::endl;
    std::cout << "***************Subject taught**************" << std::endl;
    for (size_t i = 0; i < this->sub_code_taught.size(); i++)
    {   
        std::cout << this->sub_code_taught[i] << std::endl;
    }
}