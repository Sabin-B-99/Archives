#include <iostream>

using namespace std;
template <class T> void swapVals(T &num1, T &num2);

int main(){
    double num1 = 3;
    double num2 = 4;
    cout << "Before:" << endl;
    cout << "num1 = " << num1 << " and num2 = " << num2 << endl;
    cout << "***************************************************" << endl;
    swapVals(num1,num2);
    cout << "After:" << endl;
    cout << "num1 = " << num1 << " and num2 = " << num2 << endl;
    cout << "***************************************************" << endl;
    return 0;
}

template <class T> void swapVals(T &num1, T &num2){
    T temp = num1;
    num1 = num2;
    num2 = temp;
}


