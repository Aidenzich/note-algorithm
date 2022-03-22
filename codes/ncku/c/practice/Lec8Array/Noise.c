#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    long long house[10];
    long long max = 0, tmp = 0;
    for (int i =0; i<10; ++i){        
        scanf("%lld", &house[i]);
    }

    for (int i=0; i<10; ++i){
        for (int j=0; j<10; ++j){
            if (i != j){
                tmp = (house[i] + house[j]) * abs(i-j);
                if (tmp > max){
                    max = tmp;
                }
            }            
        }
    }

    printf("%lld", max);
}