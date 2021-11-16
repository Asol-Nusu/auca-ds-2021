#include <iostream>
#include <utility>
using namespace std;

template <typename T>
void auSwap(T &x, T &y){
    T t = x;
    x = y;
    y = t;
}

void badSwap(int x, int y){
    int temp = x;
    x = y;
    y = temp;
}

void goodSwap01(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

void goodSwap02(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int main(){
    cout << "1st int: ";
    int a;
    cin >> a;

    cout << "2nd int: ";
    int b;
    cin >> b;

    cout << "std::swap:\n";
    cout << "Before swap a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After swap a = " << a << ", b = " << b << endl;

    cout << "badSwap:\n";
    cout << "Before swap a = " << a << ", b = " << b << endl;
    badSwap(a, b); //it actually doesn't do what it's supposed to do
    cout << "After swap a = " << a << ", b = " << b << endl;

    cout << "goodSwap01:\n";
    cout << "Before swap a = " << a << ", b = " << b << endl;
    goodSwap01(&a, &b);
    cout << "After swap a = " << a << ", b = " << b << endl;

    cout << "goodSwap02:\n";
    cout << "Before swap a = " << a << ", b = " << b << endl;
    goodSwap02(a, b);
    cout << "After swap a = " << a << ", b = " << b << endl;

    cout << "general swap for doubles:\n";
    double d1 = 2.34;
    double d2 = 1.45;
    cout << "Before swap d1 = " << d1 << ", d2 = " << d2 << endl;
    auSwap(d1, d2);
    cout << "After swap d1 = " << d1 << ", d2 = " << d2 << endl;

    cout << "general swap for strings:\n";
    string s1 = "hello";
    string s2 = "world";
    cout << "Before swap s1 = " << s1 << ", s2 = " << s2 << endl;
    auSwap(s1, s2);
    cout << "After swap s1 = " << s1 << ", s2 = " << s2 << endl;
}