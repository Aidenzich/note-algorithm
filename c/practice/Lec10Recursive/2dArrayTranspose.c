#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverseArray(int** A, int m, int n){
    for (int i=0; i < m; i++){
        
        int start = 0;
        int end = n - 1;
        while (start < end)
        {
            // printf("origin: %d, %d\n", A[i][start], A[i][end]);
            swap(&A[i][start], &A[i][end]);
            start++;
            end--;
        }
    }

}

void reverseArrayVertical(int** A, int m, int n){
    for (int i=0; i<n; i++){
        int start = 0;
        int end = m - 1;
        while (start < end){
            swap(&A[start][i], &A[end][i]);
            start++;
            end--;
        }
    }
}


int **transposeArray(int**A, int m, int n, int time){
    // Transpose Array
    int **AT= (int**)malloc(sizeof(int*) * n);
    for (int i=0; i<n; ++i){
        AT[i] = (int*)malloc(sizeof(int)* m);
    }

    for (int i=0; i<m; ++i){
        for (int j=0; j<n; ++j){
            AT[j][i] = A[i][j];
        }
    }

    reverseArray(AT, n, m);

    printf("Transpose:\n");
    for (int i=0; i<n; ++i){

        for (int j=0; j<m; ++j){
            printf("%d ", AT[i][j]);
        }

        printf("\n");
    }

    if (time == 1){

        return AT;

    } else {

        time--;
        return transposeArray(AT, n, m, time);
    }
}

int main(){
    int m, n, i, j;
    scanf("%d %d", &m, &n);
    
    // Array
    int **A = (int**)malloc(sizeof(int*) * m);
    for (i=0; i<m; ++i){
        A[i] = (int*)malloc(sizeof(int) * n);
    }
    
    for (i=0; i<m; ++i){
        for (j=0; j<n; ++j){
            scanf("%d", &A[i][j]);
        }
    }
    
    int operate_num;
    scanf("%d", &operate_num);

    for (i=0; i < operate_num; ++i){
        char op;
        
        scanf("%s", &op);
        
        if (op == 'r'){
            printf("旋轉\n");
            char dir;
            scanf("%s", &dir);
            printf("方向:%c", dir);
        }

        // printf("%d", strcmp(str, "r"));
    }
    A = transposeArray(A, m, n, 5);

    // reverseArrayVertical(A, m, n);
    
    printf("\n");
    for (int i=0; i<m; ++i){
        for (int j=0; j<n; ++j){
            printf("%d", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}