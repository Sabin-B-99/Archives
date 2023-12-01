#include <iostream>
#include <vector>

template<typename T>
void get_numbers(std::vector<T>& numbers);

template<typename T>
T find_largest(std::vector<T>& numbers);

//client program
int main(){
    std::vector<double> input_numbers;
    get_numbers(input_numbers);
    auto largest = find_largest(input_numbers);
    std::cout << "********************************" << std::endl;
    std::cout << "Largest Number = " << largest << std::endl;
}

/*
    Tempalte function that will accept 10 primitive numerical types
    and store them in a vector refrenced as the parameter to this 
    function. However, this function will not ensure type saftey as
    the client program can still pass a string as type T, which will
    work just fine for this function but may lead to runtime errors in
    other portion of the program, if the intended use was for a 
    mathematical type
*/
template<typename T>
void get_numbers(std::vector<T>& numbers){
    std::cout << "Enter ten positive numbers" << std::endl;
    T num;
    for(int i = 0; i < 10; i++){
        std::cout << "Number " << i << " =  "; 
        while(!(std::cin >> num)){
            std::cin.clear(); //clear previous input
            std::cin.ignore(123, '\n');
            std::cout << "You need to enter a number." << std::endl;
            std::cout << "Number " << i << " = ? ";
        }
        numbers.emplace_back(num);
    }
}

/*
    Function that sorts (insertion sort) the elements
    of the refrenced vector passed as parameter to this function.
    The fucntion will return the largest number among the numbers 
    present in the refrenced vector. 
*/
template<typename T>
T find_largest(std::vector<T>& numbers){
    T temp;
    int j;
    for(size_t i = 1; i < numbers.size(); i++){
        temp = numbers.at(i);
        j = i - 1;
        while(j >= 0 && numbers[j] > temp){
            numbers.at(j+1)  = numbers.at(j);  
            j = j - 1;  
        }
        numbers.at(j+1) = temp;
    }
    return numbers.at(numbers.size() - 1);
}