#include <queue>
#include <stdio.h>
using namespace std;

int n, k, base = 1;
priority_queue<int> pq;

int main() {
    scanf("%d%d", &n, &k);
    if (k > n) return puts("NO"), 0;
    while (n) {
        if (n & 1) pq.push(base);
        n >>= 1, base <<= 1;
    }

    if (pq.size() > k) return puts("NO"), 0;
    while (pq.size() < k) {
        int tmp = pq.top(); pq.pop();
        pq.push(tmp >> 1), pq.push(tmp >> 1);
    }

    puts("YES");
    while(!pq.empty())
        printf("%d ", pq.top()), pq.pop();
    printf("\n");
}