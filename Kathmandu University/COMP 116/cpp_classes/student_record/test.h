#ifndef _TEST.H
#define _TEST.H
#include <iostream>
#include <string>
#include "student.h"
#include <vector>
class test : public student{
protected:
    std::vector<std::pair<std::string, int>> res;
public:
    void get_each_marks();
}; 
#endif