#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 50
#define MAX_RESULT_LEN 720
char resultArr[MAX_RESULT_LEN][MAX_STR_LEN];
int resultCount = 0;

void swap(char *a, char *b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sortByStrcmp(){
    char temp[MAX_STR_LEN];
    for (int i=0; i <= resultCount; i++){
        for (int j=i; j <= resultCount; j++){
            if (strcmp(resultArr[i], resultArr[j]) > 0){                
                strcpy(temp, resultArr[i]);
                strcpy(resultArr[i], resultArr[j]);
                strcpy(resultArr[j], temp);
            }
        }
    }

}

void permute(char *a, int l, int r){
    if (l == r){
        resultCount++;
        strcpy(resultArr[resultCount], a);
    } else {
        for (int i=l; i<=r; i++){
            swap((a+l), (a+i));
            permute(a, l+1, r);
            swap((a+l), (a+i));
        }
    }
}

int main(){
    char ch;    
    char input[MAX_STR_LEN];
    int strLen = 0;
    scanf("%s", input);    
    
    permute(input, 0, strlen(input)-1);

    sortByStrcmp();
    
    for (int i=1; i<=resultCount; i++){
        printf("%s\n", resultArr[i]);
    }
    printf("\n");
}

// gcc Permutation.c -o a.out && ./a.out < a.in