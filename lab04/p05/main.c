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
    //vector<int> v;
    int *data = NULL; //doesn't point to anything
    size_t size = 0;
    size_t capacity = 0;

    int x;
    while(scanf("%d", &x) == 1){
        //v.push_back(x);
        if(size == capacity){
            capacity = (capacity == 0) ? 1 : 2 * capacity;
            int *newData = (int *)malloc((sizeof(int) * capacity)); //int: 4 bytes
            for(size_t i = 0; i < size; i++){
                newData[i] = data[i]; 
            }
            free(data);
            data = newData;
        }
        data[size++] = x;
    }

    printArray(data, data + size);
    reverse(data, data + size);
    printArray(data, data + size);
    
    free(data);    
}