#include "test.h"

void test::get_each_marks(){
    for(int i = 0; i < (this->res).size(); i++){
        std::cout << "Result of " << get_name() << "&"<< "Registration no: " << get_reg_no() << std::endl;
        std::cout << (this->res)[i].first << ":" << (this->res)[i].second << std::endl;
    }
    std::cout<<"*******************Best of luck*******************" << std::endl;
}