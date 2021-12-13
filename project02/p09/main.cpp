#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
vector<string> makeGoodValues(const string &input){
    vector<string> result;
    istringstream ss(input);

    string word; // for storing each word
    while (ss >> word) 
    {
        result.push_back(word);
    }

    return result;
}
int main()
{
    iostream::sync_with_stdio(false); 
    int contestantName;
    string input = "12 34 45 l";
    vector<string> r = makeGoodValues(input);
    for(int i = 0; i < 4; i++){
        cout << r[i] << "\n";
    }
    char c = r[3].at(0);
    cout << c << "\n";
} 