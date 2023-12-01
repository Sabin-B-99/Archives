#include <iostream>
/*
    Author: Sabin Badal
    Date: 10/06/2020
    
    Description:
    Example that tries to show how compile time 
    polymorphism and runtime polymorphism is achieved in
    cpp.
    
    In this example code the function 'display_info'
    present in phone class has been overridden in
    its child class, smmart_phone. So, when the main
    function class the overriden functions, it is an
    exapmle of a runtime polymorphism

    Similarly, the function 'click_photo' present in 
    smart_phone class has been overloaded inside of that 
    same class by using same function name but different 
    number of arguments. This function overloading is an
    example of compile time polymorphism 
*/
class phone{
    protected:
    std::string brand;
    std::string model;

    public:
    phone()
    : brand(""), model("")
    {    
    }

    phone(const std::string& brand, const std::string& model)
    :brand(brand), model(model)
    {  
    }
    
    /*  
        This function has been overriden in child class
        We have used virtual keyword in front of the function
        signatures so that it can be overriden in its child classes.

        With the help of vtables and function pointers the compiler 
        will select the correct function to call at runtime. 
    */
    virtual  void display_info(){
        std::cout << "About Phone:" << std::endl;
        std::cout << brand << " " << model << std::endl;
    }
};

class smart_phone: public phone{
    private:
    std::string os;
    int ram_in_gb;
    int storage_in_gb;

    public:
    smart_phone()
    :os(""), ram_in_gb(0), storage_in_gb(0)
    {
    }

    smart_phone(const std::string& brand, const std::string& model, const std::string os, int ram_in_gb, int storage_in_gb)
    :os(os), ram_in_gb(ram_in_gb), storage_in_gb(storage_in_gb), phone(brand, model)
    {
    }

    /*
        This function 'display_info' has been overriden form its parent class
        Note: As we can see while overriding we haven't changed the no of 
        arguments as well as return type of this function and is same as 
        that of its parent class 'display_info' function.
    */
    void display_info(){
        std::cout << "About Phone:" << std::endl;
        std::cout << brand << " " << model << std::endl;
        std::cout << os << std:: endl;
        std::cout << "Ram: " << ram_in_gb << " GB" << std::endl;
        std::cout << "Storage: " << storage_in_gb << " GB" << std::endl;
    }

    /*
        click_photo function has been overloaded with in this class.
        This version of the function does not take any type of arguments
        and notify user that a photo has been clicked 

        So, compiler at compile time will match the number and type of
        arguments passed in the function and call the appropriate 
        function.
    */
    void click_photo(){
        std::cout << "Clicked with " <<  model <<std::endl;
        std::cout << "A beautiful photo has been clicked and stored in phone storage" << std::endl;
    }

    /*
        click_photo function from above has been overloaded with 
        different number of arguments. This version of function
        takes two arguments of int and string types respectively
        and notifies the user that a photo has been clicked and 
        how many lens of the camera were used to click the photo.
        Also, notifes wether the clicked photo has been stored 
        in local storage or in cloud stroge.
    */
    void click_photo(int use_n_lens, const std::string& store_in){
        std::cout << "Clicked with " <<  model <<std::endl;
        if(use_n_lens >= 1 && use_n_lens <= 2){
            std::cout << "A beautiful photo has been clicked and stored in " << store_in << std::endl;
        }else if(use_n_lens >=3 && use_n_lens <= 5){
            std::cout << "A beautiful photo in HD has been clicked and stored in " << store_in << std::endl;
        }else{
            std::cout << "looks like some lens are not working" << std::endl;
            std::cout << "Using a single lens" << std::endl;
            std::cout << "A beautiful photo has been clicked and stored in " << store_in << std::endl;
        } 
    }
};

int main(){
    //example showing use of function overriding
    phone* nokia = new phone("Nokia", "Classic");
    nokia->display_info();
    std::cout << "****************************" << std::endl;

    phone* samsung = new smart_phone("Samsung", "Galaxy S10", "Android", 6, 64);
    samsung->display_info();
    std::cout << "****************************" << std::endl;
    //example showing use of function overloading
    smart_phone* iphone = new smart_phone("Apple", "iphone XS", "ios", 6, 128);
    iphone->click_photo();
    std::cout << "***************************" << std::endl;
    iphone->click_photo(3, "iCloud");
}