//in main.cpp
#include "m_time.hpp"
#include <iostream>
//compile with g++ main.cpp m_time.cpp
int main(){
    //creating three different time objects
    m_time* time_one = new m_time();
    m_time* time_two = new m_time(4,29,31);
    m_time* time_three = new m_time(5, 34, 37);

    //displaying time for all those three object respectively using out stream operator
    std::cout << *time_one << std::endl;
    std::cout << *time_two << std::endl;
    std::cout << *time_three << std::endl;

   
    //adding two time objects; 'time_two' and 'time_three'
    m_time new_time = time_two->operator+(*time_three);
    //dispaying the new time, using out stream operator, after addition 
    std::cout << new_time << std::endl;
}