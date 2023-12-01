//In administrative.hpp
//In Employee.hpp
/*
    Author: Sabin Badal
    Date: 10/7/2020
    
    Description:
    Class that simulates an administrative tasks of any 
    employee of a given institution. The data member of this 
    class represents the name of department under which a 
    given employee works and another data field represents the
    task assigned by the department to him/her.

    Member function of this class can be used to display all info
    related to the administrtaive depratment under which an employee
    works and list of tasks which is assigned to an employee. Another
    member function of this class can be used to assign tasks to the 
    employee. 
    
    This class inherits form the Employee base class.
*/
#ifndef _ADMINISTRATIVE_HPP
#define _ADMINISTRATIVE_HPP
#include <iostream>
#include <vector>
#include "Employee.hpp"
#include <string>
class administrative : public virtual Employee{
    protected:
    std::string department_name;
    std::vector<std::string> tasks_assigned;

    public:
    administrative();
    administrative(const std::string& dep_name);

    void display_info();
    void add_assigned_tasks();
};
#endif