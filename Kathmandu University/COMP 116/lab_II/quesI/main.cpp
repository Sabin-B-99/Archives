//In main.cpp
#include <iostream>
#include "HOD.hpp"
//compile with g++ HOD.cpp academic.cpp Employee.cpp administrative.cpp main.cpp

int main(){
  
    HOD* hod = new HOD("Ram KC", 45, 14, 70000, "KU_DoCSE", "Prof. Dr. ", 580, 42, 48);
    hod->add_course_taught();
    hod->add_depart_taught();
    hod->add_assigned_tasks();

    std::cout <<"**********ALL INFORMATION **************" << std::endl;
    hod->display_info();

}