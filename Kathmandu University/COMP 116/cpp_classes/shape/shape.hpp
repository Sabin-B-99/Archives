//in shape.hpp
#pragma once
class shape{
    protected:
    double side_one;
    double side_two;

    public:
    shape();
    shape(double, double);
    ~shape();
    void set_data();
    //pure virtual function that will be overridden by shape's child classes
    void virtual display_area() =0;

    private:
    void get_input(double&);
};