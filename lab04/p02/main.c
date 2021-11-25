#include <stdio.h>
#define N 10

int main(void){
    int a[N];

    for(int i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }

    printf("values of array:\n");
    for(int i = 0; i < N; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += a[i];
    }
    printf("Sum of elements: %d\n", sum);

    //another method of solving the problem
    int sum2 = 0;
    for(int *p = a; p != a + N; ++p){
        sum2 += *p;
    }
    printf("[second method] Sum of elements: %d\n", sum);
} 