//In HOD.cpp
#include "HOD.hpp"
HOD::HOD()
:no_students_in_dept(0), no_of_course(0), no_of_staffs(0)
{ 
}

HOD::HOD(const std::string& name, int age, int years_worked, int base_salary,
        const std::string& dep_name,
        const std::string& designation,
        int students, int course, int staffs)
        
:Employee(name, age, years_worked, base_salary), administrative(dep_name), 
academic(designation), 
no_students_in_dept(students), no_of_course(course), no_of_staffs(staffs) 
{
}

void HOD::display_info(){
    Employee::display_info();
    std::cout << "*******************************" << std::endl;
    administrative::display_info();
    std::cout << "*******************************" << std::endl;
    academic::display_info();
    std::cout << "********************************" << std::endl;
    std::cout << department_name << " has a total of " << no_students_in_dept << " studnets." << std::endl;
    std::cout << department_name << " has a total of " << no_of_staffs << " staffs." << std::endl;
    std::cout << department_name << " teaches total of "  << no_of_course << " courses." << std::endl;   
}
