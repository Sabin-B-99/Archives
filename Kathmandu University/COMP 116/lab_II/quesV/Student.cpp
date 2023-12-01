//in Student.cpp
#include "Student.hpp"

Student::Student()
:academic_level(""), institution("")
{
}
Student::Student(const std::string& academic_level, const std::string& institution)
:academic_level(academic_level) , institution(institution)
{
}
void Student::display_info(){
    std::cout << "****Academic Info*****" <<std::endl;
    std::cout << "Curent Highest Academic Level: " << this->academic_level << std::endl;
    std::cout << "Current Institution: " << this->institution << std::endl;
}