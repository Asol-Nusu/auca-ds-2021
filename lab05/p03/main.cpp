#include <iostream>
#include "../../au/algol.hpp"
#include "VecInt.hpp"
#include <algorithm>

using namespace std;
void printVecInt(const VecInt &v){
    // for(int e : v){
    //     cout << e << " ";
    // }
    // cout << "\n";
    for(size_t i = 0; i < v.size_f(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

void p01(){
    cout << "-----p01-----" << endl;
    VecInt::numOfCopies = 0;

    VecInt v1 = {1, 2, 3};
    VecInt v2 = {4, 5, 6, 7, 8, 9, 10};

    swap(v1, v2);
    cout << "v1.size() = " << v1.size_f() << endl;
    cout << "v2.size() = " << v2.size_f() << endl;

    cout << "number of copies: " << VecInt::numOfCopies << endl;
}

int main(){
    p01();
}