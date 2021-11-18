//ACCEPTED
#include <bits/stdc++.h>   
template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}
using namespace std; 

vector<string> songWords = {"Happy", "birthday", "to", "you", 
"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

int main()
{
    iostream::sync_with_stdio(false); 
    int nOfPeople;
    cin >> nOfPeople;
    vector<string> people = vector<string>(nOfPeople);
    for(int i = 0; i < nOfPeople; i++){
        cin >> people[i];
    }

    bool everyoneSang = false;
    int singerIndex = 0;

    while(!everyoneSang){
        for(int i = 0; i < 16; i++){
            cout << people[singerIndex] << ": " << songWords[i] << "\n";
            singerIndex++;
            if(singerIndex == nOfPeople){
                everyoneSang = true;
                singerIndex = 0;
            }
        }
    }
} 