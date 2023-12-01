/* #include <iostream>
template <class T> void swapValsPassByRef(T& num1, T& num2);
template <class T> void swapValsPassByValue(T num1, T num2);

int main(){
    double num1 = 3;
    double num2 = 4;
    std::cout << "Before pass by value:" << std::endl;
    std::cout << "num1 = " << num1 << " and num2 = " << num2 << std::endl;
    std::cout << "***************************************************" << std::endl;
    swapValsPassByValue(num1,num2);
    std::cout << "After pass by value:" << std::endl;
    std::cout << "num1 = " << num1 << " and num2 = " << num2 << std::endl;
    std::cout << "***************************************************" << std::endl;

    std::cout << "Before pass by refrence:" << std::endl;
    std::cout << "num1 = " << num1 << " and num2 = " << num2 << std::endl;
    std::cout << "***************************************************" << std::endl;
    swapValsPassByRef(num1,num2);
    std::cout << "After pass by refrence:" << std::endl;
    std::cout << "num1 = " << num1 << " and num2 = " << num2 << std::endl;
    std::cout << "***************************************************" << std::endl;
    return 0;
}

template <class T> void swapValsPassByRef(T& num1, T& num2){
    T temp = num1;
    num1 = num2;
    num2 = temp;
}

template <class T> void swapValsPassByValue(T num1, T num2){
    T temp = num1;
    num1 = num2;
    num2 = temp;
}
 */
/* 
#include <iostream>
inline int add(int valA, int valB){
    return valA + valB;
};
int main(){
    int a = 1;
    int b = 3;
    std::cout << add(a,b) << std::endl;
} */

/* #include <iostream>

class student{
private:
    static int student_no;
    std::string name;
public:
    student(){
        this->name = " ";
        student_no++;
    }

    student(const std::string& name){
        this->name = name;
        student_no++;
    }

    //static member function
    static int get_total_student(){
        return student_no;
    }
};
//initalzing static member variable to zero
int student::student_no = 0;


int main(){
    student* s1 = new student();
    student s2("Sabin Badal");
    std::cout << "Total Number of students: " << student::get_total_student() << std::endl;
} */

/* #include <iostream>
class student{
private:
    std::string name;
    int reg_no;
public:
    student(){
        this->name = " ";
        this->reg_no = 0;
    }

    student(const std::string& name, const int& reg_no){
        this->name = name;
        this->reg_no = reg_no;
    }

    //user defined copy constructor
    student(const student& obj_to_copy){
        this->name = obj_to_copy.name;
        this->reg_no = obj_to_copy.reg_no + 1;
    }

    void get_info(){
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "Reg No: " << this->reg_no << std::endl;
    }
};

int main(){
    student* s1 = new student("Sabin Badal", 1);
    //user define copy constructor invoked
    student* s2 = new student(*s1);
    s2->get_info();
} */
/* 
#include <iostream>
//function declarations
void print_hello();
void print_hello(const std::string&);
int main(){
    print_hello();
    print_hello("Sabin");
}

//function definitions
void print_hello(){
    std::cout << "Hello World!" << std::endl;
}

void print_hello(const std::string& name){
    std::cout << "Hello " << name << ". You have a beautiful name." << std::endl;
} */

#include <iostream>
class hello{
public:
    void print_hello();
};
void hello::print_hello(){
    std::cout << "Hello World!" << std::endl;
}

int main(){
    hello* h = new hello();
    h->print_hello();
}