/*
The first sort starts from the order of songs as given in the input. 
Each subsequent sort starts from the order given by the previous sort, 
rather than starting from the initial order. 
All sorting should be done least to greatest, in lexicographic order 
(using ASCII values, even for numeric data).
*/
#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 

//stable_sort with lambda expression (capture), find
int main()
{
    iostream::sync_with_stdio(false); 

    //Attributes
    string attributesString;
    getline(cin, attributesString);
    istringstream streamInput(attributesString);
    
    //Splitting attributes 
    vector<string> attributes;
    for(string attribute; streamInput >> attribute;){
        attributes.push_back(attribute);
    }

    int nOfSongs;
    cin >> nOfSongs;
    cin.ignore(10000, '\n');
    
    vector<vector<string>> playList;
    for(int i = 0; i < nOfSongs; i++){
        string input;
        getline()
    }
} 