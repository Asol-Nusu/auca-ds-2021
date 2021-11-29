#include <stdio.h>

#define N 5
#define M 3

void printArray(int *p, int n){ //address of the 1st element
    for(int i = 0; i < n; i++){
        printf(" %d", p[i]);
    }
    printf("\n");
}

int main(void){
    int a[N];
    int b[M];

    for(int i = 0; i < N; i++){
        scanf("%d", a + i);
    }

    for(int i = 0; i < M; i++){
        scanf("%d", b + i);
    }

    printArray(a, N);
    printArray(b, M);
}