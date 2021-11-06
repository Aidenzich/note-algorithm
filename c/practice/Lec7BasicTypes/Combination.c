// Description
// The combination is defined as C(m, n) = m! / (n! * (m - n)!), and n! is n's factorial. Use the definition above to calculate the value of C(m, n).

// Input
// Two integers m, n separated by a space. 1 <= n <= m < 30.

// Output
// An integer represents the value of C(m, n).

// Limits
// Your program needs to finish task in 2 seconds.

// Your program can only use memory less than 65535 KB.
#include <stdio.h>

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    long ans = 1;
    for (int d = 1; d <= k; ++d) {
        ans = ans * n--;
        ans = ans / d;
    }
    printf("%ld", ans);
    return 0;
}
