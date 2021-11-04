#include <stdio.h>

int main(void){
    float input, ans;    
    scanf("%f", &input);
    ans = ((input * 9)/5) + 32;
    printf("%.2f", ans);
    return 0;
}