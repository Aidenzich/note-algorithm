// Description
// Although you guys have done Combination in lecture 7 before (right?), you all notice that a factorial of a large number may cause overflow even with type unsigned long(what a nightmare. We all have learnt that there is another definition of combination:

// C(n, m) =

// 1, if m == 0 or m == n

// C(n - 1, m - 1) + C(n - 1, m), otherwise

// Please try to calculate the combination again with this definition.

// Input
// A line with two integers represent n and m respectively. (1 <= n <= m <= 30)

// Output
// An integer which represents C(n, m).

// Limits
// Your program needs to finish task in 2 seconds.

// Your program can only use memory less than 6000 KB.

#include <stdio.h>


long getCombinationNum(int n, int k) {    
    long num = 1;
    for (int d = 1; d <= k; ++d) {
        num = num * n--;
        num = num / d;
    }
    return num;
}
int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    long ans = getCombinationNum(n, k);
    printf("%ld", ans);
}
