/*
    Author: Sabin Badal
    Date: 10/06/2020
    
    Description:
    Example code showing the use of function templates.
    In this code below, we have created a template function
    named add which takes type of any data types and sums them.
    And after addition it returns result.
*/

#include <iostream>
template <typename T>
T add(T numI, T numII);

int main(){
    std::cout << "***************** Sum for integer types***************************" << std::endl;
    int int_num_a = 3;
    int int_num_b = 5;
    
    int sum = add<int>(int_num_a, int_num_b);
    std::cout << "Sum of " << int_num_a << " and " << int_num_b << " is: " << sum << std::endl;

    std::cout << "*****************Sum for double types***************************" << std::endl;
    double dec_num_a = 3.4;
    double dec_num_b = 4.8;

    double dec_sum = add<double>(dec_num_a, dec_num_b);

    std::cout << "Sum of " << dec_num_a << " and " << dec_num_b << " is: " << dec_sum << std::endl;
}

/*
    Template function that adds any given types and reuturns their sum.
*/
template <typename T>
T add(T numI, T numII){
    return numI + numII;
}

