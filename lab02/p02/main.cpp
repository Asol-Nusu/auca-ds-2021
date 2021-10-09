#include <bits/stdc++.h> 
template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
long long int computeRows(int nOfWarriors){
    long long int totalNumberOfRows = 0;

    long long int row = 1;
    while(true){
        if(nOfWarriors < row){ //if warriors = 0, then rows = 0
            break;
        }

        nOfWarriors -= row;
        ++totalNumberOfRows;

        ++row;
    }

    return totalNumberOfRows;
}

int main()
{
    iostream::sync_with_stdio(false); 
    
    long long int testCases;
    cin >> testCases;

    for(int i = 0; i < testCases; ++i){
        long long int nOfWarriors;
        cin >> nOfWarriors;
        cout << computeRows(nOfWarriors) << "\n";
    }
}