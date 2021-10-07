#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main(){
    for(string line; getline(cin, line);){
        string buff; 
        for(auto c : line){
            if(isalpha(c)){ //omit puntuation, space and other marks
                buff += tolower(c);
            }
        }

        // value semantics 
        string temp = buff;
        reverse(temp.begin(), temp.end());

        cout << (buff == temp ? "palindrome\n" : "not a palindrome\n");
    }
}