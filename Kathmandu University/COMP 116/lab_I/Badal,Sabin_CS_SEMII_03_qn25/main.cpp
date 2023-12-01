//in main.cpp
#include "complex.hpp"
//didn't include <iostream> purposefully as it has alread been included in complex.hpp
/*
    client program that will perform different mathematical opeartions
    on a complex type based on the overloaded operators present in the complex class 
*/

int main(){
    complex val_one(3, -2);
    complex val_two;
    complex val_three(1,7);

    complex val_four(2,2);
    complex val_five(2,2);

    std::cout << "********************************************************" << std::endl;
    std::cout << "Unary Substraction result for " << val_one << " = ";
    val_one.operator-();
    std::cout << val_one << std::endl;
    std::cout << "********************************************************" << std::endl;
    
    complex multiResult = val_one.operator*(val_three);
    std::cout << "Multiplication result  between " << val_one << " and " << val_three << " = " << multiResult << std::endl;
    std::cout << "********************************************************" << std::endl;

    complex addResult = val_one.operator+(val_two);
    std::cout << "Addition result between " << val_one << " and " << val_two << " = " << addResult << std::endl;
    std::cout << "********************************************************" << std::endl;

    complex subsResult = val_one.operator-(val_two);
    std::cout << "Subtraction result between " << val_one << " and " << val_two << " = " << subsResult << std::endl;
    std::cout << "********************************************************" << std::endl;

    std::cout << "Shorthand addition result for " << val_three << " and " << val_two << " = ";
    val_three.operator+=(val_two);
    std::cout << val_three << std::endl;
    std::cout << "********************************************************" << std::endl;

    std::cout << "Pre-Increment result for " << val_two << " = ";
    complex preRes = val_two++;
    std::cout << preRes << std::endl;
    std::cout << "********************************************************" << std::endl;

    std::cout << "Post-Increment result for " << val_three << " = ";
    complex postRes = val_three++;
    std::cout << postRes << std::endl;
    std::cout << "********************************************************" << std::endl;

    if(val_four == val_five){
        std::cout << val_four << " is equal to " << val_five << std::endl;
    }
    std::cout << "********************************************************" << std::endl;

    if(val_three > val_one){
        std::cout << val_three << " is greater than  " << val_one << std::endl;
    }
    std::cout << "********************************************************" << std::endl;



    if(val_one != val_three){
        std::cout << val_one << " is not equal to " << val_three << std::endl;
    }
    std::cout << "********************************************************" << std::endl;

    if(val_four == val_two){
        std::cout << val_four << " is equal to " << val_two << std::endl;
    }else{
        std::cout << val_four << " is not equal to " << val_two << std::endl;
    }
    std::cout << "********************************************************" << std::endl;
}