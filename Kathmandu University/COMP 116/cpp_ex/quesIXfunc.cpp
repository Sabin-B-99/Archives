#include <iostream>
/*
    Author: Sabin Badal
    Date: 10/06/2020
    
    Description:
    Example showcasing the use of template functions to achieve 
    generic programming in C++.

    In this program we have written a single template 
    function named swapVals which swaps two given values of
    any data type.
*/
template <class T> void swapVals(T &num1, T &num2);

int main(){
    double num1 = 3.4;
    double num2 = 4.2;
    std::cout << "Before:" << std::endl;
    std::cout << "num1 = " << num1 << " and num2 = " << num2 << std::endl;
    std::cout << "***************************************************" << std::endl;
    swapVals(num1,num2);
    std::cout << "After:" << std::endl;
    std::cout << "num1 = " << num1 << " and num2 = " << num2 << std::endl;
    std::cout << "***************************************************" << std::endl;
    return 0;
}

template <class T> void swapVals(T &num1, T &num2){
    T temp = num1;
    num1 = num2;
    num2 = temp;
}