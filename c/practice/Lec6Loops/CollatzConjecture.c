// Description
// Collatz conjecture, also known as 3n+1 problem, which is a conjecture in mathematics that is about a sequence defined as follows: Let S1 be a positive integer which is the start of the sequence, and

// if Sn is even, then Sn+1 = Sn / 2

// if Sn is odd, then Sn+1 = 3 * Sn + 1

// The conjecture is that for any given positive integer S1 (<= 10^5), the sequence will reach 1.

// e.g. Given S1 = 22, the sequence will be: 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1

// As students of NCKU, we are interested in this conjecture, please write a program to help us do some research in this conjecture.

// Input
// A positive integer S1, (1 <= S1 <= 10^5)

// Output
// Two integer L, M within a line, where L represents the length of the sequence and M is the maximum number of the sequence.

// Limits
// Your program needs to finish task in 5 seconds.

// Your program can only use memory less than 65536 KB.



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
int main() {
  int input = 0;
  int count = 1;
  int tmp, max;
  scanf("%d", &input);
  tmp = input;
  max = input;
  
  while (tmp != 1){
    if (tmp % 2 == 0){
      tmp = tmp/2;
    } else {
      tmp = 3 * tmp +1;
    }
    if (tmp > max){
      max = tmp;
    }
    count++;
  }
  printf("%d %d", count, max);
  return 0;
}