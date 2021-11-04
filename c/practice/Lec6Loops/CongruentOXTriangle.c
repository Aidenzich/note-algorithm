// Description
// Given a number h, print a congruent triangle with height h that consists of OOXX (the last line must be only consist of O).

// For example, h=5:
//     O
//    OXO
//   OXOXO
//  OXOXOXO
// OOOOOOOOO

// Input
// An integer h. (1 <= h <= 150)

// Output
// A congruent triangle consisted of OX, and the bottom of the triangle must only contains O.

// Limits
// Your program needs to finish task in 3 seconds.

// Your program can only use memory less than 10000 KB.

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
int main() {
   int i, space, height, k = 0;
   scanf("%d", &height);
   for (i = 1; i <= height; ++i, k = 0) {
      for (space = 1; space <= height - i; ++space) {
        printf(" ");
      }
      while (k != 2 * i - 1) {
        if (k % 2 == 0 || i == height){
            printf("O");
        } else {
            printf("X");
        }        
        ++k;
      }
      printf("\n");
   }
   return 0;
}