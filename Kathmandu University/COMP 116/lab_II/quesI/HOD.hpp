//In HOD.hpp
/*
    Author: Sabin Badal
    Date: 10/7/2020
    
    Description:
    Class that simulates HOD of an academic institution.
    Data member of this class represents the total number
    of student reading in the given institution, total 
    number of courses offereed by the given institution
    and the total number of staffs working in the institution.

    The function members of this class will print the total
    info about the data members present in the HOD class as 
    well as it will print out the total information about 
    other classes that it inherits from.  

    The construction of this class will initialize all 
    the data member of this class as well as data members of
    class that it inherits.

    This class inherits form administrative and academic base classes
    and shows the use of multiple inheritance. The arguments used in this 
    class' constructor is used to initialize the object of this class as well
    as its parent and grandparent class.
*/
#ifndef _HOD_HPP
#define _HOD_HPP
#include <iostream>
#include <vector>
#include "academic.hpp"
#include "administrative.hpp"
class HOD : public academic, public administrative{
    private:
    int no_students_in_dept;
    int no_of_staffs;
    int no_of_course;

    public:
    HOD();
    HOD(const std::string& name, int age, int years_worked, int base_salary,
        const std::string& dep_name,
        const std::string& designation, int students, int course, int staffs);


    void display_info();
};
#endif