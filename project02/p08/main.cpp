#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
string case1Func(const vector<int> &numbers){
    for(int i = 0; i < (int)numbers.size(); i++){
        for(int j = i + 1; j < (int)numbers.size(); j++){
            if((numbers[i] != numbers[j]) && (numbers[i] + numbers[j] == 7777)){
                return "Yes\n";
            }
        }
    }

    return "No\n";
}

int main()
{
    iostream::sync_with_stdio(false); 
    int nOfIntegers;
    int actionNumber;
    cin >> nOfIntegers >> actionNumber;

    vector<int> numbers;
    for(int i = 0; i < nOfIntegers; i++){
        int input;
        cin >> input;
        numbers.push_back(input);
    }

    switch(actionNumber){
        case 1:
        cout << case1Func(numbers);
        break;

        case 2:
        //smth
        break;

        case 3:
        //smth
        break;

        case 4:
        //smth
        break;

        case 5:
        //smth
        break;
    }
} 