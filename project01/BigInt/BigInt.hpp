#pragma once
#include <vector>
#include <iosfwd>

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
