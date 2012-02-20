#!/usr/bin/env python3

# Open big-numbers' file
i = 100
from math import factorial
n = sum(map(int, str(factorial(i))))
print('The sum of digits of factorial(', i, ') is:', n)

