#include <iostream>
template <typename T>
void getInput(T arr[], int arrSize)
{
    for(int i = 0; i < arrSize; i++)
    {
        std::cout << "Enter " << (i+1) << " th element: \t ";
        std::cin >> arr[i];
    }
}

template <typename T>
void printArr(T arr[], int arrSize)
{
    std::cout << "The elements of array are:" << std::endl;
    for(int i = 0; i < arrSize; i++)
    {
        std::cout << arr[i] << ", \t";
    }
}

int main()
{
    std::cout << "For double" << std::endl;
    double dArr[10];
    std::cout << "Enter Integers" << std::endl;
    getInput<double>(dArr, 10);
    printArr<double>(dArr, 10); 
}