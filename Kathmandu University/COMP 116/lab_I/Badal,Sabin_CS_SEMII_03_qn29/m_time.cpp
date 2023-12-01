//in m_time.cpp
#include "m_time.hpp"
/*
    default constructor that will instantinate the m_time
    object with all member varibles as 0
*/
m_time::m_time()
:hours(0), minutes(0), seconds(0)
{
}

/*
    parameterized constructor that will instantinate the object with 
    desired values and further call the organnize_time method that will
    organize the time as in real clock. For Example:
    If user enters the values of time as 4 hours 63 minutes and 64 seconds
    the the clock object will be organized as 5 hours 4 minutes and 4 seconds.
*/
m_time::m_time(const int& hours, const int& minutes, const int& seconds)
:hours(hours), minutes(minutes), seconds(seconds)
{
    organize_time();
}

/*  
    A method that will
    organize the time as in real clock. For Example:
    If user enters the values of time as 4 hours 63 minutes and 64 seconds
    the the clock object will be organized as 5 hours 4 minutes and 4 seconds.
*/
void m_time::organize_time(){
    if(this->seconds >= 60){
        this->minutes += (this->seconds / 60);
        this->seconds %= 60;
    }
    if(this->minutes >= 60){
        this->hours += (this->minutes / 60);
        this->minutes %= 60;
    }
    if(this->hours > 12){
        this->hours = 1;
    }
}

/*
    Overloaded operator that will add two time types
    and organized them as real clock times
*/
m_time m_time::operator+(const m_time& to_add){
    m_time result;
    result.hours = this->hours + to_add.hours;
    result.minutes = this->minutes + to_add.minutes;
    result.seconds = this->seconds + to_add.seconds;
    result.organize_time();
    return result;
}

/*
    Overloaded out stream operator that will display time 
    for a given time type to the termina
*/
std::ostream& operator << (std::ostream& out_stream, const m_time& time_obj){
    out_stream <<  time_obj.hours << ":" << time_obj.minutes << ":" << time_obj.seconds; 
    return out_stream;
}

/*
    Overloaded in stream operator that will take in 
    values for member vaiables of of given time types
*/
std::istream& operator >> (std::istream& in_stream, m_time& time_obj){
    std::cout << "Enter hours: " << std::endl;
    in_stream >> time_obj.hours;
    std::cout << "Enter minutes: " << std::endl;
    in_stream >> time_obj.minutes;
    std::cout << "Enter seconds: " << std::endl;
    in_stream >> time_obj.seconds;
    return in_stream; 
}


