// Description
// Read an integer x, and output its digits split by space.

// Note: 0 <= x <= 999
// Input
// Single integer

// Output
// Three digits split by spaces.

// If the number of digits is less than three, pad the output with zeros to make it three digits.

// Limits
// Your program needs to finish task in 10 seconds.

// Your program can only use memory less than 10000 KB.
#include <stdio.h>
#include <math.h>
int main(void){
    int input, hundred, ten, digits;
    scanf("%d", &input);
    hundred = input / 100;
    input -= hundred*100;
    ten = input / 10;
    input -= ten*10;
    digits = input;
    printf("%d %d %d", hundred, ten, digits);
    return 0;

}