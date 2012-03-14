#!/usr/bin/env python3

def main() :
    intmax = 100000
    modulus = 1000000
    # p[n] is the number of ways n can be written
    # as a sum of one or more integers.
    #
    p = [0] * (intmax + 1)
    p[0] = 1
    p[1] = 1
    numa = None
    for n in range(2, intmax + 1):
        sump = 0
        sign = True
        i = 1
        while (True):
            a = i * (3 * i - 1) // 2
            if a > n:
                break
            
            if sign:
                sump += p[n - a]
            else:
                sump -= p[n - a]

            b = i * (3 * i + 1) // 2
            if b > n:
                break

            if sign:
                sump += p[n - b]
            else:
                sump -= p[n - b]

            sign = not sign
            i += 1

        p[n] = sump
        if (0 == sump % modulus):
            numa = n
            break;

    print('The least value of n for which p(n) is divisible by', modulus, 'is:', numa) 

if __name__ == '__main__':
    main()
