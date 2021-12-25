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
vector<pair<int, string>> convert(const string &rawInput){
    istringstream streamInput(rawInput);

    vector<pair<int, string>> pairs;

    int index = 0;
    for(string s; streamInput >> s;){
        strings.push_back(make_pair(index, s));
        index++;
    }

    return pairs;
}
//stable_sort with lambda expression (capture), find
int main()
{
    iostream::sync_with_stdio(false); 

    //Attributes
    string attributesString;
    getline(cin, attributesString);
    //Splitting attributes 
    vector<pair<int, string>> attributes = convert(attributesString); //each attribute will have its index

    int nOfSongs;
    cin >> nOfSongs;
    cin.ignore(10000, '\n');

    vector<vector<pair<int, string>>> playList;
    /*vector of songs; each song is a vector of pairs<int, string>*/
    for(int i = 0; i < nOfSongs; i++){
        string record;
        getline(cin, record);
        vector<pair<int, string>> recordInfo = convert(record);
        playList.push_back(recordInfo);
    }
    
    int nOfCommands;
    cin >> nOfCommands;
    for(int i = 0; i < nOfCommands; i++){
        string command;
        cin >> command;
        
    }
} 