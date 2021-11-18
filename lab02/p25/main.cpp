#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
int findClosestSum(const vector<int> &integers, const int &nOfIntegers, const int &query){
    int closestSum;
    for(int i = 0; i < nOfIntegers; i++){
        for(int j = i + 1; j < nOfIntegers; j++){
            if(i == 0){
                int currentSum = integers[i] + integers[j];
                if(currentSum <= query){
                    closestSum = currentSum;
                }
            }else{
                int currentSum = integers[i] + integers[j];
                int absoluteValue = abs(query - currentSum);
                if(absoluteValue < closestSum){
                    closestSum = currentSum;
                }
            }
        }
    }

    return closestSum;
}

int main()
{
    iostream::sync_with_stdio(false); 
    int nOfIntegers;
    cin >> nOfIntegers;
    int testCase = 1;
    while(nOfIntegers != 0){

        vector<int> integers = vector<int>(nOfIntegers);

        for(int i = 0; i < nOfIntegers; i++){
            cin >> integers[i];
        }

        int nOfQueries;
        cin >> nOfQueries;

        cout << "Case " << testCase << ":\n";

        for(int i = 0; i < nOfQueries; i++){
            int query;
            cin >> query;
            
            cout << "Closest sum to " << query << " is " << findClosestSum(integers, nOfIntegers,query) << ".\n";
        }

        cin >> nOfIntegers;
        testCase++;
    }
} 