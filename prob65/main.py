#!/usr/bin/env python3

def main() :
    target = 100
    factor = [1]*target
    factor[0] = 2
    n = 2
    for i in range(2, target, 3):
        factor[i] = n
        n += 2

    f = target - 1
    num, denum = factor[f], 1
    denum = factor[f]
    while f > 0:
        denum, num = num, denum
        f -= 1
        num += denum * factor[f]

    sumnum = sum(map(int, str(num)))

    print('The sum of digits in the numerator of the', target, 'th'
          '\nconvergent of the continued fraction for e is:', sumnum)

if __name__ == '__main__':
    main()
