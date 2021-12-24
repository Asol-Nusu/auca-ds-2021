#ifndef VECINT_H
#define VECINT_H

#include <stddef.h>

struct VecInt{
    int *data;
    size_t size;
    size_t capacity;
}; 
void VecInt_createOfSize(struct VecInt *self, size_t size, int initValue);
void VecInt_createEmpty(struct VecInt *self); //self == this
void VecInt_pushBack(struct VecInt *self, int x);
void VecInt_destroy(struct VecInt *self);
#endif
 