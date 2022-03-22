#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_LENGTH 100000

int compare( const void* a, const void* b)
{
    
    int int_a = * ( (int*) a );
    int int_b = * ( (int*) b );

    
    if ( int_a == int_b ) return 0;
    else if ( int_a < int_b ) return -1;
    else return 1;
}
int isunique(int new, int arr[]){
    for (int i =0 ; i< 100; i++){
        if (arr[i] == -1){
            return 1;
        }
        if (new == arr[i]){
            return 0;
        }
    }
    return 1;
}


int main(){
    int t = 0;

    scanf("%d", &t);
    int arr[t+1][101];
    int arr_size[t+1];
    
    char ch;
    bool first = true;
    int index = 0;
    int num = 1;
    memset(arr, -1, sizeof(arr));

    for (int i=1; i<t+1; i++){
        arr[i][0] = i;
    }

    // 先存資料
    while ((ch=getchar()) != EOF){        
        if (ch == '0'){
            break;
        }
        if (ch >= '0'){            
            if (first){
                index = (int)ch - '0';
                first = false;
            }
            arr[index][num] = (int)ch - '0';
            arr_size[index]++;
            num++;
        }
        
        if (ch == '\n'){
            first = true;
            num = 0;
        }
    }


    
    // 查詢相關論文
    for (int i =1; i<t+1; i++){                
        int j = 0;
        int search = 0;
        while (true){
            if (arr[i][j] == -1){                
                break;
            }
            if (arr[i][j] == i){
                j++;
                continue;
            }
            search = arr[i][j];            
            int k = 0;
            while (true){
                try{
                    if (isunique(arr[search][k], arr[i])){                    
                        arr[i][arr_size[i]++] = arr[search][k];
                    }
                    if (arr[search][k] == -1){
                        break;
                    }
                    k++;                
                }catch 
                
            }
            j++;            
        }
    }
    
    // return 0;
    for (int i =1; i<t+1; i++){        
        
        printf("%d ->", i);
        int j = 0;
        int size = sizeof arr[i] / sizeof *arr[i];
                
        // qsort(arr[i], 100, sizeof(int), compare);
                
        

        while (true){
            if (arr[i][j] == -1){
                printf(" %d\n", i);
                // printf("\n");
                break;
            }
            // printf("%d", arr[i][j]);
            if (arr[i][j+1] == -1){
                printf(" %d\n", arr[i][j]);                    
                break;
            } else {
                printf(" %d", arr[i][j]);            
            }
            j++;
        }
    }
    
}


