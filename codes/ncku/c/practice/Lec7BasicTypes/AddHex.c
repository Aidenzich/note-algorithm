#include <stdio.h>
#include <limits.h>


int main(void){
    unsigned int i1, i2;
    unsigned int output;
    
    scanf("%x %x", &i1, &i2);
    
    // what's the problem?

    // if ((i2 > UINT_MAX - i1)) {
    //     printf("OVERFLOW!"); // ?
    // } else {
    //     printf("%x", i1+i2);
    // }

    if( (i1 + i2) & 0x10000){
        printf("OVERFLOW!");
    } else {
        printf("%x", i1+i2);
    }

   return 0;

}


