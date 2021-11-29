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
    
    std:: vector<int> mDigits;
    bool mIsNegative;

    static BigInt addAbsValues(const BigInt &a, const BigInt &b){
        BigInt r;
        r.mDigits.clear();

        auto i = a.mDigits.rbegin();
        auto j =  b.mDigits.rbegin();

        int carry = 0;

        while(i != a.mDigits.rend() || j != b.mDigits.rend()){
            int sum = carry;

             if(i != a.mDigits.rend() ){
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
        std::reverse(r.mDigits.begin(), r.mDigits.end());
        return r;
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
    if(a.mIsNegative == b.mIsNegative){
        BigInt r = BigInt::addAbsValues(a, b);
        r.mIsNegative = a.mIsNegative;
        return r;
    }
    throw std::runtime_error("not implemented yet");
}