#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 

int main()
{
    iostream::sync_with_stdio(false); 
    vector<string> words = {"apple",  "banaca", "bananba", "kiwi", "pear", "zzzza"};
    sort(begin(words), end(words), [](const string &w1, const string &w2){
        string reversedW1 = w1;
                string reversedW2 = w2;
                reverse(reversedW1.begin(), reversedW1.end());
                reverse(reversedW2.begin(), reversedW2.end());

                return reversedW1 < reversedW2;
    });
    for(string w : words){
        cout << " " << w;
    }
} 