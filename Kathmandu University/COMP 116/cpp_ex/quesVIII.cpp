/*
    Author: Sabin Badal
    Date: 10/06/2020
    
    Description:
    Example showing use of virtual base class as well
    as virtual function.

    In this code example we encouter the diamond problem as
    sqrt_rect_combo class inherits from both square and rectangle
    class which in turn inheits from the abstract shape class.

    So, This causes ambugity as sqrt_rect_combo inheits two 
    instances of shape class. To remove this ambuguity we have 
    made the shape class as virtual base class by using the 
    virtual keyword when declaring the rectangle and square class.

    Also, we have overriden the pure virtual function display_area()
    as well as virtual function get_area whenever necessary.


*/
#include <iostream>
class shape{
    public:
    virtual void display_area() = 0;
};

class rectangle : public virtual shape{
    protected:
    int length;
    int breadth;

    public:
    rectangle(int length, int breadth)
    :length(length), breadth(breadth)
    {
    }

    virtual int get_area(){
        return length * breadth;
    }

    void display_area(){
        std::cout << "Area of Rectangle: " << get_area() << std::endl;
    }
};
//The oreder of keyword virtual and access modifer does not matter
class square : virtual public shape{
    private:
    int length;

    public:
    square(int length)
    :length(length)
    {
    }

    virtual int get_area(){
        return length * length;
    }

    void display_area(){
        std::cout << "Area of square: " << get_area() << std::endl;
    }
};
/*
    Class that inherits form both of square and rectangle class and
    displays area when a square and a rectangle is combined.
*/
class sqr_rect_combo : public square, public rectangle{
    public: 
    sqr_rect_combo(int length_sqr, int length_rect, int breadth_rect)
    :rectangle(length_rect, breadth_rect), square(length_sqr)
    { 
    }
    /*
        overriden the virtual function get_area form rectangle and
        square class.
    */
    int get_area(){
        return square::get_area() + rectangle::get_area();
    }
    /*
        overriden the pure virtual class form shape class
    */
    void display_area(){
        std::cout << "Area of combined shape of square and rectangle: " <<  get_area() <<std::endl;
    }
};

int main(){
    shape* complex_shape = new sqr_rect_combo(2, 5, 3);
    complex_shape->display_area();
}