//ACCEPTED
#include <bits/stdc++.h> 
/*
10 web pages an integer-valued relevance.
The most related page will be chosen. 
If there is a tie, all the pages with the highest relevance 
are possible to be chosen.
*/ 
template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 

void printWebPages(const vector<string> &webPages, const vector<int> &relevances, const int &maxRelevance){
    for(int i = 0; i < 10; i++){
        if(relevances[i] == maxRelevance){
            cout << webPages[i] << "\n";
        }
    }
}
int main()
{
    iostream::sync_with_stdio(false); 
    int tests;
    cin >> tests;
    for(int i = 1; i <= tests; i++){
        vector<string> webPages = vector<string>(10);
        vector<int> relevances = vector<int>(10);

        int maxRelevance = 0;
        for(int j = 0; j < 10; j++){
            cin >> webPages[j];
            cin >> relevances[j];
            if(relevances[j] > maxRelevance){
                maxRelevance = relevances[j];
            }
        }
        cout << "Case #" << i << ":\n";
        printWebPages(webPages, relevances, maxRelevance);
    }
}