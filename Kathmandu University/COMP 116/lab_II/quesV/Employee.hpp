//in Employee.hpp
/*
    Author: Sabin Badal
    Date: 10/7/2020
    
    Description:
    Class that simulates an Employee of any instutuion.
    This class data field represents the age of the employee. 
    
    Finally, another data field of this class represents 
    the base salary of the employee.

    Data function of this class will display all info of the 
    employee. These info includes the number of year a given 
    employee has worked in a given institution, current salary 
    of the employee which increases by 5 percent of every years
    worked.

    This class inherits form Person Base class 
*/
#pragma once
#include <iostream>
#include "Person.hpp"
class Employee : virtual public Person{
    protected:
    int year_worked;
    int base_salary;

    public:
    Employee();
    Employee(int year_worked, int base_salary);

    void display_info();

    private:
    double calculate_salary();

};