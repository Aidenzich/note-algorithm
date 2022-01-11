#include <stdio.h>
#define KEY_LEN 10000

// gcc XORCipher.c -o xor && ./xor < xocipher.in 
int main (){
    char cipherKey[KEY_LEN], ch;
    
    scanf("%s", cipherKey);
    getchar();
    
    int ck = 0;
    int count = 0;
    while((ch = getchar()) != EOF){
        
        if (cipherKey[ck] == '\0') ck = 0;
        // printf("%c\n", cipherKey[ck]);
        ch ^= cipherKey[ck];    
        printf("%c", ch);        
        ck++;
    }
    
    return 0;
    
    // zj3)[=D(x?4x&   8(bG$Cq>R4JCldXW1mI`|QFv
    //                                     <qLk
}