//in complex.hpp
#ifndef _COMPLEX_HPP
#define _COMPLEX_HPP
#include <iostream>
/*
    A class that simulates a complex number. The number (a + ib) will be
    stord in this class's x and y variables as where x = a and y = b.
    This class will allow its client programs to perform various mathematical
    operations realted with complex numbers.
*/
class complex
{
private:
    int x;
    int y;
public:
    complex();
    complex(int, int);

    void operator -(); //for unary minus operator

    complex operator *(const complex&) const;
    
    complex operator +(const complex&) const;
    complex operator -(const complex&) const;
    void operator += (const complex&);
    
    bool operator ==(const complex&);
    bool operator > (const complex&); 
    bool operator !=(const complex&); 

    complex operator ++ (); //for prefix
    complex operator ++ (int); //for postfix
    
    friend std::ostream& operator << (std::ostream&, const complex&);

};
#endif