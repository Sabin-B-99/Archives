/*
    Author: Sabin Badal
    Date: 10/8/2020

    Description:
    Simple program that will ask user to enter a whole number and 
    calulate and display its factorial if possible.
*/
#include <iostream>
int factorial(int num);
int main(){
    try{
        int fact_of;
        std::cout << "Enter an positive for which the factorial is to be calculated" << std::endl;
        std::cin >> fact_of;
        int result = factorial(fact_of);
        std::cout << "The factorial of " << fact_of << " = " << result << std::endl;
    }catch(const std::string& err_msg){
        std::cerr << err_msg << std::endl;
    }catch(...){
        std::cerr << "Enter a positive whole number and try again" << std::endl;
    }   
}

/*
    Function that will calcluate the factorial of a given number.
    Whole number whose factorial is to be calculated is passed as the
    argument to this function. The function then will claulate the 
    factoral if the number is a positive whole number and return the
    result or else it will throw an expception. 
*/
int factorial(int num){
    if(num < 0){
        std::string neg_error = "Error: Cannot find factorial of a negative number";
        throw neg_error;
    }
    if(num == 0){
        return 1;
    }
    int val = 1;
    for (int i = 1; i <= num; i++)
    {
        val = val * i;
    }
    return val;
}