#include <iostream>
 
class Perimeter{
    private:
        int length;
        int breadth;
    
    public: Perimeter(){
        this->length = 1;
        this->breadth = 1;
    }

    public: Perimeter(int length, int breadth){
        this->length = length;
        this->breadth = breadth;
    }

    public:double calculateArea(){
        return  (this->length * this->breadth);
    }

   

    public: double calculatePerim(){
        return  (2*(this->length + this->breadth));
    }

    public: int getLegth(){
        return this->length;
    }
    public : int getBreadth(){
        return this -> breadth;
    }

    public: void setSides(int length, int breadth){
        this->length = length;
        this->breadth = breadth;
    }
 };

 int main(void){
    Perimeter rect;
    Perimeter rectTwo(10,12);

    std:: cout << "Perimeter of first rectangle: " << rect.calculatePerim() << std::endl;
    std:: cout << "Perimeter of second rectangle: " << rectTwo.calculatePerim() << std::endl;
    std:: cout<<"********************************" << std::endl;
    std:: cout << "Area of first rectangle: " << rect.calculateArea() << std::endl;
    std:: cout << "Area of second rectangle: " << rectTwo.calculateArea() << std::endl;
 } 