#ifndef _FACTORIAL_H
#define _FACTORIAL_H
#include <iostream>
class factorial{
    private:
        int num_to_factor;
    public:
        factorial();
        factorial(int);
        factorial(factorial &obj2);
        int calculate_factorial();
};
#endif