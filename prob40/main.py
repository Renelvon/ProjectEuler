#!/usr/bin/env python3

# If the positive integers from 1 to infinity are concatenated together as a single string
# find the product of the digits at positions 1, 10, 100, ... maxn of the string (1-based).
# See Project Euler problem 48 for more details.
maxn = 1000000
nums = map(str, range(0, maxn + 1))

fulls = ''
for s in nums:
    fulls = fulls + s

i = 1; n = 1
while True:
    n *= int(fulls[i])
    i *= 10
    if i > maxn:
        break

print('The solution is:', n)
