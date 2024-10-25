// ASTE 404 HW 7
// By: Justin Chandler

#include<iostream>
#include"vec.h"


int main(int num_args, char **args) {
    double3 a{0,1,2};
    double3 b{0,0,1};

    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    std::cout<<a-b<<std::endl;
    std::cout<<dot(a,b)<<std::endl;

    return 0;
}