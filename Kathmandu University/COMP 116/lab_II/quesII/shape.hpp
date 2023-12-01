//in shape.hpp
//In academic.hpp
/*
    Author: Sabin Badal
    Date: 10/7/2020
    
    Description:
    Class that can be extended by its child class and this class 
    represents a generic shape whose area can be figured out.

*/
#pragma once
class shape{
    public:
   //pure virtual function that will be overridden by shape's child classes
    void virtual display_area() =0;
    void virtual set_data() =0;
    
    void get_input(double& side_input);
};