//in quad_eqn.hpp
#pragma once
#include <iostream>
#include <cmath>
/*
    template class that holds coefficent of 
    quadratic equation and perform their real operations
    and not the complex ones.
    choose a template class for type saftey as doing this
    client program now can enter both double and int types
*/
template<class T>
class quad_eqn{
    private:
    T coff_a;
    T coff_b;
    T coff_c;

    public:
    quad_eqn();
    quad_eqn(const T& coff_a, const T& coff_b, const T& coff_c);
    bool are_roots_real();
    void get_coeff_input();
    auto get_discriminant();
    auto get_root_x1();
    auto get_root_x2();
    void display_real_roots();
};