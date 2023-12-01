//in main.cpp
#include "m_time.hpp"
#include <iostream>
//client program
int main(){
    //creating three different time objects
    m_time* time_one = new m_time();
    m_time* time_two = new m_time(4,29,31);
    m_time* time_three = new m_time(5, 34, 37);

    //displaying time for all those three object respectively
    time_one->display_time();
    time_two->display_time();
    time_three->display_time();

    //adding two time objects 'time_two' and 'time_three'
    m_time new_time = time_two->operator+(*time_three);
    //dispaying the new time after addition
    new_time.display_time();
}