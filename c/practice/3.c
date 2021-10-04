// Division of Two Integers
// Description
// Given two integers x and y, your program should calculate the answer of x/y and print out the result according to the Output Format.

// Note : -𝟏𝟎³ < x, y < 𝟏𝟎³

// Input
// Two integers split by a space.

// Output
// Two values split by space: 1. One digit after the decimal point. 2. Two digits after the decimal point. All the values should be rounded.

// Limits
// Your program needs to finish task in 5 seconds.

// Your program can only use memory less than 65536 KB.

// Hint
// Google: "printf specifier"

#include <stdio.h>
#include <math.h>
int main(void){
    float i1, i2;
    float r;
    scanf("%f %f", &i1, &i2);
    r = i1 / i2;
    printf("%.1f %.2f", r, r);
    return 0;
}
