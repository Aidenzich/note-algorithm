#include<stdio.h>
#include <math.h>
int *poly(int*, int*, int*);

// void poly(int*, int*, int*);
int main() {
    int a, b, c;
    int *A, *B, *C;
    scanf("%d %d %d", &a, &b, &c);
    A = &a;
    B = &b;
    C = &c;
    if (a < 0) A = NULL;
    if (b < 0) B = NULL;
    if (c < 0) C = NULL;

    poly(A,B, C);
    // int *result = poly(A, B, C);
    // printf("%d", *result);
    return 0;
}

int *poly(int *A, int *B, int *C) {
    int a=0, b=0, c=0;
    if (A != NULL){
        a = pow(*A, 3);
    }
    if (B != NULL){
       b = pow(*B, 2); 
    }
    if (C != NULL){
        c = *C;
    }
    int result = a+b+c;    
    int *result_pointer = &result;
    return result_pointer;
}