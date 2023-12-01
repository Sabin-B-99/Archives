//in main.cpp
#include <iostream>
#include "ComboDevice.hpp"
#include "printer.hpp"
#include "scanner.hpp"
#include "appliance.hpp"
//compile with g++ main.cpp scanner.cpp printer.cpp appliance.cpp ComboDevice.cpp
/*
    Driver program that simulates printing of three papers and 
    scanning of two papers.
*/
int main(){
    ComboDevice* cannon = new ComboDevice(3,2);
    cannon->on();
    cannon->print();
    cannon->scan();
    cannon->off();
}