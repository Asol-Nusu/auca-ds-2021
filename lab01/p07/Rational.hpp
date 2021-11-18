#pragma once
#include <iosfwd>
#include <stdexcept>
#include <cctype>

template<typename T>
class Rational{
    T mNumerator;
    T mDenominator;

    public:
    Rational()
        : mNumerator(0), mDenominator(1)
    {
    }

    Rational(const T &num, const T &den) //no copies, no changes
        : mNumerator(num), mDenominator(den)
    {
        if(mDenominator == 0){
            throw std::runtime_error("Rational: denominator is zero");
        }

        //Finding GCD (working w/ positive values)
        T a = mNumerator < 0 ? -mNumerator : mNumerator;
        T b = mDenominator < 0 ? -mDenominator : mDenominator;
        while(b != 0){
            T remainder = a % b;
            a = b;
            b = remainder;
        }

        mNumerator /= a;
        mDenominator /= a;

        //Keeping a negative sign in the numerator
        if(mDenominator < 0){
            mNumerator *= -1;
            mDenominator *= -1;
        }
    }
    const T &numerator() const{
        return mNumerator;
    }
    const T &denominator() const{
        return mDenominator;
    }
};


template<typename T>
Rational<T> operator+(const Rational<T> &a, const Rational<T> &b){
    T num = a.numerator() * b.denominator() + b.numerator() * a.denominator();
    T den = a.denominator() * b.denominator();

    return Rational<T>(num, den);
}

template<typename T>
Rational<T> operator-(const Rational<T> &a, const Rational<T> &b){
    T num = a.numerator() * b.denominator() - b.numerator() * a.denominator();
    T den = a.denominator() * b.denominator();

    return Rational<T>(num, den);
}
template<typename T>
Rational<T> operator*(const Rational<T> &a, const Rational<T> &b){
    T num = a.numerator() * b.numerator();
    T den = a.denominator() * b.denominator();

    return Rational<T>(num, den);
}
template<typename T>
Rational<T> operator/(const Rational<T> &a, const Rational<T> &b){
    T num = a.numerator() * b.denominator();
    T den = a.denominator() * b.numerator();

    return Rational<T>(num, den);
}

template<typename T>
bool operator<(const Rational<T> &a, const Rational<T> &b){
    return a.numerator()*b.denominator() < b.numerator()*a.denominator();
}

template<typename T>
bool operator>(const Rational<T> &a, const Rational<T> &b){
    //a > b <=> b < a
    return b < a;
}

template<typename T>
bool operator<=(const Rational<T> &a, const Rational<T> &b){
    return a < b || a == b;
    //!(a > b)
}

template<typename T>
bool operator>=(const Rational<T> &a, const Rational<T> &b){
    return a > b || a == b;
    //!(a > b)
}

template<typename T>
bool operator==(const Rational<T> &a, const Rational<T> &b){
    return a.numerator() * b.denominator() == b.numerator() * a.denominator();
}

template<typename T>
bool operator!=(const Rational<T> &a, const Rational<T> &b){
    return !(a == b);
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const Rational<T> &r){
    out << r.numerator() << "/" << r.denominator();  

    return out;
}

template<typename T>
std::istream &operator>>(std::istream &inp, Rational<T> &r){
    T num;
    if(!(inp >> num)){
        return inp;
    }
    
    char ch;
    if(!inp.get(ch)){ //no skipping spaces
        return inp;
    }

    if(ch != '/'){
        inp.setstate(std::ios_base::failbit);
        return inp;
    }

    if(!inp.get(ch)){
        return inp;
    }
    if(ch == '+' || ch == '-' || isdigit(ch)){
        inp.putback(ch);
    }else{
        inp.putback(ch);
        inp.setstate(std::ios_base::failbit);
        return inp;
    }

    T den;
    if(!(inp >> den)){
        return inp;
    }
    r = Rational<T>(num, den);
    return inp;
}