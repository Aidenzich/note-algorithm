// Description
// There is a sequence A/B**C/)D , where A,B,C,D are integer.

// Please output the A+B+C+D.


// Input
// There is one line sequence A/B**C/)D.

// ( 1 < A,B,C,D < 1000000 and A,B,C,D are integers )

// Output
// Please output the A+B+C+D.

// No need to print the newline.

// Limits
// Your program needs to finish task in 5 seconds.

// Your program can only use memory less than 65535 KB.
#include <stdio.h>
#include <math.h>
int main(void){    
    int a, b, c, d;
    int total;

    scanf("%d/%d**%d/)%d", &a, &b, &c, &d);
    total = a + b + c + d;
    printf("%d", total);
    
    return 0;
}