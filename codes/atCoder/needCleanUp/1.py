import math


def rad(n):
    return reduce(operator.mul, set(ma.prime.factors3(n)))
 
def q(a, b, c):
    return math.log(c) / math.log(rad(a * b * c))
 
def find_abc(limit=1000):
    pfac = [0] + [set(ma.prime.factors3(n)) for n in range(1, limit)]
    num = 0
    for a in range(1, limit - 2):
        for b in range(a + 1, limit - a):
            c = a + b
            if c < limit and not pfac[a] & pfac[b]:
                qabc = q(a, b, c)
                if qabc > 1:
                    num += 1
                    print "{0:3d}  {1:5.3f}  {2:3d}  {3:3d}   {4:3d}".format(num, qabc, a, b, c)
find_abc(1000)