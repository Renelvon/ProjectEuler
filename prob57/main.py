#!/usr/bin/env python3

from fractions import gcd
from math      import floor, log10

def main() :
    repmax = 1000
    num = 1
    denum = 1
    count = 0
    for i in range(1, repmax):
        num, denum = 2 * denum + num, num + denum
        m = gcd(num, denum)
        num //= m
        denum //= m
        if floor(log10(num)) > floor(log10(denum)):
            count += 1

    print('In the first', repmax, 'expansions of sqrt(2),', count, 'fractions \
            \ncontain a numerator with more digits than denominator')

if __name__ == '__main__':
    main()
