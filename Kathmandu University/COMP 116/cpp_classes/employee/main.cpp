#include <iostream>
#include "department.h"

int main(){
    std::vector<int> sub_codes;
    sub_codes.push_back(234);
    sub_codes.push_back(1133);
    sub_codes.push_back(321);
    employee* employee = new department(01, "Sabin Badal", 2018, "Dhulikhel - 08", 9, sub_codes, 10.01);

    employee->display_info();

}