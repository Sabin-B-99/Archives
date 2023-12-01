//in quad_eqn.cpp
#include "quad_eqn.hpp"
/*  
    default constructor for class quad_eqn
    which initializes the calue for all coefficients
    a,b and c to zero
*/
template<class T> 
quad_eqn<T>::quad_eqn()
   :coff_a(0), coff_b(0), coff_c(0)
{
}

//parameterized constructor
template<class T> 
quad_eqn<T>::quad_eqn(const T& coff_a, const T& coff_b, const T& coff_c)
   :coff_a(coff_a), coff_b(coff_b), coff_c(coff_c)
{  
}
/*
    function to check wether the roots of the given quadratic
    equation is real or not i.e, wether its discriminant >= 0.
    If the roots are real then the function will return true
    else it will return false
*/
template <class T>
bool quad_eqn<T>::are_roots_real(){
    if((pow(this->coff_b, 2) - 4 * this->coff_a * this->coff_c) >= 0){
        return true;
    }
    return false;
}

/*
    function to get all the coefficeints(a,b,c) of a quadratic
    equation, ax^2 + bx + c = 0. Also, the members variables of 
    this class will be set as the user inputs in this function
*/
template <class T>
void quad_eqn<T>::get_coeff_input(){
    std::cout << "Enter the coofficients(a,b,c) of the quadratic equation." << std::endl;
    std::cout << "It should be in for ax^2 + bx + c = 0" << std::endl;
    std::cout << "Coefficient a?: " << std::endl;
    std::cin >> this->coff_a;
    std::cout << "Coefficient b?: " << std::endl;
    std::cin >> this->coff_b;
    std::cout << "Coefficient c?: " << std::endl;
    std::cin >> this->coff_c;
}

/*
    function that returns the discriminant of the quadratic equation.
    The return type will be according to the type provided in 
    the client application while constructing an object of this class.
    The function will return disriminant if solutions are real
    else will teminate the program with error message: 'No real solutions'
*/
template <class T>
auto quad_eqn<T>::get_discriminant(){
    if(!are_roots_real()){
        std::cout << "Error: No Real Solutions." << std::endl;
        exit(0);
        
    }
    return (pow(this->coff_b, 2) - 4 * this->coff_a * this->coff_c);
}

/*
    function that returns the first root of the quadratic equation.
    The return type will be according to the type provided in 
    the client application while constructing an object of this class.
    The function will return first root if solutions are real
    else will teminate the program with error message: 'No real solutions'
*/
template <class T>
auto quad_eqn<T>::get_root_x1(){
    if(!are_roots_real()){
        std::cout << "Error: No Real Solutions." << std::endl;
        exit(0);
        
    }
    return ((-this->coff_b + sqrt(get_discriminant())) / (2 * this->coff_a));
}
/*
    function that returns the second of the quadratic equation.
    The return type will be according to the type provided in 
    the client application while constructing an object of this class.
    The function will return second if solutions are real
    else will teminate the program with error message: 'No real solutions'
*/
template <class T>
auto quad_eqn<T>::get_root_x2(){
    if(!are_roots_real()){
        std::cout << "Error: No Real Solutions." << std::endl;
        exit(0);    
    }
    return ((-this->coff_b - sqrt(get_discriminant())) / (2 * this->coff_a));
}
/*
    functions that will display the roots for the quadratic equation.,
    if they are real
*/
template <class T>
void quad_eqn<T>::display_real_roots(){
    std::cout << "****Real Solutions****" << std::endl;
    if(!are_roots_real()){
        std::cout << "Error: No Real Solutions." << std::endl;
        exit(0);
    }
    if(get_discriminant() == 0){
        std::cout << "Root = " << get_root_x1() << std::endl;    
    }else{
        std::cout << "X1 = " << get_root_x1() << std::endl;
        std::cout << "X2 = " << get_root_x2() << std::endl;
    }
}

//these lines below are to avoid linkage errors as we have a template class
template class quad_eqn<int>;
template class quad_eqn<double>; 

