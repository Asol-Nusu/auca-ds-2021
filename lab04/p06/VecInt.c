#include "VecInt.h"
#include <stdlib.h>

void VecInt_createEmpty(struct VecInt *self){
     self->data = NULL;
     self->capacity = 0;
     self->data = 0;
}
void VecInt_pushBack(struct VecInt *self, int x){
     if(self->size == self->capacity){
          self->capacity = (self->capacity == 0) ? 1 : 2 * self->capacity;
          int *newData = (int *)malloc((sizeof(int) * self->capacity)); //int: 4 bytes
          for(size_t i = 0; i < self->size; i++){
               newData[i] = self->data[i]; 
          }
          free(self->data);
          self->data = newData;
     }
     self->data[self->size++] = x;
}
 
void VecInt_destroy(struct VecInt *self){
     free(self->data);
     self->size = 0;
     self->capacity = 0;
}