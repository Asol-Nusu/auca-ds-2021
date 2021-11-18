#include <bits/stdc++.h>  
template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
int sumOfLetters(const string &line){
    int subtrahend = 96; //ASCII value of 'a' is 97
    int nameValue = 0;
    for(auto ch : line){
        if(isalpha(ch)){
            nameValue += int(tolower(ch)) - subtrahend;
        }
    }

    return nameValue;
}

int sumOfDigits(const int &number){
    string sNumber = to_string(number);
    int sum = 0;
    for(auto ch : sNumber){
        sum += int(ch) - 48; //ASCII value of '0' is 48
    }
    
    return sum;
}
int findSum(const int &nameValue){
    int sum = sumOfDigits(nameValue);
    while(sum >= 10){
        sum = sumOfDigits(sum);
    }

    return sum;
}

int main()
{
    iostream::sync_with_stdio(false);
    string line1; 
    string line2;

    while(getline(cin, line1), getline(cin, line2)){
        int person1NameValue = sumOfLetters(line1);
        int person2NameValue = sumOfLetters(line2);

        int person1Sum = findSum(person1NameValue);
        int person2Sum = findSum(person2NameValue);

        if(person2Sum < person1Sum){
            swap(person1Sum, person2Sum);
        }
        cout << fixed << setprecision(2) << ((double)person1Sum) * 100.0 / ((double)person2Sum)<< " %\n";
    }
}