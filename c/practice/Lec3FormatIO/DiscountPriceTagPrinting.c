// A-chao, from CSIE, is helping a poor supermarket salesperson designing the price tag for the upcoming anniversary event. However, there is way too much to do it by hand. Please help him design a program to print out the price tag format. Don't worry, he knows how to make things in the terminal become physical.

// The following are the rules for each output lines:

// Line #0 / #4: Filly Packed with the character "

// Line #1: Start with a backslash \, four spaces, the discount percentage which takes 3 character lengths, the string %off!, four more spaces, then ends with another backslash.

// Line #2: Start with a backslash \, one space, the string Before , two more spaces, a dollar sign $, the original cost without a decimal point using a field width of five characters (justified to the right), and ends with another space and a backslash.

// Line #3: Start with a backslash \, one space, the string After, three more spaces, a dollar sign $, the discounted cost till the second decimal place using a field width of five characters (justified to the right), and ends with another space and a backslash.

// No leading zero should be added to any of the printed numbers.

// You can checkout the testing cases for full examples.


// Input
// Two integers a, b separated by a space.

// a represents "discount percentage".

// b represents "original cost".

// 0 <= a <= 100

// 1 <= b <= 99

// Output
// Consists of 5 lines, forming a 18*5 rectangle.

// Please refer to the description section for details of each line.

// Limits
// Your program needs to finish task in 1 second.

// Your program can only use memory less than 5000 KB.
#include <stdio.h>
#include <math.h>

int main (void) {
    int a, b;
    float c;
    char str[10];
    
    scanf("%d %d", &a, &b);
    c = ((float)b * (100-(float)a)) / 100;
    
    printf("\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\n");
    sprintf(str, "%d", a);
    printf("\\    %3s\%%off!    \\\n", str);
    sprintf(str, "%d", b);
    printf("\\ Before  $ %4s \\\n", str);
    sprintf(str, "%.2f", c);
    printf("\\ After   $%5s \\\n", str);
    printf("\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"");
    return 0;
}
