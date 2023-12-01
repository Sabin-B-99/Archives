//in Employee.cpp
#include "Employee.hpp"

Employee::Employee()
:year_worked(0), base_salary(0)
{
}

Employee::Employee(int year_worked, int base_salary)
:year_worked(year_worked), base_salary(base_salary)
{
}

void Employee::display_info(){
    std::cout << "****Work Info*****" <<std::endl;
    std::cout << "Years worked: " << this->year_worked << std::endl;
    std::cout << "Current Salary: " << calculate_salary() << std::endl;
}
/*
    Function that claultes the salary of an Employee.
    This salary increases by 15 percent from base salary 
    every working year of the employee.
*/
double Employee::calculate_salary(){
    return this->base_salary + (0.05 * this->base_salary * this->year_worked);
}