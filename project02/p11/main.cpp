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
        vector<string> normalStrings;
        for(int i = 0; i < nOfWords; i++){
            string word;
            cin >> word;
            normalStrings.push_back(word);
        }

        //Building vertical strings
        vector<string> verticalStrings;
        for(int column = 0; column < wordLength; column++){
            string verticalString;
            for(int row = 0; row < nOfWords; row++){
                verticalString.push_back(normalStrings[row].at(column));
            }
            verticalStrings.push_back(verticalString);
        }
        
        stable_sort(begin(verticalStrings), end(verticalStrings), [](const string &vS1, const string &vS2){
            string vS1Copy = vS1;
            string vS2Copy = vS2;
            transform(vS1Copy.begin(), vS1Copy.end(), vS1Copy.begin(), ::tolower);
            transform(vS2Copy.begin(), vS2Copy.end(), vS2Copy.begin(), ::tolower);

            return vS1Copy < vS2Copy;
            //in case they are equal, stable sort will keep the orginal/relative order
        });

        firstTime = false;
        cin >> nOfWords >> wordLength;
    }
} 