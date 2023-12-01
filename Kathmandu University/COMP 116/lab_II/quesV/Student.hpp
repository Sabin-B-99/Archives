//in Student.hpp
/*
    Author: Sabin Badal
    Date: 10/7/2020
    
    Description:
    Class that simulates an student. 
    
    The academic_level data fields of this class represents the maximum 
    academic qualification of the studnet. While the institution data 
    field of this class represents the name of the academic instution
    in which the student studied.

    The member function of this dispay_info dsiplays all information 
    of data fields of this class.

    This class inherits form Person Base class 
*/
#pragma once
#include <iostream>
#include "Person.hpp"
class Student : virtual public Person{
    protected:
    std::string academic_level;
    std::string institution;

    public:
    Student();
    Student(const std::string& academic_level, const std::string& institution);

    void display_info();
};