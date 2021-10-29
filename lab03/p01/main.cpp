//10205
#include <bits/stdc++.h>
template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std;

//functions
vector<int> createDeck();
void printDeck(const vector<int> &deck);
vector<vector<int>> readShuffles();

int main(){
    iostream::sync_with_stdio(false); 

    int tests;
    cin >> tests;
    for(int i = 0; i < tests; i++){
        auto shuffles = readShuffles();

        for(string line; getline(cin, line) && !line.empty();){
            int m = stoi(line);
            cout << m << endl;
            //applyShuffleToDeck(shuffle, deck[m - 1]);
        }
    }
    // auto deck = createDeck();
    // printDeck(deck);
}

void printDeck(const vector<int> &deck){
    vector<string> ranks = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    vector<string> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
    for(auto card : deck){
        cout << ranks[card % 13] << " of " << suits[card/13] << endl;
    }
}
vector<int> createDeck(){
    vector<int> deck(52);
    for(int i = 0; i < 52; i++){
        deck[i] = i;
    }

    return deck;
}
vector<vector<int>> readShuffles(){
    int n;
    cin >> n;

    vector<vector<int>> result(n, vector<int>(52));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 52; j++){
            cin >> result[i][j];
        }
    }

    cin.ignore(1024, '\n');
    return result;
}