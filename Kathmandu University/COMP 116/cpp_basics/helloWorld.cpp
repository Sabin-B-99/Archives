#include <iostream>

int min(int a, int b);
int min(int a, int b, int c);
int min(int a, int b, int c, int d);

using namespace std;
int main(){
    //std::cout << "Hello World!";
    // std:: cout << "How old are you?" << std::endl;
    // int age = 0;
    // std:: cin >> age;
    // std:: cout << age << " is a great age to start learning c++. Enjoy!" << std:: endl;
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;
    
    
    cout << "Enter the numbers to be compared(maximum of four) :)" << endl;
    cin >> num1 >> num2 >> num3 >> num4;
    cout << "Min between two numbers: " <<  min(num1, num2) << endl;
    cout << "Min between three numbers: " <<  min(num1, num2, num3) << endl;
   // cout << "Min between four numbers: " <<  min(num1, num2, num3, num4) << endl;

    return 0;
}

int min(int a, int b){
    int minVal;
    minVal =  a < b ? a : b;
    return minVal;
}

int min(int a, int b, int c){
    int minVal;
    minVal = a < b ? (a < c ? a : c) : b;
    return minVal;
}

// int min(int a, int b, int c, int d){
//     int minVal;
//     minVal = a < b ?  (a < c ?  (a < d ? a : d) : (c < d ? c : d)) : b;       
//     return minVal;
// }
