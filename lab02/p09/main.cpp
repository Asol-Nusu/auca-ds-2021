//ACCEPTED
#include <bits/stdc++.h> 
#include <vector>
#include <algorithm>
 
template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}
using namespace std; 

int findDistance(vector<int> &storePositions){
    sort(storePositions.begin(), storePositions.end());
    int firstStore = storePositions.front();
    int lastStore = storePositions.back();
    int distance = (lastStore - firstStore)*2;
    return distance;
}

int main() 
{
    iostream::sync_with_stdio(false);
    int tests;
    cin >> tests;

    for(int i = 0; i < tests; ++i){
        int nOfStores;
        cin >> nOfStores;
        auto storePositions = vector<int>(nOfStores);
        
        //Initializing positions of the stores
        for(int j = 0; j < nOfStores; j++){
            cin >> storePositions[j];
        } 
        cout << findDistance(storePositions) << "\n";
    }
} 