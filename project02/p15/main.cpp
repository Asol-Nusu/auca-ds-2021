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
vector<pair<int, string>> convertToPairs(const string &rawInput){
    istringstream streamInput(rawInput);

    vector<pair<int, string>> pairs;

    int index = 0;
    for(string s; streamInput >> s;){
        pairs.push_back(make_pair(index, s));
        index++;
    }

    return pairs;
}

vector<string> convertToStrings(const string &rawInput){
    istringstream streamInput(rawInput);
    vector<string> strings;
    for(string s; streamInput >> s;){
        strings.push_back(s);
    }
    return strings;
}
//stable_sort with lambda expression (capture), find
int main()
{
    iostream::sync_with_stdio(false); 

    //Attributes
    string attributesString;
    getline(cin, attributesString);
    //Splitting attributes 
    vector<pair<int, string>> attributes = convertToPairs(attributesString); //each attribute will have its index

    int nOfSongs;
    cin >> nOfSongs;
    cin.ignore(10000, '\n');

    vector<vector<string>> playList;
    /*vector of songs; each song is a vector of separated string infos*/
    for(int i = 0; i < nOfSongs; i++){
        string record;
        getline(cin, record);
        vector<string> recordInfo = convertToStrings(record);
        playList.push_back(recordInfo);
    }
    
    int nOfCommands;
    cin >> nOfCommands;
    bool firstTime = true;
    for(int i = 0; i < nOfCommands; i++){
        if(!firstTime){
            cout << endl;
        }
        string command;
        cin >> command;
        
        auto foundAttribute = find_if(begin(attributes), end(attributes), [&command](const pair<int, string> &attribute){
            return attribute.second == command;
        });

        int commandIndex;
        if(foundAttribute != end(attributes)){
            commandIndex = (*foundAttribute).first;
        }

        stable_sort(begin(playList), end(playList), [&commandIndex](const vector<string> &record1, const vector<string> &record2)
        {
            return record1[commandIndex] < record2[commandIndex];
        });

        cout << attributesString << endl;
        for(int record = 0; record < (int)playList.size(); i++){
            for(int recordInfo = 0; recordInfo < (int)playList[record].size(); recordInfo++){
                bool finish = recordInfo == ((int)playList[record].size() - 1);
                string r = (!finish) ? " " : "\n";
                cout << playList[record][recordInfo] << r;
            }
        }

        firstTime = false;
    }
} 