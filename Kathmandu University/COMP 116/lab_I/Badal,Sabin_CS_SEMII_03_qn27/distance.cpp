//in distance.cpp
#include "distance.hpp"
/*
    empty constructor for the distance class that 
    sets the value of all of its member functions to
    zero.
*/
distance::distance()
:meters(0), centims(0)
{
}

/*
    parameterized constructor that will also change the value 
    of centimeters that is greater or equals to 100 into meters 
    when necessary by calling the add_cm_to_m fucntion.
    For Example: if there is 1 meters and 112 centimeters than this
    constructor will call the add_cm_to_m method which will then convert 
    that 1 meters and 112 centimeters into 2 meters and 12 centimeters
*/
distance::distance(const int& meters, const float& centims)
:meters(meters), centims(centims)
{
    add_cm_to_m();
}

//opverloaded shorthand plus operator that adds two distance types 
void distance::operator+=(const distance& to_add){
    this->meters += to_add.meters;
    this->centims += to_add.centims;
    add_cm_to_m();
}

/*
    method that will change the value 
    of centimeters that is greater or equals to 100 into meters 
    For Ex: If there is 1 meters and 112 centimeters than this
    add_cm_to_m method will convert 
    that 1 meters and 112 centimeters into 2 meters and 12 centimeters
*/
void distance::add_cm_to_m(){
    if(this->centims >= 100){
        this->meters += (this->centims / 100);
        this->centims = std::fmod(this->centims, 100); //modulo operation for doubles and floats
    }
}

/*
    Method that will prompt user to enter the magnitude of 
    their distances in meters and centimeters respectively.
*/
void distance::get_Dist(){
    std::cout << "Enter the distance in meters: " << std::endl;
    get_num_input<int>(this->meters);
    std::cout << "Enter the distance in centimeters: " << std::endl;
    get_num_input<float>(this->centims);
}

/*
    Function that will get the input from the terminal.
    This function will force the user to enter an int or 
    double value. Doing this will ensure type saftey as well 
    as prevent the whole program from crashing if the user 
    inputs a char or string variable instead of int or double 
    variable type 
*/
template<typename T>
void distance::get_num_input(T& num){
    while(!(std::cin >> num)){
        std::cin.clear(); //clear previous input
        std::cin.ignore(123, '\n'); //flushes the new line character remaining in the input buffer
        std::cout << "You need to enter a number." << std::endl;
    }
}

/*
    Method that will display the distances to the terminal
*/
void distance::show_Dist(){
    std::cout << "****************************" << std::endl;
    std::cout << "The distance is: " << this->meters << " meters and " << this->centims << " centimeters." << std::endl;   
}
