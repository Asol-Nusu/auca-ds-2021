/*
sort a group of people by their classes 
to show their true place in the social class hierarchy.

three main classes: upper, middle, and lower.
upper-upper > middle-upper > lower-upper

all of the upper classes (upper-upper, middle-upper, and lower-upper) 
are higher than any of the middle classes.

When comparing classes, once you have reached the lowest level of detail, 
you should assume that all further classes are the same as the middle level of the previous level of detail.
*/
#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
pair<string, string> produceValidValues(const string &rawInput){
    string name;
    string socialClass;
    bool isSocialClassPart = false;
    for(auto c : rawInput){
        if(c != ':' && c != ' ' && !isSocialClassPart){
            name.push_back(c);
        }else if(c == ':' || c == ' '){
            isSocialClassPart = true;
            continue;
        }

        if(isSocialClassPart){
            socialClass.push_back(c);
        }
    }

    return make_pair(name, socialClass);
}

//use stable_sort, pair<string, string>
int main()
{
    iostream::sync_with_stdio(false); 
    int tests;
    cin >> tests;
    for(int i = 0; i < tests; i++){
        int nOfPeople;
        cin >> nOfPeople;
        cin.ignore(10000, '\n');

        for(int j = 0; j < nOfPeople; j++){
            string rawInput;
            getline(cin, rawInput);
            pair<string, string> person = produceValidValues(rawInput);
        }
    }
} 