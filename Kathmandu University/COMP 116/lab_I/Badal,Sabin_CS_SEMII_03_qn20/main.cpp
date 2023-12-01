//in main.cpp
//client program
#include <iostream>
#include "quad_eqn.hpp"

int main(){
    quad_eqn<int>* eqnI = new quad_eqn<int>();
    eqnI->get_coeff_input();
    eqnI->display_real_roots();
}
