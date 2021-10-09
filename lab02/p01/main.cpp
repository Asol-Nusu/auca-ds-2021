//ACCEPTED
#include <bits/stdc++.h> 
#include <algorithm>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
int cycleLength(int number, int itsCycleLength){ 
    ++itsCycleLength;
    if(number == 1){
        return itsCycleLength;
    }
    
    if(number % 2 == 0){
        return cycleLength(number/2, itsCycleLength);
    }else{
        return cycleLength(number*3 + 1, itsCycleLength);
    }
}

int main()
{
    iostream::sync_with_stdio(false);  

    int i;
    int j;

    while(cin >> i >> j){
        int maximum = max(i, j);
        int minimum = min(i, j);
        int maxCycleLength = 0;

        for(int number = minimum; number <= maximum; ++number){
            int itsCycleLength = cycleLength(number, 0);
            if(maxCycleLength < itsCycleLength){
                maxCycleLength = itsCycleLength;
            }
        }

        cout << i << " " << j << " " << maxCycleLength << "\n";
    }
}