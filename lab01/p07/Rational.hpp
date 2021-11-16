#pragma once
#include <iosfwd>

template<typename T>
class Rational{
    T mNumerator;
    T mDenominator;

    public:
    Rational()
        : mNumerator(0), mDenominator(1)
    {
    }

    const T &num() const{
        return mNumerator;
    }
    const T &den() const{
        return mDenominator;
    }
};

template<typename T>
std::ostream &operator<<(std::ostream &out, const Rational<T> &r){
    out << r.num() << "/" << r.den();  

    return out;
}