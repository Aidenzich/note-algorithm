// Make a Circle
// Description
// Suppose you are in an art class now. The teacher wants you to make a circle, made up of cloth, with string glued on the edge. Given the radius of the circle, you should calculate the area of the cloth and the length of the string that you need in order to make this circle.

// You should use macro to define PI as 3.14f.


// Input
// The radius of the circle. It is an integer x where 1 <= x <= 100.

// Output
// Two floating-point numbers (round to nearest 100th) separated by a space. The first one represents the area of the cloth, and the second one represents the length of the string.

// Limits
// Your program needs to finish task in 3 seconds.

// Your program can only use memory less than 6000 KB.
#include <stdio.h>
#include <math.h>
int main(void){
    const float PI = 3.14;
    int i1;
    float r1, r2;
    scanf("%d", &i1);
    r1 = pow(i1, 2) * PI;
    r2 = i1*2 * PI;
    printf("%.2f %.2f", r1, r2);
    return 0;
}