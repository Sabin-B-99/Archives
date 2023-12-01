/*
    Author: Sabin Badal
    Date: 10/8/2020
    
    Description:
    Simple application that checks the greater number between
    two values of any number type.
*/
#include <iostream>

template<typename T1, typename T2>
double max(T1 numI, T2 numII);

template<typename T, typename U>
void display_max_val(T numI, U numII);

int main(){
    int numI = 4;
    double numII = 5.1;
    display_max_val(numI,numII);

    double numIII = 8.86;
    double numIV = 8.82;
    display_max_val(numIII, numIV);

    int numV = 3;
    int numVI = 3;
    display_max_val(numV,numVI);    
}

/*
    Function that checks and returns the maximum/greatest
    value among any two number types which are passed as
    arguments of this funtion. The function will throw 
    an exception if the two passed number are equal. 
*/
template<typename T1, typename T2>
double max(T1 numI, T2 numII){
    if(numI == numII){
        std::string error = "The given numbers are equal!";
        throw error;
    }else if(numI > numII){
        return numI;
    }else{
        return numII;
    }
}

/*
    Function will print to the screen which number is greater among 
    two passed number. The check will be done by use of 
    max(...) function present above.
*/
template<typename T, typename U>
void display_max_val(T numI, U numII){
    try
    {
        double max_val = max(numI,numII);
        std::cout << "*******************************************************" << std::endl;
        std::cout << "The max value between " << numI << " and " << numII << " is: " << max_val << std::endl;
        std::cout << "*******************************************************" << std::endl;
    }
    catch(const std::string& err_msg)
    {
        std::cerr << err_msg << std::endl;
    }
}