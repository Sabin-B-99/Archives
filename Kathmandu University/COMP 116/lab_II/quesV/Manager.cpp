//in Manager.cpp
#include "Manager.hpp"
Manager::Manager()
:supervised_departs(0), Student(),Employee(), Person()
{
}

Manager::Manager(const std::string& name, int age, int year_worked, int base_salary,
                const std::string& academic_level, const std::string& institution,int supervised_departs)

:Person(name, age), Student(academic_level, institution),  Employee(year_worked,base_salary),
supervised_departs(supervised_departs)
{
}

void Manager::display_info(){
    Person::display_info();
    Employee::display_info();
    Student::display_info();
    std::cout << "****Managerial Experience*****" <<std::endl;
    std::cout << "Number of depratment under managerial supervision of ";
    std::cout << name << " is " << this->supervised_departs << std::endl;
}