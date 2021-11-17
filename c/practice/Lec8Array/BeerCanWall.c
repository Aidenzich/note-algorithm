#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    long long width;
    scanf("%lld", &width);
    width = width/10;
    long long arr[width];
    arr[0] = 1;
    arr[1] = 2;
    for (int i = 2; i< width; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    
    printf("%lld", arr[width-1]);
}