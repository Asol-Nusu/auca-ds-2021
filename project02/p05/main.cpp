#include <bits/stdc++.h> 
 
template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 

int main()
{
    iostream::sync_with_stdio(false); 
    // b > a = 1 true
    //a > b = 0 false

    char c1 = 'a';
    char c2 = 'b';
    bool r = c1 > c2;
    cout << r;

} 