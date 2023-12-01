#include <iostream>

/*
    Author: Sabin Badal
    Date: 10/06/2020
    
    Description:
    Example that tries to show an example of composition and inheritance

    Here, we have shown the concpet of inheritance by inheriting the abstract class
    shape into rectangle class and square class.

    Here, we have three classes rectangle, square and complex_shape
    class. The recatngle and square class is used as a data member of 
    complex_shape class. This is a concept of composition 
*/
class shape{
    public:
    virtual int get_area() =0;
};

/* 
    rectangle class inherits shape class.
    This displays the concpet of inheritance
*/
class rectangle : public shape{
    private:
    int length;
    int breadth;

    public:
    rectangle(int length, int breadth)
    :length(length), breadth(breadth)
    {
    }
    int get_area(){
        return length * breadth;
    }
};

class square : public shape{
    private:
    int length;

    public:
    square(int length)
    :length(length)
    {
    }
    int get_area(){
        return length * length;
    }
};

class complex_shape{
    /*
        concept of composition
        here, rectangle class and square class are 
        data fields of complex_shape class
    */
    private:
    rectangle rect;
    square sqr;

    public:
    complex_shape(const rectangle& rect, const square& sqr)
    :rect(rect), sqr(sqr)
    {
    }

    void display_area(){
        std::cout << "The area of complex_shape which is a combination of rectangle and square is " << rect.get_area() + sqr.get_area() << std::endl;
    }
};

int main(){
    rectangle* rect = new rectangle(5,4);
    square* sqr = new square(2);
    complex_shape* combo = new complex_shape(*rect, *sqr);
    combo->display_area();
}