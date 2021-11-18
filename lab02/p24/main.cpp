#include <bits/stdc++.h>  
#include <algorithm>
template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; //to avoid repetition

int main()
{
    iostream::sync_with_stdio(false); 
    int tests;
    cin >> tests;
    for(int i = 0; i < tests; i++){
        int nOfRelatives;
        cin >> nOfRelatives;
        vector<int> streetNumbers = vector<int>(nOfRelatives);

        for(int r = 0; r < nOfRelatives; r++){
            cin >> streetNumbers[r];
        }
        sort(streetNumbers.begin(), streetNumbers.end());
        cout << streetNumbers.back() - streetNumbers.front() << "\n";
    }
} 