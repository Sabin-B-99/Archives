//In Employee.hpp
/*
    Author: Sabin Badal
    Date: 10/7/2020
    
    Description:
    Class that simulates an Employee of any institutuion.
    This class data field represents the name of the employee
    as well as the years worked by the employee in a given
    institution and the age of the employee. Finally, another 
    data field of this class represents the base salary of the 
    employee.

    Data function of this class will display all info of the 
    employee. These info includes the number of year a given 
    employee has worked in a given institution, current salary 
    of the employee which increases by 15 percent of every years
    worked, and other info includes his years left before retirement. 
*/
#ifndef _EMPLOYEE_HPP
#define _EMPLOYEE_HPP
#include <iostream>
class Employee{
    protected:
    std::string name;
    int age;
    int years_worked;
    int base_salary;

    public:
    Employee();
    Employee(const std::string& name, int age, int years_worked, int base_salary);

    virtual void display_info();

    private:
    int calculate_salary();
    int time_before_retirement();
};
#endif