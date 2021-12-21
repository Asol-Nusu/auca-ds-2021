#ifndef VECINT_HPP
#define VECINT_HPP

#include <cstddef>
#include <iostream>

#ifdef AUCA_DEBUG
    #include  <string>
#endif 
using namespace std;

class VecInt{
    int *data;
    size_t size;
    size_t capacity;

public:
    using Iter = int*;
    using CIter = const int*;
    VecInt()
        : data(nullptr), size(0), capacity(0)
    {
    }

    ~VecInt(){
        cout << "~VecInt: " << size << " integers released" << endl;
        delete[] data;
    }

    size_t size_f() const {
        //size()
        return size;
    }
    //void VecInt_createOfSize(struct VecInt *self, size_t size, int initValue);
    Iter begin(){
        return data;
    }
    CIter begin() const{
        return data;
    }

    Iter end(){
        return data + size;
    }
    CIter end() const{
        return data + size;
    }

    int &operator[](size_t index) const {
    #ifdef AUCA_DEBUG
        if(index >= size){
            throw runtime_error("vectInt: incorrect index: " + to_string(index));
        }
    #endif
        return data[index];
    }
    void pushBack(int x);    
}; 

#endif

    