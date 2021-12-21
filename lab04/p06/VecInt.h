#ifndef VECTINT_H
#define VECTINT_H
#include <stddef.h>
struct VecInt{
    int *data;
    size_t size;
    size_t capacity;
}; 
void VecInt_createEmpty(struct VecInt *self); //self == this
#endif

 