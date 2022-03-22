n, k = list(map(int,input().split()))
a = list(map(int,input().split()))
a = sorted(a, reverse=True)
a2 = [ i - a[-1] for i in a ]

diff = sum(a) - k
if diff < 0:
    print(0)
    exit()

minTry = 1e+9

for m2 in range(len(a)):
    for m1 in range(diff+1):
        if (diff - sum(a2[ 0 : m2+1]) - m1 - m1*m2 <= 0):
            if (minTry > m1 + m2):
                minTry = m1 + m2

print(minTry)