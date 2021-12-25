//ACCEPTED
#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
string case1Func(const vector<int> &numbers){
    for(int number : numbers){
        if(binary_search(begin(numbers), end(numbers), 7777-number)){
            return "Yes\n";
        }
    }

    return "No\n";
}

string case2Func(const vector<int> &numbers){
    for(int i = 0; i < (int)numbers.size(); i++){
        for(int j = 0; j < (int)numbers.size(); j++){
            if (i != j && numbers[i] == numbers[j]){
                return "Contains duplicate\n";
            }
        }
    }

    return "Unique\n";
}

string case3Func(const vector<int> &numbers, int nOfIntegers){
    for(int number : numbers){
        auto lowB = lower_bound(begin(numbers), end(numbers), number);
        auto upB = upper_bound(begin(numbers), end(numbers), number);
        if (lowB != end(numbers) && upB != end(numbers) && (upB - lowB) > nOfIntegers/2)
        {
            return to_string(number) + "\n";
        }
    }
    return "-1\n";
}

void case4Func(const vector<int> &numbers, int nOfIntegers){
    if(nOfIntegers % 2 == 0){
        cout << numbers[sz(numbers)/2 - 1] << " " << numbers[sz(numbers)/2] << "\n";
    }else{
        cout << numbers[sz(numbers) / 2] << "\n";
    }
}

void case5Func(const vector<int> &numbers){
    for(int i = 0; i < sz(numbers); i++){
        bool determine = i != (sz(numbers) - 1);
        string r = determine ? " " : "\n";
        if(numbers[i] >= 100 && numbers[i] <= 999){
            cout << numbers[i] << r;
        }
    }
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

    sort(begin(numbers), end(numbers));
    switch(actionNumber){
        case 1:
        cout << case1Func(numbers);
        break;

        case 2:
        cout << case2Func(numbers);
        break;

        case 3:
        cout << case3Func(numbers, nOfIntegers);
        break;

        case 4:
        case4Func(numbers, nOfIntegers);
        break;

        case 5:
        case5Func(numbers);
        break;
    }
} 

/*
lower_bound returns an iterator pointing to the first element 
in the range [first,last) which has a value equal OR greater than ‘val’. 

upper_bound returns an iterator pointing to the first element 
in the range [first,last) which has a value greater than ‘val’.
*/