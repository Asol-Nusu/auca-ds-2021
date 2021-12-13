#include <bits/stdc++.h> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 

int main()
{
    iostream::sync_with_stdio(false); 
    vector<int> v;
    for(int j = 0; j < 5; j++){
        auto i;
        cin >> i;
        v.push_back(i);
    }

    for(auto e : v){
        cout << e << "\n";
    }
} 