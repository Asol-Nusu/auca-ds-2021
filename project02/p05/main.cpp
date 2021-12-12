//ACCEPTED
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
    friend bool operator== (const Pair &lhs, const Pair &rhs);
    int mASCIIValue; 
    int mOccurrence = 0; //int value, such naming is not clear to me

    Pair(const int &asciiValue)
    : mASCIIValue(asciiValue)
    {
        mOccurrence++;
    }
};

bool operator==(const Pair &a, const Pair &b){
    return a.mASCIIValue == b.mASCIIValue;
}

int main()
{
    iostream::sync_with_stdio(false); 

    int presentationChecker = 0;
    string input;
    while(getline(cin, input)){
        if(presentationChecker != 0){
            cout << "\n";
        }

        //Working on a string input
        vector<Pair> pairs;
        for(auto c : input){
            auto isExistingElement = find(begin(pairs), end(pairs), Pair(c));
            if(isExistingElement != end(pairs)){ //if found
                (*isExistingElement).mOccurrence++;
            }else{
                pairs.push_back(Pair(c));
            }
        }

        //sorting 
        sort(begin(pairs), end(pairs), [](const Pair &a, const Pair &b){
            if(a.mOccurrence != b.mOccurrence){
                return a.mOccurrence < b.mOccurrence;
            }else{
                return a.mASCIIValue > b.mASCIIValue;
            }
        });

        //printing 
        for(int j = 0; j < sz(pairs); j++){
            cout << pairs[j].mASCIIValue << " " << pairs[j].mOccurrence << "\n";
        }
        presentationChecker = 1;
    }
} 