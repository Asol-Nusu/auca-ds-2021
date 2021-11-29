#pragma once
#include <vector>
#include <iosfwd>
#include <stdexcept>
#include <cctype>

class BigInt{
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    std:: vector<int> mDigits;
    bool mIsNegative;

static BigInt addAbsValues(const BigInt &a, const BigInt &b){
    BigInt r;
    r.mDigits.clear();
    // endIterator of a, endInterator of b
}
public:
    BigInt()
        : mIsNegative(false)
    {
        mDigits.push_back(0);
    }

    BigInt(const string &s)
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
                throw runtime_error("BigInt: incorrect string");
            }
            mDigits.push_back(s[i] - '0');
            i++;
        }
        if(mDigits.empty()){ //no digits were assigned 
            throw runtime_error("BigInt: incorrect string");
        }
    }
};

inline 
std::ostream &operator<<(std::ostream &out, const BigInt &x){
    if(x.mIsNegative){
        out << '-';
    }

    for(auto digit : x.mDigits){
        out << digit;
    }

    return out;
}
