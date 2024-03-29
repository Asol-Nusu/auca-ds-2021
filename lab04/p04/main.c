#include <stdio.h>
#include <stdlib.h>

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

int main(void){
    printf("the size of the array: ");
    int n;
    scanf("%d", &n);

    int *const dynamicArray = (int *)malloc(n * sizeof(int));
    if(dynamicArray == NULL){
        printf("Not enough memory");
        exit(1);
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &dynamicArray[i]);
    }
    
    reverse(dynamicArray, dynamicArray + n);

    printArray(dynamicArray, dynamicArray + n);
    free(dynamicArray);
}