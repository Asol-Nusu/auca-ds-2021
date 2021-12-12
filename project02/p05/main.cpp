/*
Find out the frequencies of the ASCII characters.

*/
#include <bits/stdc++.h> 
 
template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
struct Pair{
    int mAscii; 
    int mValue;

    Pair(const int &ascii, const int value)
    : mAscii(ascii), mValue(value)
    {
    }
};

int main()
{
    iostream::sync_with_stdio(false); 
    vector<Pair> pairs;

    string input;
    while(getline(cin, input)){
        //Working on a string input
        for(int i = 0; i < (int)input.length(); i++){
            char character = input.at(i);
            int value = character;
        }


        cout << "\n";
    }

} 