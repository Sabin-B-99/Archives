//in main.cpp
#include <iostream>
#include "Manager.hpp"
//compile with g++ main.cpp Manager.cpp Student.cpp Employee.cpp Person.cpp
int main(){
    Person* pers = new Manager("Sabin Badal", 21, 4, 25000, "Undergraduate", "Kathmandu University", 3);
    pers->display_info();
}