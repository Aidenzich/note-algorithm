// Description
// Your cousin is a second grade elementary school student. He learned the addition that written in column form in his today's class. However, he still has lots of questions about it. Your task is to write a small program to demonstrate the answer to the addition of xand ywritten in column form.


// Input
// Given 2 integers split by a space.

// 0 <= x, y <= 9999

// Output
// The column form will be performed in 4 lines.

// First line will start in 2 space and augend(被加數) padding with zeros until 4 digits.

// Second line will start in "+)" and addend (加數) padding with zeros until 4 digits.

// Third line is "------".

// Last line is the result padding with zeros until 6 digits.

// Limits
// Your program needs to finish task in 5 seconds.

// Your program can only use memory less than 65535 KB.


#include <stdio.h>
#include <math.h>
int main(void){    
    int a, b, c;        
    scanf("%d %d", &a, &b);
    c = a + b;    
    printf("  %.4d\n", a);    
    printf("+)%.4d\n", b);
    printf("------\n");

    printf("%06d", c);

    return 0;
}