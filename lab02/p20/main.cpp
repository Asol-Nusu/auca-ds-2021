/*
Money is evenly divided between receivers
Dave -> 200
- 198 (x66)
+ 500
= 302

Owen 
- 500
+ 66
+ 75
= -359

Amr
- 150

Laura
+66

*/
#include <bits/stdc++.h> 
  
template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
    
}

using namespace std; 
void assignReceiversWallets(const vector<string> &people, vector<int> &peopleWallets,  const vector<string> &receivers, const int &receivingMoney, const int &nOfPeople, const int &nOfReceivers){
    for(int r = 0; r < nOfReceivers; r++){
        for(int p = 0; p < nOfPeople; p++){
            if(receivers[r] == people[p]){
                peopleWallets[p] += receivingMoney;
            }
        }
    }
}
void assignGiverWallet(const vector<string> &people, vector<int> &peopleWallets, const string &giver, const int &totalLoss, const int &nOfPeople){
    for(int p = 0; p < nOfPeople; p++){
        if(giver == people[p]){
            peopleWallets[p] -= totalLoss;
        }
    }
}

void printResults(const vector<string> &people, const vector<int> &peopleWallets, const int &nOfPeople){
    for(int i = 0; i < nOfPeople; i++){
        cout << people[i] << " " << peopleWallets[i] << "\n";
    }
}

int main()
{
    iostream::sync_with_stdio(false); 
    int nOfPeople;
    while(cin >> nOfPeople){
        vector<string> peopleNames = vector<string>(nOfPeople);
        vector<int> peopleWallets = vector<int>(nOfPeople);
    
        for(int i = 0; i < nOfPeople; i++){
            cin >> peopleNames[i];
        }
        
        for(int i = 0; i < nOfPeople; i++){
            string giver;
            int money;
            int nOfReceivers;

            cin >> giver >> money >> nOfReceivers;
            vector<string> receivers = vector<string>(nOfReceivers);
            for(int j = 0; j < nOfReceivers; j++){
                cin >> receivers[j];
            }
            if(nOfReceivers != 0){
                int receivingMoney = money / nOfReceivers;
                int totalLoss = nOfReceivers * receivingMoney;
                assignReceiversWallets(peopleNames, peopleWallets, receivers, receivingMoney, nOfPeople, nOfReceivers);
                assignGiverWallet(peopleNames, peopleWallets, giver, totalLoss, nOfPeople);
            }
        }
        printResults(peopleNames, peopleWallets, nOfPeople);
        
        cout << "\n";
    }
}