#include <iostream>
using namespace std;
#include "factorial.h"
int main(){
    factorial fact1(5);
    factorial fact2 = fact1;
    cout << "Calculated factorial: " << fact2.calculate_factorial() << endl;
}