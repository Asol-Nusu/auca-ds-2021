//ACCEPTED*
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

    vector<BigInt> fibonacciNumbers;
    fibonacciNumbers.push_back(0);
    fibonacciNumbers.push_back(1);
        
    for(int i = 2; i <= 5000; i++){
        BigInt currentNum = fibonacciNumbers[i-1] + fibonacciNumbers[i-2];
        fibonacciNumbers.push_back(currentNum);
    }

    int fNumber;
    while(cin >> fNumber){
        BigInt r = fibonacciNumbers[fNumber];
        cout << "The Fibonacci number for " << fNumber << " is " << r << "\n";
    }
} 