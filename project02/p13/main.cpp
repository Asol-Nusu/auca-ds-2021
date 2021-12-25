/*
it organizes words based on how they end rather than how they start (alphabetically).
If two words have the same suffix, the shorter word is sorted earlier.
*/
#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 

//Use sort with functor (lambda), reverse
int main()
{
    iostream::sync_with_stdio(false); 
    string word;
    vector<string> words;
    while(getline(cin, word)){
        if(!word.empty()){
            words.push_back(word);
        }else{
            //New group began
            sort(begin(words), end(words), [](const string &w1, const string &w2)
            {
                if(){
                    
                }
                return w1.back() < w2.back();
            });



            words.clear();
        }
    }    
} 

/*
    vector.clear() Removes all elements from the vector (which are destroyed), 
    leaving the container with a size of 0.
*/