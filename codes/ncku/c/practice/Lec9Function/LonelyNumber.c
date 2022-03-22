
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100

int remove_elem(int *arr, int delete_pos, int size){
    int i;
    for (i = delete_pos; i < size; i++) arr[i] = arr[i+1];
    return --size;
}

int remove_elem_by_val(int *arr, int delete_val, int size){    
    // printf("size:%d\n", size);
    if (size != 1){
        int delete_pos = -1;
        for (int i = 0; i < size; ++i){
            if (arr[i] == delete_val){
                delete_pos = i;
                break;
            }
        }
        
        if (delete_pos != -1){
            return remove_elem(arr, delete_pos, size);
        }
    }
    
    
    return size;
}

int compare(const void *a, const void *b){
    int x = *(int*)a;
    int y = *(int*)b;
    return (x > y) - (x < y);
}

int reverse(const void *a, const void *b){
    return -compare(a, b);
}


int find_group(int *arr, int size, bool ascend){
    if (size != 1){
        if (ascend){
            qsort((void *)arr, size, sizeof(arr[0]), compare);
        } else {
            qsort((void *)arr, size, sizeof(arr[0]), reverse);
        }
        
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                if (j==i) continue;
                
                int tmp = arr[i] + arr[j];
                for (int x=0; x<size; x++){
                    if (x==i || x==j) continue;
                    
                    if (arr[x] == tmp){

                        // printf("Found! %d %d %d", arr[i], arr[j], arr[x]);
                        int del1= arr[i], del2= arr[j], del3=arr[x];
                        size = remove_elem_by_val(arr, del1, size);
                        // printf("size:%d delete: %d\n", size, del1);
                        size = remove_elem_by_val(arr, del2, size);
                        // printf("size:%d delete: %d\n", size, del2);
                        size = remove_elem_by_val(arr, del3, size);
                        // printf("size:%d delete: %d\n", size, del3);
                        
                        return find_group(arr, size, ascend);
                    }
                }                
            }
        }
    }
    return size;
}


int main(){    
    int a[N];
    int b[N];
    int size = 0;
    scanf("%d", &size);
    
    // int * a = calloc(k, sizeof(int));       
    for (int i=0; i<size; i++){
        int tmp;
        scanf("%d", &tmp);
        a[i] = tmp;
        b[i] = tmp;
    }
    
    
    int b_size = size;
    size = find_group(a, size, true);
    if (size ==1){
        for (int i=0; i<size; i++){
            printf("%d", a[i]);
        }
    }
    else {
        b_size = find_group(b, b_size, false);
        if (b_size == 1){
            printf("%d", b[0]);
        } else {
            printf("%d", 1);
        }
    }
    
    
}