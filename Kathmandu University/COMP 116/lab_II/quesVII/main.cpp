/*
    Author: Sabin Badal
    Date: 10/7/2020
    
    Description:
    Simple program that displays the result of 
    division between two numbers and throws an 
    exception when a number is divided by 0.
    This program shows the use of exception
    handling in C++
*/
#include <iostream>

template<typename T>
double divide(T numI, T numII);

/*
    driver program that gets two number as input from 
    the user and divides them and displays the result 
    ,if possible, to the console screen.
*/
int main(){
    double a;
    double b;
    double div;
    std::cout << "Enter First Number: " << std::endl;
    std::cin >> a;
    std::cout << "Enter Second Number: " << std::endl;
    std::cin >> b;
    try
    {
        div = divide<double>(a, b);
        std::cout << a  << " / " << b << " = " << div << std::endl;
    }
    catch(const std::string& err_msg)
    {
        std::cerr << err_msg << std::endl;
    }
}

/*
    Function that takes in two numbers of any primitive number types 
    as an arguments and divides them and returns the result. But if
    the divisor is zero the program throws an exception (error message)
    notifying the user about trying to divide with a zero value.
*/
template<typename T>
double divide(T numI, T numII){
    if(numII == 0){
        std::string err = "Math Error: Divided By Zero.";
        throw err;
    }
    return (numI / numII);
}