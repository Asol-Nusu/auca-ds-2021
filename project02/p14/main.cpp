//ACCEPTED
/*
sorts a list of student last names, 
but the sort only uses the first two letters of the name. 
Nothing else in the name is used for sorting. 

However, if two names have the same first two letters, 
they should stay in the same order as in the input
*/
#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 

//stable_sort with lambda expression
int main()
{
    iostream::sync_with_stdio(false); 
    bool firstTime = true;
    int nOfPeople;
    while(cin >> nOfPeople && nOfPeople != 0){
        cin.ignore(10000, '\n');

        if(!firstTime){
            cout << endl;
        }
        vector<string> names;
        string name;
        for(int i = 0; i < nOfPeople; i++){
            getline(cin, name);
            names.push_back(name);
        }

        stable_sort(begin(names), end(names), [](const string &name1, const string &name2)
        {
            string name1Part = name1.substr(0, 2); //pos, length
            string name2Part = name2.substr(0, 2); //pos, length
            return name1Part < name2Part;
        });

        //printing 
        for(auto n : names){
            cout << n << endl;
        }
        firstTime = false;
    }    
} 