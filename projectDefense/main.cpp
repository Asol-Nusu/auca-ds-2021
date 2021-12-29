#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 

int main()
{
    iostream::sync_with_stdio(false); 
    int nOfWords;
    int nOfJobDescriptions;

    cin >> nOfWords >> nOfJobDescriptions;
    vector<pair<string, int>> dictionary;

    for(int i = 0; i < nOfWords; i++){
        string word;
        int salary;
        cin >> word >> salary;
        dictionary.push_back(make_pair(word, salary));
    }
    
    sort(begin(dictionary), end(dictionary), [](const pair<string, int> &w1, const pair<string, int> &w2)
    {
        return w1.first < w2.first;
    });
    //by job name

    for(int i = 0; i < nOfJobDescriptions; i++){
        int totalSalary = 0;
        string input;
        while(cin >> input && input != "."){
            auto found = lower_bound(begin(dictionary), end(dictionary), input, [](const pair<string, int> &w1, const pair<string, int> &w2)
            {
                return w1.first < w2.first;
            });

            if(found != end(dictionary)){
                totalSalary += (*found).second;
            }
        }

        cout << totalSalary << "\n";
    }
} 