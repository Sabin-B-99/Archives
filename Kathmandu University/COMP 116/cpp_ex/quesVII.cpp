/* 
/*
    First case:
    Where both class B and class D does not have any data 
    fields
**?
#include <iostream>
class B{

};

class D : public B{

};

int main(){
    D obj;
    //program will compile and run without errors.
} 
*/

/* #include <iostream>
class B{
    protected:
    int val;
    
    public:
    B()
    :val(0)
    { 
    }

    void display_val(){
        std::cout << "Val: " << val << std::endl;
    }        
};
class D : public B{
    //class D does not require constructor in this case
};
int main(){
    B* obj = new D();
    obj->display_val();
} */

#include <iostream>
//second case
class B{
    protected:
    int val;
    
    public:
    B(int val)
    :val(val)
    {  
    }

    void display_val(){
        std::cout << "Val: " << val << std::endl;
    }        
};
class D : public B{
    public:
    //D requires a constructor because B does not have a default constructor
    D(int val)
    :B(val)
    {
    }
};
int main(){
    B* obj = new D(5);
    obj->display_val();
}