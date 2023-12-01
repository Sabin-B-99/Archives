//in rectangle.hpp
#pragma once
#include "iostream"

/*
    class rectangle that simulate the real world
    rectangle and performs calculates its area and
    perimeter. 
*/
class rectangle{
private:
    int length;
    int breadth;
public:
    rectangle();
    rectangle(int length, int breadth);
    void  setSize(int length, int breadth);
    int getArea(); 
    int getPerimeter();
};