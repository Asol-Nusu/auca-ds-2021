#include <bits/stdc++.h> 
template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
std::int64_t computeRows(int nOfWarriors){
    std::int64_t nOfRows = 0;

    std::int64_t row = 1;
    while(true){
        if(nOfWarriors < row){ //if warriors = 0, then rows = 0
            break;
        }

        nOfWarriors -= row;
        ++nOfRows;

        ++row;
    }

    return nOfRows;
}

int main()
{
    iostream::sync_with_stdio(false); 
    std::int64_t testCases;
    cin >> testCases;

    for(int i = 0; i < testCases; ++i){
        std::int64_t nOfWarriors;
        cin >> nOfWarriors;
        cout << computeRows(nOfWarriors) << "\n";
    }
}