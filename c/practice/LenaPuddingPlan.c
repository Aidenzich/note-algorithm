#include<stdio.h>

int main () {
    int i1, i2, i3, sum, puddingsperday, left;
    scanf("%d%d%d", &i1, &i2, &i3);
    sum = i1 + i2 + i3;
    puddingsperday = sum / 7;
    left = sum % 7;
    printf("%d %d", puddingsperday, left);
    
    return 0;
}