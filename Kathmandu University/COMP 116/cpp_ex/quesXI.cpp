#include <iostream>

/*
    Author: Sabin Badal
    Date: 10/06/2020
    
    Description:
    Here we have overloaded function named display_sum by using 
    same name but differet signatures
*/
void display_sum(int a, int b);
void display_sum(double a, double b);

/*
    Here, we have overloaded a template name display_difference 
    by using same name but different signatures
*/
template<typename T>
void display_difference(T a, T b);

/*
    overloaded template
*/
template<typename T, typename U>
void display_difference(T a, U b);

void display_difference(int a, int b);


int main(){
    display_sum(5, 3);
    display_sum(3.3, 4.8);
    display_difference<double>(4.8, 3.3);
    display_difference<int, double>(5, 2.1);
    display_difference(4,6);
}

void display_sum(int a, int b){
    std::cout << "The sum of " << a << " and " << b << " is " << a+b << std::endl;
    std::cout << "**********************************************" << std::endl;
}

void display_sum(double a, double b){
    std::cout << "The sum of " << a << " and " << b << " is " << a + b << std::endl;
    std::cout << "**********************************************" << std::endl;
}

template<typename T>
void display_difference(T a, T b){
    std::cout << "The difference of " << a << " and " << b << " is " << a - b << std::endl;
    std::cout << "**********************************************" << std::endl;
}

template<typename T, typename U>
void display_difference(T a, U b){
    std::cout << "The difference of " << a << " and " << b << " is " << a - b << std::endl;
    std::cout << "**********************************************" << std::endl;
}


void display_difference(int a, int b){
    std::cout << "The difference of given integers " << a << " and " << b << " is " << a - b << std::endl;
    std::cout << "**********************************************" << std::endl;
}