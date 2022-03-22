#include <stdio.h>
#define SIZE 201

void modify_array(int *);

int main(void) {
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    modify_array(&arr[SIZE/2]);
    for (int i = 1; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void modify_array(int *p) {
    int mode = *(p-100);
    // printf("\n%d\n", SIZE/2);
    for (int i=(-99); i<101; ++i){
        int current_idx = SIZE/2 + i - 1;
        if (mode == 1){
            if (current_idx%2 == 0){
                *(p+i) += 10;
            }
        }
        if (mode == 2){
            if (current_idx%3 == 0){
                *(p+i) *= 8;
            }
        }
        if (mode == 3){
            if (current_idx%5 == 0){
                *(p+i) -= 2;
            }
        }
        // printf("%d\n", current_idx);
    }
    
    
    return;
}