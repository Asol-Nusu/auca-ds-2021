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
    std::string input; 
    BigInt sum = BigInt(); //0
    while(getline(cin, input) && input != "0"){
        sum += BigInt(input);
    }

    cout << sum << "\n";
} 