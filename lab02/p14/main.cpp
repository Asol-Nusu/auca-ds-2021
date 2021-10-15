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

        bool orderedRight = true; // min from left
        for(int j = 1; j < 10; j++){
            if(beards[j - 1] > beards[j]){
                orderedRight = false;
            }

            if(!orderedRight){
                break;
            }
        }

        bool orderedLeft = true; //min from right
        for(int j = 9; j < 0; j--){
            if(beards[j] < beards[j-1]){
                orderedRight = false;
            }

            if(!orderedRight){
                break;
            }
        }

        cout << "Lumberjacks:\n";
        if(!orderedLeft && !orderedRight){
            cout << "Unordered\n";
        }else{
            cout << "Ordered\n";
        }
    }
} 