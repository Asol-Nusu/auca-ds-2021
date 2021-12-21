#include <iostream>
#include "../../au/algol.hpp"
#include "VecInt.hpp"

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

int main(){
    VecInt v;
    for(int x; cin >> x;){
        v.pushBack(x);
    }
    printVecInt(v);
    auReverse(v.begin(), v.end());
    v[100000] = 6;
    printVecInt(v);
}