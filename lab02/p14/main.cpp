//ACCEPTED
#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 

int main()
{
    iostream::sync_with_stdio(false); 
    int nOfGroups;
    cin >> nOfGroups; //0 < N < 20

    for(int i = 0; i < nOfGroups; i++){
        vector<int> beards;

        //Filling in the array
        for(int j = 0; j < 10; j++){
            int currentBeard;
            cin >> currentBeard;
            beards.push_back(currentBeard);
        }

        bool orderedSL = true; // shortest to longest
        for(int j = 1; j < 10; j++){
            if(beards[j - 1] > beards[j]){
                orderedSL = false;
                break;
            }
        }

        bool orderedLS = true; // longest to shortest
        for(int j = 1; j < 10; j++){
            if(beards[j-1] < beards[j] ){
                orderedLS = false;
                break;
            }
        }

        if(i == 0){
            cout << "Lumberjacks:\n";
        }
        if(orderedLS || orderedSL){
            cout << "Ordered\n";
        }else{
            cout << "Unordered\n";
        }
    }
} 