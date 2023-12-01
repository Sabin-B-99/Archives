//in ComboDevice.hpp
/*
    Author: Sabin Badal
    Date: 10/8/2020
    
    Description:
    Class that simulates a device which is a combination of 
    a printer and a scanner and can either print a certain
    number copies or scan a certain number of copies at a given
    time.
    
    This calss inherits form two base class and these base
    classes are printer and scanner.
*/
#pragma once
#include <iostream>
#include "printer.hpp"
#include "scanner.hpp"

class ComboDevice : public printer, public scanner{
    public:
    ComboDevice(int print_copies, int scan_copies);
};