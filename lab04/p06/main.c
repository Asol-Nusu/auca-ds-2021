#include <stdio.h>
#include "VecInt.h"
void printArray(int *beg, int *end){
    while(beg != end){
        printf(" %d", *beg++);
    }
    printf("\n");
}

void reverse(int *beg, int *end){
    for(;;){
        if(beg == end){
            break;
        }
        --end;

        if(beg == end){
            break;
        }

        int t = *beg;
        *beg = *end;
        *end = t;

        ++beg;
    }
}

void p01(){
    printf("the size of the array: ");
    int n;
    scanf("%d", &n);

    struct VecInt v;
    VecInt_createOfSize(&v, n, 0 );

    for(int i = 0; i < n; i++){
        scanf("%d", &v.data[i]);
    }
    
    reverse(v.data, v.data + n);
    printArray(v.data, v.data + n);
    
    VecInt_destroy(&v);
}

void p02(){
    struct VecInt v;
    VecInt_createEmpty(&v);

    int x;
    while(scanf("%d", &x) == 1){
        //v.push_back(x);
        VecInt_pushBack(&v, x);
    }

    printArray(v.data, v.data + v.size);
    reverse(v.data, v.data + v.size);
    printArray(v.data, v.data + v.size);
    
    VecInt_destroy(&v);//free(data);
}

int main(void){    
    p02();
    return 0;
}