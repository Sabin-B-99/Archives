#include <iostream>
/*
    Author: Sabin Badal
    Date: 10/06/2020
    
    Description:
    This example codes shows the applications of the 'this' pointer 
    as mentioned above in four points. 
*/
class person{
    private:
    std::string name;
    int age;

    public:
    person()
    :name(""), age(0)
    { 
    }

    /*
        1. Relsoving naming conflict while initalizing objects:
       
        So, as we can see tha arguments of person paramaterized constructor 
        and the memmber data fields of person class has same name.
        So, during initialization of this class's objects the 'this'
        pointer helps resolve naming conflicts by poiniting to the 
        correct data fields of the class
    */
    person(const std::string& name, int age){
        this->name = name;
        this->age = age;
    }

    ~person(){

    }

    /*
        2. accessing member functions and member fields:

        In function 'display_info' the 'this' pointer has been used
        to access the member fields name and age as well as private
        member function named 'say_hello'.
    */
    void display_info(){
        this->say_hello();
        std::cout << "My name is " << this->name << std::endl;
        std::cout << "and I am " << this->age << " years old."<< std::endl;
    }
    
    /*
        3. Returning current object:

        As we can see in the function 'had_birthday', which returns refrence to 
        the person object, we have used this pointer to return refrence of current 
        object after increasing his age by one, when he recently had a birthday.  
    */
    person& had_birthday(){
        (this->age)++;
        return *this;
    }

    /*
        4. override the current object:

        So, in function edit_info below we have used this pointer to override 
        the information of current object with new information as provided
        in function's arguments.
        Note: This is not a safe way to use pointers.

    */
   person& edit_info(const std::string& new_name, int new_age){
       //instead of using destructor we could have used 
       //delete this;
       //and program will still compile and run
       //but it is not safe
       this->~person();
       new (this) person(new_name, new_age);
       return *this;
   }

    private:
    void say_hello(){
        std::cout << "Hello! everyone." << std::endl;
    }
};

int main(){
    person* human = new person("John Doe", 50);
    human->display_info();
    std::cout << "********************" << std::endl;
    human->edit_info("Sabin Badal", 20);
    human->had_birthday();
    human->display_info();
}