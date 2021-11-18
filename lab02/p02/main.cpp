//ACCEPTED
#include <bits/stdc++.h> 
template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
std::int64_t computeRows(std::int64_t nOfWarriors){
    /*
        Arithmetic Progression
        S = (a1 + an)/2 * n
    */
    std::int64_t discriminantRoot = std::sqrt(1 + 8 * nOfWarriors);
    std::int64_t totalNumberOfRows = (-1 + discriminantRoot)/2;

    return totalNumberOfRows;
}

int main()
{
    iostream::sync_with_stdio(false); 
    
    int testCases;
    cin >> testCases;

    for(int i = 0; i < testCases; ++i){
        std::int64_t nOfWarriors;
        cin >> nOfWarriors;
        cout << computeRows(nOfWarriors) << "\n";
    }
}