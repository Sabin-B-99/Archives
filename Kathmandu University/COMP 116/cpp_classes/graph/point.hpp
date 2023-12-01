//in point.hpp
#pragma once
#include <iostream>
#include <cmath>

/*
    class declaration for point class
    that holds two variables (x,y) that 
    will simulate a point in space
    and perform mathematical operations
    based on it
*/
class point{
private:    
    double x;
    double y;
public:
    point();
    point(const double& x, const double& y);
    void input_points();
    static double get_distance(const point& p1, const point& p2);
private:
    void force_num_input(double& x_or_y);
};