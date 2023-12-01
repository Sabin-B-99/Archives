#pragma once
#include <iostream>
#include <string>

class employee{
    protected:
        int id;
        std::string name;
        int join_year;
        std::string address;

    public:
        employee();
        employee(int, const std::string&, int, const std::string&);

        virtual void display_info() const =0;
};