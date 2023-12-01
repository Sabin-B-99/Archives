#include <iostream>
/*
    Author: Sabin Badal
    Date: 10/06/2020
    
    Description:
    Example code showing implementation of generic programming in C++ 
    by using class templates.
    In this code below, we have created a template class
    named difference which takes type of any data types and substracts them.
    The substraction result of data fields is achieved by use of member function
    named display_difference of the difference class. 
*/
template <class T> 
class difference{
    private:
    T num_I;
    T num_II;

    public:
    difference()
    :num_I(0), num_II(0)
    {
    }

    difference(T num_I, T num_II)
    :num_I(num_I), num_II(num_II)
    {      
    }

    void display_difference(){
        T diff = this->num_I - this->num_II;
        std::cout << "The difference of " << num_I << " and " << num_II << " is " << diff << std::endl;
    }
};

int main(){
    std::cout << "***************** Difference for integer types***************************" << std::endl;
    difference<int>* add_int = new difference<int>(8,5);
    add_int->display_difference();

    std::cout << "*****************Difference for double types***************************" << std::endl;
    difference<double>* add_dec = new difference<double> (3.4, 4.8);
    add_dec->display_difference();
}