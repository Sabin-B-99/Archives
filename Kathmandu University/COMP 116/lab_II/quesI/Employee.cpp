//In Employee.cpp
#include "Employee.hpp"

Employee::Employee()
:name(""), age(0), years_worked(0), base_salary(0)
{ 
}

Employee::Employee(const std::string& name, int age, int years_worked, int base_salary)
:name(name), age(age), years_worked(years_worked), base_salary(base_salary)
{
}

void Employee::display_info(){
    std::cout << "*******Information of the employee********" << std::endl;
    std::cout << "Employee Name: " << this->name << std::endl;
    std::cout << "Current Age: " << this->age << std::endl;
    std::cout << "Years worked for this institution: " << this->years_worked << std::endl;
    std::cout << "Current Salary: " << calculate_salary() << std::endl;
    std::cout << "Working years left before retirement: " << time_before_retirement() << std::endl;
}

/*
    Function that claultes the salary of an Employee.
    This salary increases by 15 percent from base salary 
    every working year of the employee.
*/
int Employee::calculate_salary(){
    return base_salary + ((0.15 * base_salary) * this->years_worked);   
}

/*
    Function that calculates and returns year left before retirement of 
    an employee. An employee retires when he is of age greater than or equal 
    to 61.
*/
int Employee::time_before_retirement(){
    if(age < 18 || age > 60){
        return 0;
    }
    return 60 - age;
}