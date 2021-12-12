#include <bits/stdc++.h> 
 
template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
struct SpecialString{
    string mSequence;
    int mInputIndex;
    int mInversions = 0;
    

    SpecialString(const string &sequence, const int inputIndex)
    : mSequence(sequence), mInputIndex(inputIndex)
    {
        //Calculate the number of inversions (A, C, G, T)
        for(int i = 0; i < sequence.length(); i++){
            for(int j = i; j < sequence.length(); j++){
                if(sequence.at(i) > sequence.at(j)){
                    mInversions++;
                }
            }
        }
    }
};

int main()
{
    iostream::sync_with_stdio(false); 
    int tests;
    cin >> tests;
    for(int test = 0; test < tests; test++){
        int stringLength;
        int nOfStrings;
        cin >> stringLength >> nOfStrings;

        vector<SpecialString> specialStrings;

        //Reading special strings
        for(int i = 0; i < nOfStrings; i++){
            string input;
            cin >> input;
            specialStrings.push_back(SpecialString(input, i));
        }

        cout << (test != tests - 1) ? "\n" : "";
    }
    
} 