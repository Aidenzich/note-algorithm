// gcc b.c -o b && ./b < b.in
#include <stdio.h>
#include <string.h>
#include <math.h>
void print_binary(void *n, int x){
    for(int i = 62; i >= 0; --i){
        // printf("i::%d\n", i);
        if (x-1 < i && i <= x+8 ){
            printf("%d", (*(int *)n >> i) & 1);
        } else {
            printf("%d", 0);
        }
        
        if (i && !(i % 8)) printf(" ");
    }
}
int main(){
    
    int round = 0;
    scanf("%d", &round);
    int startBits[round];
    // unsigned long K;
    unsigned long num[round];
    char bitArr[round][8];
    getchar();

    for (int i=0; i<round; i++){
        startBits[i] = 0;
        num[i] = 0;
        for (int j=0; j<8; j++){
            // strcpy(bitArr[i],  )
        }
        
    }
    for (int i=0; i<round; i++){        
        scanf("%d-%lx\n", &startBits[i], &num[i]);
        // printf("%d %d\n", (num[i] >> startBits[i]), num[i]);
        
        print_binary(&num[i], startBits[i]);
        // break;
        printf("\n");
    }
    
    

    return 0;
}

