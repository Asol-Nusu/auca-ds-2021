/*
sort a group of people by their classes 
to show their true place in the social class hierarchy.

three main classes: upper (2), middle (1), and lower (0).
upper-upper > middle-upper > lower-upper

all of the upper classes (upper-upper, middle-upper, and lower-upper) 
are higher than any of the middle classes.

When comparing classes, once you have reached the lowest level of detail, 
you should assume that all further classes are the same as the middle level of the previous level of detail.

middle-middle-lower-middle == lower-middle
1-1-0-1 == 0-1

upper == middle-upper
1-2 == 2
*/
#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
char convertToSocialClass(const string &sSocialClass){
    if(sSocialClass == "upper"){
        return '0';
    }else if(sSocialClass == "middle"){
        return '1';
    }else{
        return '2';
    }
}
pair<string, string> produceValidValues(string rawInput){
    replace(rawInput.begin(), rawInput.end(), ':', ' ');
    replace(rawInput.begin(), rawInput.end(), '-', ' ');

    istringstream streamInput(rawInput); //Input stream class to operate on strings
    
    string name;
    string socialClass;
    int index = 0; 
    for(string word; streamInput >> word;){
        if(word == "class"){
            continue;
        }
        if(index == 0){
            name = word;
        }else{
            char intSocialClass = convertToSocialClass(word);
            socialClass.push_back(intSocialClass);
        }
        
        index++;
    }
    return make_pair(name, socialClass);
}

void outputEqualSigns(){
    for(int i = 0; i < 29; i++){
        cout << "=";
    }
    cout << "=\n";
}

//use stable_sort, pair<string, string>
int main()
{
    iostream::sync_with_stdio(false); 
    int tests;
    cin >> tests;
    for(int i = 0; i < tests; i++){
        int nOfPeople;
        cin >> nOfPeople;
        cin.ignore(10000, '\n');

        for(int j = 0; j < nOfPeople; j++){
            string rawInput;
            getline(cin, rawInput);

            pair<string, string> person = produceValidValues(rawInput);
            cout << person.first << " " << person.second << "\n";
        }
        //outputEqualSigns();
    }
} 