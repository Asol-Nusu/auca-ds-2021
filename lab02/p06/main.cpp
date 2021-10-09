#include <bits/stdc++.h> 
//ACCEPTED 
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

    for(int test = 0; test < tests; ++test){
        int one, two, three;
        cin >> one >> two >> three;
        int maxSalary = max(max(one, two), three);
        int minSalary = min(min(one, two), three);
        
        int employees [3] = {one, two, three};
        for(int i = 0; i < 3; i++){
            if(employees[i] > minSalary && employees[i] < maxSalary){
                cout << "Case " << test + 1 << ": " << employees[i] << endl;
            }
        }
    }
} 