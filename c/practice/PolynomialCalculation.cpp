// Description
// Read a floating-point number for x and calculate the value of the following polynomial:

// 𝟕𝐱⁴ - 𝟖𝐱³ - 𝐱² + 𝟔𝐱 - 𝟐𝟐

// Input
// A floating-point number to read for x.

// Output
// The result should be displayed with one digit after the decimal point.

// Limits
// Your program needs to finish task in 5 seconds.

// Your program can only use memory less than 65536 KB.

#include <stdio.h>
#include <math.h>
int main(void){
    float a, ans;
    
    scanf("%f", &a);
    ans = 7 * pow(a, 4) - 8 * pow(a, 3) -  pow(a, 2) + 6 * a -22;
    printf("%.1f\n", ans);
    return 0;
}
