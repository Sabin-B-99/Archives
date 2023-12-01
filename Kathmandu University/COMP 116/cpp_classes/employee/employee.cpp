#include "employee.h"

employee::employee(){
    this->id = 0;
    this->name = "";
    this->join_year = 0;
    this->address = "";
}

employee::employee(int id, const std::string& name, int join_year, const std::string& address)
    :id(id), name(name), join_year(join_year), address(address) 
{
    std::cout << "Base Class Constructor" << std::endl;
}
