//in complex.hpp
#include "complex.hpp"
/*
    default constructor that will initalize all its
    member variables to 1, which means that the default 
    complex number will be (1 + i)
*/
complex::complex(){
    this->x = 1;
    this->y = 1;
}

//parameterized constructor. To set the complex number to (x + yi) 
complex::complex(int x, int y){
    this->x = x;
    this->y = y;
}
/*
    Function that overloads the default unary minus operator
    to make it suitable to perform operations on complex types
    Will return void
*/
void complex::operator-(){
    this->x = -this->x;
    this->y = -this->y;
}

/*
    Function that overloads the default multiplication operator
    to make it suitable to perform scalar multiplication on complex types
    Will return a complex type
*/
complex complex::operator * (const complex& second_val) const{
    complex result;
    result.x = (this->x * second_val.x) + (-1 * (this->y * second_val.y));
    result.y = (this->x * second_val.y) + (this->y * second_val.x);
    return result; 
}

/*
    Function that overloads the default binary addition operator
    to make it suitable to addition between two complex types
    Will return a complex type
*/
complex complex:: operator +(const complex& second_val) const{
    complex result;
    result.x = this->x + second_val.x;
    result.y = this->y + second_val.y;
    return result;
}

/*
    Function that overloads the default binary substractiom operator
    to make it suitable to substraction between two complex types.
    Will return a complex type
*/
complex complex:: operator -(const complex& second_val) const{
    complex result;
    result.x = this->x - second_val.x;
    result.y = this->y - second_val.y;
    return result;
}

/*
    Function that overloads the default shorthand addition operator
    to make it suitable to perform operations on complex types.
    Will return void.
*/
void complex::operator += (const complex& number){
    this->x += number.x;
    this->y += number.y;
}
/*
    Function that overloads the default equals operator
    to make it suitable to check wether given complex types 
    are equal or not
    Will return true if they are equal, otherwise will return false.
*/
bool complex::operator == (const complex& number){
    return (this->x == number.x) && (this->y == number.y);
}

/*
    Function that overloads the default greater than operator
    to make it suitable to check wether given complex type 
    is grater than other complex type not
    Will return true if it is greater, otherwise will return false.
*/
bool complex::operator > (const complex& number){
    return ((this->x > number.x) || (this->x == number.y && this->y > number.y));
}

/*
    Function that overloads the default equals operator
    to make it suitable to check wether given complex types 
    are equal or not
    Will return true if they are not equal, otherwise will return false.
*/
bool complex::operator != (const complex& number){
    return (this->x != number.x) && (this->y != number.y);
}

/*
    Function that overloads the default prefix operator
    to make it suitable to perform operations on complex types
    Will return complex types
*/
complex complex::operator ++ (){
    this->x = ++this->x;
    this->y = ++this->y;
    return *this;
}


/*
    Function that overloads the default postfix operator
    to make it suitable to perform operations on complex types
    Will return complex types
*/
complex complex::operator ++ (int place_holder){
    this->x = (this->x)++;
    this->y = (this->y)++;
    return *this;
}

/*
    Function that overloads the default stream insertion operator
    to make it suitable to print a complex number in form of 
    (a + ib) into the terminal
*/
std::ostream& operator << (std::ostream& stream, const complex& number){
    stream << number.x  << ( (number.y >= 0) ? " + " : " " ) << number.y << "i"; 
    return stream;
}

