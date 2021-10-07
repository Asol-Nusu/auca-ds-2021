#include <bits/stdc++.h> 
/*
This header is a collection of all header files from C and C++ 
standard libraries. 
*/  
template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
    /*
    c.size() return unsigned int which is bad. 
    So that is why we are doing type conversion. 
    */
}

using namespace std; //to avoid repetition

int main()
{
    iostream::sync_with_stdio(false); 
    /*
    Don't synchronize i/o C++ library with C library [only C++ i/o facilities].
    Turn off synchronization with printf() and scanf()
    */
} 