#pragma once
#include <vector>
#include <iosfwd>
#include <stdexcept>
#include <cctype>
#include <string>
#include <algorithm>

class BigInt{
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    friend BigInt operator+(const BigInt &a, const BigInt &b);
    friend BigInt operator-(const BigInt &a, const BigInt &b);


    std::vector<int> mDigits;
    bool mIsNegative;

    //done
    static int compareAbsValues(const BigInt &a, const BigInt &b){
        //0 is equal, 1 is more, -1 is less
        if(a.mDigits.size() > b.mDigits.size()){
            return 1;
        }else if(a.mDigits.size() < b.mDigits.size()){
            return -1;
        }else{
            //if equal: 123 and 999, 999 and 123, 222 and 222

            for(size_t i = 0; i < a.mDigits.size(); i++){
                if(a.mDigits[i] != b.mDigits[i]){
                    return a.mDigits[i] - b.mDigits[i];
                }
            }

            //if it reached this, it's equal
            return 0;
        }
    }

    //done
    static BigInt addAbsValues(const BigInt &a, const BigInt &b){
        BigInt r;
        r.mDigits.clear();

        auto i = a.mDigits.rbegin();
        auto j =  b.mDigits.rbegin();

        int carry = 0;

        //digit by digit 
        while(i != a.mDigits.rend() || j != b.mDigits.rend()){
            int sum = carry;

            if(i != a.mDigits.rend()){
                 sum += *i;
                 i++;
            }

            if(j != b.mDigits.rend()){
                sum += *j;
                j++;
            }
            r.mDigits.push_back(sum % 10);
            carry = sum / 10;
        }

        if(carry != 0){
            r.mDigits.push_back(carry);
        }

        std::reverse(r.mDigits.begin(), r.mDigits.end()); //в нормальное состояние привести
        return r;
    }
   
   //done
    static BigInt subtractAbsValues(const BigInt &a, const BigInt &b){
        // It's guaranteed that always a > b
        BigInt r;
        r.mDigits.clear();

        auto i = a.mDigits.rbegin(); //last element
        auto j =  b.mDigits.rbegin(); //last element

        int borrow = 0;
        while(i != a.mDigits.rend()){
            int subtractionResult = *i - borrow;
            i++;

            if(j != b.mDigits.rend()){
                subtractionResult -= *j;
                j++;
            }

            if(subtractionResult < 0){
                subtractionResult += 10;
                borrow = 1;
            }else{
                borrow = 0;
            }

            r.mDigits.push_back(subtractionResult);
        }

        while(r.mDigits.size() > 1 && r.mDigits.back() == 0){
            r.mDigits.pop_back();
        }

        std::reverse(r.mDigits.begin(), r.mDigits.end()); //в нормальное состояние привести
        return r;
    }

public:
    //done
    BigInt()
        : mIsNegative(false)
    {
        mDigits.push_back(0);
    }

    //done
    BigInt(const std::string &s)
        : mIsNegative(false)
    {
        if(s.empty()){
            throw std::runtime_error("BigInt: empty string");
        }
        size_t i = 0;
        if(s[i] == '+' || s[i] == '-'){
            mIsNegative = s[i] == '-';
            i++;
        }

        while(i != s.size() - 1 && s[i] == '0'){
            //Leading Zeros
            i++;
        }

        while(i < s.size()){
            if(!isdigit(s[i])){
                throw std::runtime_error("BigInt: incorrect string");
            }
            mDigits.push_back(s[i] - '0');
            i++;
        }
        if(mDigits.empty()){ //no digits were assigned 
            throw std::runtime_error("BigInt: incorrect string");
        }

        if(mDigits.size() == 1 && mDigits.front() == 0){
            //-0 or +0
            mIsNegative = false;
        }
    }

    //Constructor Delegation
    //done
    BigInt(long long x)
        : BigInt(std::to_string(x))
    {
    }
};
 
//done  
inline std::ostream &operator<<(std::ostream &out, const BigInt &x){
    if(x.mIsNegative){
        out << '-';
    }

    for(auto digit : x.mDigits){
        out << digit;
    }

    return out;
}

inline BigInt operator+(const BigInt &a, const BigInt &b){
    if(a.mIsNegative == b.mIsNegative){ // a + b or -a + (-b)
        BigInt r = BigInt::addAbsValues(a, b);
        r.mIsNegative = a.mIsNegative;
        return r;
    }

    int compare = BigInt::compareAbsValues(a, b);
    if(compare == 0){
        return BigInt();
    }
    if(compare > 0){
        //if a > b
        BigInt r = BigInt::subtractAbsValues(a, b); // a + (-b)
        r.mIsNegative = a.mIsNegative;
        return r;
    }else if(compare < 0){
        //if b > a
        BigInt r = BigInt::subtractAbsValues(b, a); // b + (-a)
        r.mIsNegative = b.mIsNegative;
        return r;
    }
}

// inline BigInt operator-(const BigInt &a, const BigInt &b){
//     BigInt r = BigInt::subtractAbsValues(a, b);
//     return r;
// }