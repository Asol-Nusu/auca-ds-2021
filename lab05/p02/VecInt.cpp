#include "VecInt.hpp"
VecInt::VecInt(const VecInt &other)
    : data(new int[other.capacity]), size(other.size), capacity(other.capacity)
{
    for(size_t i = 0; i < size; i++){
        data[i] = other.data[i] ;
    }
}

VecInt &VecInt::operator=(const VecInt &other){
    if(&other != this){
        int* newData = new int[other.capacity];
        for(size_t i = 0; i < other.size_f(); i++){
            newData[i] = other.data[i];
        } 

        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = newData;
    }

    return *this;
}
void VecInt::pushBack(int x){
    if(size == capacity){
        capacity = (capacity == 0) ? 1 : 2 * capacity;
        int *newData = new int[capacity];
        for(size_t i = 0; i < size; i++){
            newData[i] = data[i]; 
        }
        delete[] data;
        data = newData;
    }
    data[size++] = x;
} 

bool operator==(const VecInt &a, const VecInt &b){
    if(a.size_f() != b.size_f()){
        return false;
    }

    for(size_t i = 0; i < a.size_f(); i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}

bool operator!=(const VecInt &a, const VecInt &b){
    return !(a == b);
}
