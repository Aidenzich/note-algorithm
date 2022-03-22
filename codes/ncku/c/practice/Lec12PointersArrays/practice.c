#include <stdio.h>

int main(){
    int a[10], *p, *q, k;
    
    p = &a[0]; // 將array[0]的記憶體位址指派給p
    
    q = &a[5];
    
    *p = 5;
    printf("%d\n", a[0]);
    printf("%d\n", *p);
    printf("%d\n", a[0]);
    *p++ = 3;
    *p-- = 4;
    k = q - p;
    // printf("%d", k);
}

