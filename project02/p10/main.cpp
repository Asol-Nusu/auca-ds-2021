/*
diameter color [XXX]
color radius  

From the smallest radius to the biggest
*/
#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
pair<string, int> produceValidValues(const string &rawInput){
    string part1;
    string part2;

    bool goToPart2 = false;
    for(char c : rawInput){
        if(c != ' ' && !goToPart2){
            part1.push_back(c);
        }else if(c == ' '){
            goToPart2 = true;
        }

        if(goToPart2){
            part2.push_back(c);
        }
    }

    int radius;
    string color;

    if(isdigit(part1.front())){
        //Bad case: diameter color [XXX]
        radius = stoi(part1)/2;
        color = part2;
    }else{
        //Good case: color radius
        color = part1;
        radius = stoi(part2);
    }

    return make_pair(color, radius);
}

//use sort, pair<int, string>
int main()
{
    iostream::sync_with_stdio(false);
    int nOfCups;
    cin >> nOfCups;
    cin.ignore(10000, '\n');

    vector<pair<string, int>> cups;
    for(int i = 0; i < nOfCups; i++){
        string rawInput;
        getline(cin, rawInput);

    }
} 