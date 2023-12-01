//in printer.hpp
/*
    Author: Sabin Badal
    Date: 10/8/2020
    
    Description:
    Class that simulates a printer through which a certain 
    number of peper copies can be printed at a given time.
    
    This number of copies which can be printed is represented by
    the member variable of this class and this class inherits the 
    base appliance class 
*/
#pragma once
#include "appliance.hpp"
#include <iostream>
class printer: virtual public appliance
{
protected:
    int copies_to_print;
public:
    printer();
    printer (int copies_to_print);
    void print();
};
