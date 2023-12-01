//in Person.hpp
/*
    Author: Sabin Badal
    Date: 10/7/2020
    
    Description:
    Class that simulates a person. 
    
    The data member name and age of this class represents
    name and age person respectively.

    The member function of this dispay_info dsiplays all information 
    of data fields of this class.   
*/
#pragma once
#include <iostream>
class Person{
    protected:
    std::string name;
    int age;
    
    public:
    Person();
    Person(const std::string& name, int age);

    virtual void display_info();
};