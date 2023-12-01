//in scanner.hpp
/*
    Author: Sabin Badal
    Date: 10/8/2020
    
    Description:
    Class that simulates a scanner through which a certain 
    number of peper copies can be scanned at a given time.
    
    This number of copies which can be scanned is represented by
    the member variable of this class and this class inherits the 
    base appliance class 
*/
#pragma once
#include "appliance.hpp"
#include <iostream>
class scanner: virtual public appliance
{
protected:
    int copies_to_scan;
public:
    scanner();
    scanner (int copies_to_scan);
    void scan();
};
