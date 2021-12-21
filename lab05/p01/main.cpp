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
void p01(){
    cout << "the size of the array: ";
    int n;
    cin >> n;

    VecInt v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    auReverse(v.begin(), v.end());
    printVecInt(v);    
}
void p02(){
    VecInt v;
    for(int x; cin >> x;){
        v.pushBack(x);
    }
    printVecInt(v);
    auReverse(v.begin(), v.end());
    v[100000] = 6;
    printVecInt(v);
}

int main(){
    p01();
}