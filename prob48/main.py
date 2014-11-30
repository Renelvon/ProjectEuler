#!/usr/bin/env python3

def f(i):
    return i**i

maxn = 1000
d = 10
n = sum(map(f, range(0, maxn + 1))) - 1
print('The last', d, 'digits of the sum of i raised to i, for i = 1 to', maxn, 'are:', str(n)[-d:])
