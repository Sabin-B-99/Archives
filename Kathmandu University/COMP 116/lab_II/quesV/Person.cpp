//in Person.cpp
#include "Person.hpp"

Person::Person()
:name(""), age(0)
{
}

Person::Person(const std::string& name, int age)
:name(name), age(age)
{
}

void Person::display_info(){
    std::cout << "****Personal Info*****" <<std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
}