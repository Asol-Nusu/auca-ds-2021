#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 

//11044
int main()
{
    iostream::sync_with_stdio(false); 
    
    int testCases;
    cin >> testCases;
    for(int i = 0; i < testCases; ++i){
        int rows;
        int columns;

        cin >> rows;
        cin >> columns;
        
        rows -= 2;
        columns -= 2;

        int locatorsPerLine = rows/3 + (rows % 3 != 0); //true - 1, false - 0
        int nOfLines = columns/3 + (columns % 3 != 0);

        cout << nOfLines * locatorsPerLine << "\n";
    }
}