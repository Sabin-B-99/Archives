#pragma once
#include <iostream>
#include "employee.h"
#include <vector>

class department : public employee{
    private:
        int department_id;
        std::vector<int> sub_code_taught;
        double salary;

    public:
        department();
        department(int, const std::string&, int, const std::string&, int, const std::vector<int>&, double);
        void display_info() const;
};