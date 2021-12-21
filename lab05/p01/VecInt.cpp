#include "VecInt.hpp"

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