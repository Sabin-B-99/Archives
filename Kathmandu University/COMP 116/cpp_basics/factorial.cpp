#include <iostream>
using namespace std;
class factorial{
    private:
        int num_to_factor;
    public:
        factorial();
        factorial(int);
        factorial(factorial &obj2);
        int calculate_factorial();
};

//empty/default constructor
factorial::factorial(){
    this->num_to_factor = 1;
}

//paramatrized constructor
factorial::factorial(int num_to_factor){
    this->num_to_factor = num_to_factor;
}

//copy constuctor
factorial::factorial(factorial &obj2){
    num_to_factor = obj2.num_to_factor;
}

//method definition to calculate factorial
int factorial::calculate_factorial(){
    int fact_ans = 1;
    for (int i = 1; i <= num_to_factor; i++)
    {
        fact_ans *= i;
    }
    return fact_ans;
}

int main(){
    factorial fact1(5);
    factorial fact2 = fact1;
    cout << "Calculated factorial: " << fact2.calculate_factorial() << endl;
}