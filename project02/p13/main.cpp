//ACCEPTED
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

void justifyRight(const string &word, int maxLength){
    int diff = maxLength - (int)word.length();
    for(int i = 0; i < diff; i++){
        cout << " "; 
    }
}

//Use sort with functor (lambda), reverse
int main()
{
    iostream::sync_with_stdio(false); 

    string word;
    int maxLength = 0;
    vector<string> words;
    while(getline(cin, word)){
        
        if(!word.empty()){
            reverse(word.begin(), word.end());
            maxLength = max(maxLength, (int)word.length());
            words.push_back(word);
        }else{
            //New group began
            sort(begin(words), end(words));

            for(auto w : words){
                justifyRight(w, maxLength);
                reverse(w.begin(), w.end());
                cout << w << endl;
            }
            cout << endl;
            maxLength = 0;
            words.clear();
        }
    }
    //Last group (else case doesn't work)
    sort(begin(words), end(words));

    for(auto w : words){
        justifyRight(w, maxLength);
        reverse(w.begin(), w.end());
        cout << w << endl;
    }
} 

/*
    vector.clear() Removes all elements from the vector (which are destroyed), 
    leaving the container with a size of 0.
*/