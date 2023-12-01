//in distance.hpp
#pragma once
#include <iostream>
#include <cmath>
/*
    class that will simulate a length of any distance 
    in meters and centimeters and perform different 
    operations related to them
*/
class distance{
private:
    int meters;
    float centims;
public:
    distance();
    distance(const int& meters, const float& centims);
    void operator +=(const distance& to_add);
    void get_Dist();
    void show_Dist();

private:
    void add_cm_to_m();
    template<typename T>
    void get_num_input(T& num);
};