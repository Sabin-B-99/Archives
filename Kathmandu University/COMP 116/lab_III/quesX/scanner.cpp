//in scanner.cpp
#include "scanner.hpp"
scanner::scanner()
:copies_to_scan(0)
{
}

scanner::scanner(int copies_to_scan)
:copies_to_scan(copies_to_scan)
{
}


/*
    Function that simulates scanning of a paper by dislpaying
    the workd "Scanning" on the screen as many time as the 
    value of copies_to_scan data field of this class.
*/
void scanner::scan(){
    for (int i = 0; i < copies_to_scan; i++)
    {
        std:: cout << "Scanning " ;
    }
    std::cout << std::endl;
}