#include <stdio.h>

int max(int arr[], int n){
    int i;
    int max = arr[0];
    for (i=1; i<n; i++){
        if (arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int min(int arr[], int n){
    int i;
    int min = arr[0];
    for (i=1; i<n; i++){
        if (arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}

int main(){
    int ArrayNum, ArrayLen;
    scanf("%d", &ArrayNum);
    while (ArrayNum-- > 0){
        scanf("%d", &ArrayLen);
        // printf("%d\n", ArrayLen);
        
        int inputArray[ArrayLen];
        for (int i=0; i<ArrayLen; i++){
            scanf("%d", &inputArray[i]);
        }        
        int maxNum = max(inputArray, ArrayLen);
        int minNum = min(inputArray, ArrayLen);
        printf("%d\n", maxNum - minNum);        
    }    
}



// gcc PlusOneOnTheSubset.c -o A.out && ./A.out < A.in