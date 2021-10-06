#include <iostream>

int main(){
#ifdef AUCA_DEBUG
    std::cout << "Author: Asol Nusuvalieva" << std::endl;
#endif

    std::cout << "Hello, C++ " << __cplusplus << "!!!\n";
}