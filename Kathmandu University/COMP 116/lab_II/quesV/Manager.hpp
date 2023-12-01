//in Manager.hpp
/*
    Author: Sabin Badal
    Date: 10/7/2020
    
    Description:
    Class that simulates a manager of any organization. 
    
    The supervised_departs data fields of this class represents the number
    of deparment which this manager supervises in the given organization.

    The member function of this dispay_info dsiplays all information 
    of data fields of this class.

    This class inherits form Student Base class and Employee base class and
    tries to show the use of multiple inheritance. The arguments used in this 
    class' constructor is used to initialize the object of this class as well
    as its parent and grandparent class.  
*/
#pragma once
#include <iostream>
#include "Employee.hpp"
#include "Student.hpp"

class Manager: public Employee, public Student{
    private:
    int supervised_departs;

    public:
    Manager();
    Manager(const std::string& name, int age, int year_worked, int base_salary,
    const std::string& academic_level, const std::string& institution, int supervised_departs);

    void display_info();
};