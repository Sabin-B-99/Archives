//in m_time.hpp
#pragma once
#include <iostream>
/*
/*
    Author: Sabin Badal
    Date: 10/8/2020

    Description:
    Class that simulates a clock with time
    in hours, minutes and days but won't differentiate 
    wehther the time is A:M or P:M
*/
class m_time{
private:
    int hours;
    int minutes;
    int seconds;
public:
    m_time();
    m_time(const int& hours, const int& minutes, const int& seconds);
    m_time operator+(const m_time& to_add);
    friend std::ostream& operator << (std::ostream& out_stream, const m_time& time_obj);
private:
    void organize_time();
};