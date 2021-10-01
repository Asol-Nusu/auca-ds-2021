#include <bits/stdc++.h> //include all the headers of C++ library  

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std; //to avoid repetition

int main()
{
    iostream::sync_with_stdio(false); //faster 

    int a;
    int b;
    while(cin >> a >> b){
        cout << a + b << "\n";
    }
}