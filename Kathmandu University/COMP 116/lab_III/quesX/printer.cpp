//in printer.cpp
#include "printer.hpp"
printer::printer()
:copies_to_print(0)
{
}

printer::printer(int copies_to_print)
:copies_to_print(copies_to_print)
{
}

/*
    Function that simulates printing of a paper by dislpaying
    the workd "Printing" on the screen as many time as the 
    value of copies_to_print data field of this class.
*/
void printer::print(){
    for (int i = 0; i < copies_to_print; i++)
    {
        std:: cout << "Printing ";
    }
    std::cout << std::endl;
}