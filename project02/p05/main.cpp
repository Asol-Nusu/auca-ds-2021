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
    vector<Pair> pairs;

    string input;
    while(getline(cin, input)){
        //Working on a string input
        for(int i = 0; i < (int)input.length(); i++){
            char character = input.at(i);
           
            auto isExistingElement = find(begin(pairs), end(pairs), Pair(character));
            if(isExistingElement != end(pairs)){ //if found
                (*isExistingElement).mOccurrence++;
            }else{
                pairs.push_back(Pair(character));
            }

            //sorting 
            sort(begin(pairs), end(pairs), [](const Pair &a, const Pair &b){
                if(a.mASCIIValue != b.mASCIIValue){
                    return a.mOccurrence < b.mOccurrence;
                }else{
                    return a.mASCIIValue > b.mASCIIValue;
                }
            });

            //printing 
            
        }

        cout << "\n";
    }

} 