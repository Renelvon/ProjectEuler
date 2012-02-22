#!/usr/bin/env python3

from math import factorial

def c(n,r):
    return factorial(n) / factorial(r) / factorial(n - r)

i = 0; lowr = 1; highr = 100; limit = 1000000
for n in range(lowr, highr + 1):
    for r in range(lowr, n + 1):
        if c(n,r) > limit:
            i += 1

print('For', lowr, '<= n <=', highr, ', the number of values of C(n, r) that exceed', limit, 'is:', i)
