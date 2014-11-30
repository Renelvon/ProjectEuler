#!/usr/bin/env python3

def main() :
    digits = 10
    modulus = 10**digits
    base = 2; exp = 7830457
    # base should be positive and exp should be non-negative
    powresult = pow(base, exp, modulus)
    mul = 28433
    result = (mul * powresult + 1) % modulus
    print('The last', digits, 'digits of the prime',
          mul, '* pow(', base, ',', exp, ') + 1 are:', result)

if __name__ == '__main__':
    main()
