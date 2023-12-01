#ifndef _STUDENT_H
#define _STUDENT_H
#include <iostream>
#include <string>
class student{
private:
    std::string full_name;
    int reg_no;
public:
    std::string  get_name();
    int get_reg_no();
};
#endif