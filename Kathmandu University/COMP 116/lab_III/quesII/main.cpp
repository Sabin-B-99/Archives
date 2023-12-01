//in main.cpp
#include <iostream>
#include "m_string.hpp"
//complie with g++ main.cpp m_string.cpp 
int main(){
    /*
        We have initalized three m_string types.
        The casting with (char*) is done because C++
        is a strongly typed langauge which strongly checks
        for type saftey. If the (char*) part for these three
        lines are removed, the program will still compile and
        run without any errors, but we will get a warning about
        ISO C++ type saftey. The three lines can be changed into

        m_string* string = new m_string("Kathmandu");
        m_string* stringII = new m_string("University");
        m_string* stringIII = new m_string("University");

        A screen shot of code compiled and waring generated when
        the (char*) is not used is also provided below.
    */
    m_string* string = new m_string("Kathmandu");
    m_string* stringII = new m_string("University");
    m_string* stringIII = new m_string("University");

    string->operator+(*stringII);
    
    //Output: KathmanduUniversity
    std::cout << *string << std::endl;

    //Output: String Match
    if(stringII->operator=(*stringIII)){
        std::cout << "String Match" << std::endl;
    }else{
        std::cout << "String do not match" << std::endl;
    }

    //Output: String do not match
    if(string->operator=(*stringIII)){
        std::cout << "String Match" << std::endl;
    }else{
        std::cout << "String do not match" << std::endl;
    }

    string->operator=("Sabin Badal");
    //Output:Sabin Badal
    std::cout << *string << std::endl;
}