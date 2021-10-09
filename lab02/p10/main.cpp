//ACCEPTED
#include <bits/stdc++.h> 
 
template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 

int main()
{
    iostream::sync_with_stdio(false); 
    int tests;
    cin >> tests;

    for(int i = 0; i < tests; ++i){
        int walls;
        cin >> walls;
        
        int lows = 0;
        int highs = 0;
        
        int currentWall;
        cin >> currentWall;
        for(int j = 1; j < walls; ++j){
            int nextWall;
            cin >> nextWall;

            if(nextWall > currentWall){
                highs++;
            }else if(nextWall < currentWall){
                lows++;
            }
            currentWall = nextWall;
        }

        cout << "Case " << i + 1 << ": " << highs << " " << lows << endl;
    }
} 