//ACCEPTED
#include <bits/stdc++.h> 
  
template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 

int main(){
    iostream::sync_with_stdio(false); 
    int quoteCounter = 1; //odd - open, even - close 
    for (char c; cin.get(c);) {
        if(c == '"'){
            string answer = (quoteCounter % 2 == 1) ? "``" : "''";
            cout << answer;
            quoteCounter++;
        }else{
            cout.put(c);
        }
    }
} 
/*
``
''
*/