/*
    Author: Sabin Badal
    Date: 10/7/2020
    
    Description:
    Simple program that displays sorts an array of 
    any number types. This array must have ten elements.
    The program takes in 10 numbers as input form the user,
    sorts those ten numbers in ascending order and displays
    the sorted list in the screen
*/
#include <iostream>
template<typename T>
void get_numbers(T arr[]);

template<typename T>
void sort(T arr[]);

template<typename T>
void display_sorted(T arr[]);

/*
    client program showing the use of the sorting functions as
    well as other functions declared above. This client program
    dispays the use of these function with integer types and
    double types 
*/
int main(){
    std::cout << "*********INTEGER SORTED********" << std::endl;
    int arr[10];
    get_numbers<int>(arr);
    sort<int>(arr);
    display_sorted<int>(arr);
    std::cout << "**********DOUBLE SORTED*********" << std::endl;
    double arrII[10];
    get_numbers<double>(arrII);
    sort<double>(arrII);
    display_sorted<double>(arrII);

}

/*
    A function that takes ten number input from the user
    and initializes the array of size 10, which is passed
    as refrence argument to this function.
*/
template<typename T>
void get_numbers(T arr[]){
    std::cout << "Enter ten numbers" << std::endl;
    T num;
    for(int i = 0; i < 10; i++){
        std::cout << "Number " << i << " =  ";
        /*
            forcing user to enter a number value.
            If the user inputs a string or char type 
            then the whole program will not crash
        */ 
        while(!(std::cin >> num)){
            std::cin.clear(); //clear previous input
            std::cin.ignore(123, '\n');
            std::cout << "You need to enter a number." << std::endl;
            std::cout << "Number " << i << " = ? ";
        }
        arr[i] = num;
    }
}

/*
    A function that takes ten element number array refrence
    of any number types as an argument and sorts that array 
    in ascending order.
*/
template<typename T>
void sort(T arr[]){
    T temp;
    for(int i = 0; i < 9; i++){
        for (int j = i+1; j < 10; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            
        }
    }
}

/*
    A function that takes ten element number array refrence
    of any number types as an argument displays all the elements
    present in that array to the console screen.
*/
template<typename T>
void display_sorted(T arr[]){
    std::cout << "Arrays in sorted order" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << std::endl;    
    }
}