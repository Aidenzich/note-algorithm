// gcc a.c -o a && ./a < a.in
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<stdlib.h>
int pull_radish(int *l, int *r, int *pos, int x);

int main() {
    int N, y, x;
    scanf("%d %d %d", &N, &y, &x);
    int *farm = malloc(N*sizeof(int));

    // initialize farm[N]
    for(int i=0; i<N; i++) {
        farm[i]=1;
    }

    int total = pull_radish(&farm[0], &farm[N-1], &farm[y], x);
    
    printf("%d\n", total);

    for(int i=0; i<N; i++) {
        printf("%d ", farm[i]);
    }

    return 0;
}

int pull_radish(int *l, int *r, int *pos, int x) {
    // printf("%d %d %d %d\n", *l, *r, *pos, x);
    int *current_pos;
    int total = 0;
    current_pos = pos;
    while (current_pos < r){
        // *(pos+x) = 0;        
        current_pos += x;
        if (*current_pos == 1){
            *current_pos = 0;
            total++;
            // printf("%d\n", *current_pos);
        }        
        // break;
    }
    current_pos = pos;
    while (current_pos > l){
        current_pos -= x;
        if (*current_pos == 1){
            *current_pos = 0;
            total++;
            // printf("%d\n", *current_pos);
        }
    }
    

    return total;
}