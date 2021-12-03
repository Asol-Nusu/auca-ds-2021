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


    std:: vector<int> mDigits;
    bool mIsNegative;

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
    static int compareAbsValues(const BigInt &a, const BigInt &b){
        //0 is equal, 1 is more, -1 is less
        if(a.mDigits.size() > b.mDigits.size()){
            return 1;
        }else if(a.mDigits.size() < b.mDigits.size()){
            return -1;
        }else{
            //if equal: 123 and 999, 999 and 123, 222 and 222

            for(int i = 0; i < a.mDigits.size(); i++){
                if(a.mDigits[i] > b.mDigits[i]){
                    return 1;
                }else if(a.mDigits[i] < b.mDigits[i]){
                    return -1;
                }
            }

            //if it reached this, it's equal
            return 0;
        }
    }

    public:
    static BigInt subtractAbsValues(const BigInt &a, const BigInt &b){
        // It's guaranteed that always a > b
        BigInt r;
        r.mDigits.clear();

        auto i = a.mDigits.rbegin(); //last element
        auto j =  b.mDigits.rbegin(); //last element

        int borrow = 0;
        int subtractionResult;
        while(j != b.mDigits.rend()){
            if(*i >= *j){
                subtractionResult = *i - *j - borrow;
                borrow = 0;
            }else{
                subtractionResult = 10 + *i - *j - borrow;
                borrow = 1;
            }
            r.mDigits.push_back(subtractionResult);

            j++;
            i++;
        }

        //finish pushing
        for(;i <= a.mDigits.rend(); i++){
            //digit and borrow 
            if((*i - borrow) < 0){
                subtractionResult = 10 + *i - borrow;
                borrow = 1;
            }else{
                subtractionResult = *i - borrow;
                borrow = 0;
            }
            r.mDigits.push_back(subtractionResult);
        }

        std::reverse(r.mDigits.begin(), r.mDigits.end()); //в нормальное состояние привести
        return r;
        /*
        TODO: removing leading zeros
        */
    }

public:
    BigInt()
        : mIsNegative(false)
    {
        mDigits.push_back(0);
    }

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
    }

    //Constructor Delegation
    BigInt(long long x)
        : BigInt(std::to_string(x))
    {
    }
};
 
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
    /*
    I)
    a + b
    -a + (-b)

    II)
    a + (-b)
    -a + b
    */

   //I)
    if(a.mIsNegative == b.mIsNegative){ // a + b or -a + (-b)
        BigInt r = BigInt::addAbsValues(a, b);
        r.mIsNegative = a.mIsNegative;
        return r;
    }

    //II)
    if(BigInt::compareAbsValues(a, b) == 1){
        //if a > b
        BigInt r = BigInt::subtractAbsValues(a, b); // a - b
        r.mIsNegative = a.mIsNegative;
        return r;
    }else{
        //if b > a
        BigInt r = BigInt::subtractAbsValues(b, a); // b - a
        r.mIsNegative = b.mIsNegative;
        return r;
    }
}

inline BigInt operator-(const BigInt &a, const BigInt &b){

}