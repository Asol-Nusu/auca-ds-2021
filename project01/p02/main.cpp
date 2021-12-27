//ACCEPTED
#include <bits/stdc++.h> 
#include "../BigInt/BigInt.hpp"

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 

int main()
{
    iostream::sync_with_stdio(false); 
    int tests;
    cin >> tests;

    for(int i = 0; i < tests; i++){
        BigInt benefit;
        BigInt cost;

        cin >> benefit >> cost;
        cout << benefit - cost << "\n"; 
    }
} 