#include <iostream>
#include <typeinfo>
class Student{
};

int main(){
    Student* s = new Student();
    std::string typeName = typeid(s).name();
    std::cout <<  typeName << std::endl;
}

