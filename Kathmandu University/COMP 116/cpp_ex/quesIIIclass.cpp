#include <iostream>
/*
    Author: Sabin Badal
    Date: 10/06/2020
    
    Description:
    Example code showing the use of class templates.
    In this code below, we have created a template class
    named addition which takes type of any data types and sums them.
    The sum of data fields is achieved by use of member function
    named display_sum of the addition class. 
*/
template <class T> 
class addition{
    private:
    T num_I;
    T num_II;

    public:
    addition()
    :num_I(0), num_II(0)
    {
    }

    addition(T num_I, T num_II)
    :num_I(num_I), num_II(num_II)
    {      
    }

    void display_sum(){
        T sum = this->num_I + this->num_II;
        std::cout << "The sum of " << num_I << " and " << num_II << " is " << sum << std::endl;
    }
};

int main(){
    std::cout << "***************** Sum for integer types***************************" << std::endl;
    addition<int>* add_int = new addition<int>(4,5);
    add_int->display_sum();

    std::cout << "*****************Sum for double types***************************" << std::endl;
    addition<double>* add_dec = new addition<double> (1.1, 2.8);
    add_dec->display_sum();
}