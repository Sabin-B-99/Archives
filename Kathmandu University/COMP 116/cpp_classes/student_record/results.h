#ifndef _RESULTS.H
#define _RESULTS.H
#include <iostream>
#include <string>
#include "test.h"
class results : public test{
    private:
        int result_year;
    
    public:
        void display_percentage();
};
#endif