#include <iostream>
/*
    Author: Sabin Badal
    Date: 10/06/2020
    
    Description:
    class shape is an abstract class which has a pure 
    virtual function named display_perimeter and a 
    virtual function display_area.
*/
class shape{
    protected:
    double length;
    double breadth;

    public:
    shape()
    :length(0), breadth(0)
    {    
    }

    shape(double length, double breadth)
    :length(length), breadth(breadth)
    {
    }
    /*
        Since the class has atleat one pure virtual function named
        display_perimeter it is an abstract class.
        So, any classes inheriting from this shape class must 
        implement/override this display_perimeter function.
        Otherwise the class inheriting this class will also be 
        an abstract class.
        We can make a function purely vitual by using the keyword =0 
        as shown below.
    */
    virtual void display_perimeter() =0;

    /*
        Here we have just a virtual function name, display_area(). It is 
        not a compulsion for a child class of this shape class to override
        this display_area() function.
    */
    virtual void display_area(){
        std::cout << "The area of a generic shape is " << 0 << " sq. units" << std::endl;
    }
};

/*
    class rectangle is a child class of the abstract class shape. 
    So, it must override all of the pure virtual function of the
    shape class. So, we have overriden the pure virtual function 
    named display_perimeter of the shape class. While it is not a 
    compulsion for the rectangle class to override the virtual function
    named display_area of shape class, we have overrden that too.
*/
class rectangle: public shape{
    public:
    rectangle()
    { 
    }
    rectangle(double length, double breadth)
    :shape(length, breadth)
    {
    }

    void display_perimeter(){
        std::cout << "The perimeter is " <<  2 * (length + breadth) << " units." << std::endl;
    }
    void display_area(){
        std::cout << "The area is " << length * breadth << " sq. units" << std::endl;
    }
};

int main(){
    shape* rect = new rectangle(4,5);
    rect->display_perimeter();   
    rect->display_area();
}