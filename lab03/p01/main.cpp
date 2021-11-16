/*
UVA 10205
52 cards = 4 suits * 13

Clubs, Diamonds, Hearts, Spades
2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace
*/

#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std;

//Function Prototypes
vector<int> createDeck();
void printDeck(const vector<int> &deck); //no copies & no changes (const)
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

vector<int> createDeck(){
    vector<int> deck(52);
    for(int i = 0; i < 52; i++){
        deck[i] = i;
    }

    return deck;
}

void printDeck(const vector<int> &deck){
    static vector<string> values = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    static vector<string> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
    for(auto card : deck){
        cout << values[card % 13] << " of " << suits[card/13] << endl;
    }
}

vector<vector<int>> readShuffles(){
    int nOfShuffles;
    cin >> nOfShuffles;

    vector<vector<int>> result(nOfShuffles, vector<int>(52));

    for(int i = 0; i < nOfShuffles; i++){
        for(int j = 0; j < 52; j++){
            cin >> result[i][j];
        }
    }

    cin.ignore(1024, '\n'); //a tricky thing to read input correctly
    return result;
}