#include <iostream>
#include "hello.hpp" //it's just a good idea since it can be useful with predicting potential errors

void hello(){
    std::cout << "Hello, C++ " << __cplusplus << "!!!\n";
}