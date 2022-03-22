from math import factorial as fact
mod = 10**9 + 7

def C(n, k):
  return fact(n) // (fact(k) * fact(n - k))

n, m = map(int, input().split())
print(C(n + m - 1, m) % mod)