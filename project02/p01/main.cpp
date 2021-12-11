#include <bits/stdc++.h> 
#include <algorithm>  
#include <vector> 

template <typename C>
int sz(const C &c) { 
    return static_cast<int>(c.size()); 
}

using namespace std;

class MyFunctor{
    int operator () (int num1, int num2) const {
       return ;
   }
};

//Отсортировать числа по возрастанию их остатков при делении на М
int main()
{
    iostream::sync_with_stdio(false); 
    int n;
    int divider;

    cin >> n >> divider;
    while(n != 0 && divider != 0){
        vector<int> numbers = vector<int>(n);

        for(int i = 0; i < n; i++){
            int number;
            cin >> number;
            numbers.push_back(number);
        }

        sort(begin(numbers), end(numbers), [divider](int num1, int num2){
            int result1 = num1 % divider;
            int result2 = num2 % divider;

            if(result1 != result2){
                return result1 < result2;  //if r1 < r2 (true), num1 will go first            
            }else{
                if(num1 % 2 == 1 && num2 % 2 == 0){
                    return true;
                }else if(num1 % 2 == 0 && num2 % 2 == 1){
                    return false;
                }

                if(num1 % 2 == 1 && num2 % 2 == 1){
                    return num1 > num2;
                }
            }
        });

        cin >> n >> divider;
    }
} 