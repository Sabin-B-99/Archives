#include <iostream>
using namespace std;
class simple_intrest{
    private:
        double principal;
        double rate;
        int time;
    
    public:
        simple_intrest();
        simple_intrest(double , double , int );
        inline double calculate_simple_intrest();
        
};

simple_intrest::simple_intrest(double principal, double rate, int time){
    this->principal = principal;
    this->rate = rate;
    this->time = time;
}
simple_intrest::simple_intrest(){
    this->principal = 100;
    this->time = 1;
    this->rate = 10;
}

inline double simple_intrest::calculate_simple_intrest(){
    return (principal * rate * static_cast<double>(time)) / 100;
}

int main(void){
    simple_intrest intrest(1000, 2, 10);
    cout << "Intrested calulated is: " << intrest.calculate_simple_intrest();
    return 0;   
}