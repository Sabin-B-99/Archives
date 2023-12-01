#include <iostream>
class room{
    private:
        int length;
        int breadth;
    public:
        room(){ //default constructior
            this->length = 1;
            this->breadth = 1;
        
        }
        room(int length, int breadth)//parametrized construction
        :length(length), breadth(breadth) //parameter lists
        { 
        }

        int get_area(){
            return (length * breadth);
        }
};

int main(){
    room r1(3,4); //method of declaring object
    std::cout << "Area: " << r1.get_area() << std::endl; 
    //use dot operator to retrive objects data
}

