//In academic.hpp
/*
    Author: Sabin Badal
    Date: 10/7/2020
    
    Description:
    Class that simulates an academic credibility of a given
    employee of an academic institution. 
    
    First data  members of this class represents the 
    academic designation of an employee For Ex: 
    Lecturer, Proffessor, HOD, Associate Proffessor etc.

    Also, another data member of this class reprsents 
    the list of all the course taught by the given employee

    And, final data member of this class represents the name list of 
    departments in which the employee teaches the courses. 

    Member function of this class displays all the information 
    about the given academic employee. This academic employee's 
    information includes all the names of course taught by the 
    employee and the names of departments in which the academic
    professional teaches.

    Other private function inculdes helper functions that helps to 
    display these aformentioned informations.

    And two public member functions namely add_course_taught() and
    add_depart_taught will help the driver program to add the list of
    course and list of departments taught respectively.

    This class inherits form the Employee base class.

    Note: I have use #ifndef macros here in this program but in most of
    the programs I will be using #pragma once preprocessor directives to
    save time. 
*/
#ifndef _ACADEMIC_HPP
#define _ACADEMIC_HPP
#include <iostream>
#include <vector>
#include <string>
#include "Employee.hpp"

class academic : public virtual Employee{
    private:
    std::string designation;
    std::vector<std::string> course_taught;
    std::vector<std::string> depart_taught;

    public:
    academic();

    academic(const std::string& designation);

    void display_info();

    void add_course_taught();
    void add_depart_taught();

    private:
    void display_course_taught();
    void display_depart_taught();
};
#endif