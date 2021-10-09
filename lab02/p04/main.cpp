#include <bits/stdc++.h> 
//ACCEPTED
template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std; 
char tensDigit(int number){ 
    string str = to_string(number);
    char answer = str.at(str.length() - 2);

    //обязательно двузначное или больше
    return answer;
}

int main()
{
    iostream::sync_with_stdio(false); 
    int tests;
    cin >> tests; //1 ≤ t ≤ 100
    for(int i = 0; i < tests; ++i){
        int number;
        cin >> number;
        int result = abs((number*567/9 + 7492)*235/47-498);

        cout << tensDigit(result) << "\n";
    }

} 