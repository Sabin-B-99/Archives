//in main.cpp
#include "m_time.hpp"
#include <iostream>
//client program
int main(){
    //creating three different time objects
    m_time* time_one = new m_time();
    m_time* time_two = new m_time(4,29,31);
    m_time* time_three = new m_time(5, 34, 37);

    //displaying time for all those three object respectively using out stream operator
    std::cout << *time_one << std::endl;
    std::cout << *time_two << std::endl;
    std::cout << *time_three << std::endl;

    //using in stream operator to get values for default time type 'time_one'
    std::cin >> *time_one;
    //adding two time objects; new 'time_one' and 'time_three'
    m_time new_time = time_one->operator+(*time_three);
    //dispaying the new time, using out stream operator, after addition 
    std::cout << new_time << std::endl;
}