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
    string s = "c";
    vector<string> r = makeGoodValues("My name is Sol");
    for(auto w : r){
        cout << w << "\n";
    }
} 