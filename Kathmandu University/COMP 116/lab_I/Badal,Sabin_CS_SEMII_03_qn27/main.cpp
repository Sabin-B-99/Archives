//in main.cpp
#include <iostream>
#include "distance.hpp"
//client program
int main(){

    //created default object
    distance* d1 = new distance();
    //created object with distance values as 143 meters and 2323 centimeters
    distance* d2 = new distance(143, 2323);
    
    //dispalaying dimesnions of both distnaces 
    d1->show_Dist();
    d2->show_Dist();
    
    //promptiog user to enter new values for default object d1
    d1->get_Dist();
    
    //adding object d2 with new d1
    d2->operator+=(*d1);
    //displaying the new dimensions of d2 after addition with d1
    d2->show_Dist();
}