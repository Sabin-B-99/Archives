//in m_time.hpp
#pragma once
#include <iostream>
/*
    class that simulates a clock with time
    in hours, minutes and days but wont differentiate 
    wether the time is A:M or P:M
*/
class m_time{
private:
    int hours;
    int minutes;
    int seconds;
public:
    m_time();
    m_time(const int& hours, const int& minutes, const int& seconds);
    void display_time();
    m_time operator+(const m_time& to_add);
private:
    void organize_time();
};