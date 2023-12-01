/*
    Author: Sabin Badal
    Date: 10/7/2020
    
    Description:
    Simple program that lets user calculte average of any data types provided.
*/
#include <iostream>
#include <typeinfo>

template <typename T>
T average(T arr[], int size);

int main(){
    int arrayOInt[7] = {4,5,1,3,10,12,7};
    long arrayOLong[5] = {1L, 2L, 5L, 8L, 9L};
    double arrayODouble[6] = {5.5, 4.8, 5.0, 2.1, 8.9, 1.1};
    char arrayOchar[2] = {'K', 'U'};
    std::cout << "****************Average Values****************" << std::endl;
    std::cout << "Average of integers: " << average<int>(arrayOInt, 7) << std::endl;
    std::cout << "Average of longs: " << average<long>(arrayOLong, 5) << "L" << std::endl;
    std::cout << "Average of doubles: " << average<double>(arrayODouble, 6) << std::endl;
    std::cout << "Average of chars: " << average<char>(arrayOchar, 3) << std::endl;
    std::cout << "**********************************************" << std::endl;
}

/*
    Template function that takes in an array of any primitive type and the number of
    elements in that array. Based on this information this function calculates the 
    average of the types and returns them.
*/
template <typename T>
T average(T arr[], int size){
    T sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return (sum / size);
}