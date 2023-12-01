//in m_string.hpp
/*
    Author: Sabin Badal
    Date: 10/8/2020

    Description:
    Class that tries to simulate the stirng class of the standard C++ langauage.
    So, This class can be used to create a string data type and manipulate it.
    Member functions, other than constructor of this class, are overloaded operators
    namley binary addition operator, and two overloaded '=' operators. And the final 
    overloaded operator of this class is an '<<' operator. 
    This program is written to show the use of operator overloading feature of 
    C++ langauge to manipulate a string.
*/
#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
class m_string
{
private:
    char* string;
public:
    /*
        Parameterized constructor that initialzies the one and only member 
        field of this class, which is a pointer of char type. 
    */
    m_string(char* string);
    //destructor to free up dangaling pointers and memory
    ~m_string();
    /*
        Overloaded binary addition operator that adds or more specifically
        concatenates two m_string (which are strings) types. 
    */
    void operator+(const m_string& word);
    /*
        Overloaded assignmnet operator that checks wether two given m_string
        types are equal or not. It returns 'true' if they are equal and false
        otherwise. For Example: If one m_string is "Sabin" and other m_string
        is "Badal" then this function will compare these two types and return 
        false. Note: The evaluation is case sensitive. 
    */
    bool operator=(const m_string& word);
    /*
        Overloaded assignment operator that assigns the literal string on the left 
        side of the assignment as the new value of the m_string type on present in 
        its right side.
        Ex:
        Consider, m_String obj = "Sabin"; Then if we write another expression as
        obj = "Badal", then the old value which is "Sabin" will be overwritten by
        the new value "Badal"
    */
    void operator=(const char* word);
    /*
        Oveloaded stream out operator that direclty print the m_string type to the 
        standard output screen.
    */
    friend std::ostream& operator << (std::ostream& out_stream, const m_string& obj);
};
