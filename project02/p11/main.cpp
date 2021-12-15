#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 

//use stable_sort with lambda expression
int main()
{
    iostream::sync_with_stdio(false); 
    int nOfWords;
    int wordLength;

    bool firstTime = true;
    cin >> nOfWords >> wordLength;
    while(nOfWords != 0 && wordLength != 0){
        if(!firstTime){
            cout << "\n";
        }

        //receiving each word, I sort Column Strings
        for(int i = 0; i < nOfWords; i++){
            string word;
            cin >> word;
            
        }

        firstTime = false;
        cin >> nOfWords >> wordLength;
    }
} 