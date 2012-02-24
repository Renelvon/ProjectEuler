#!/usr/bin/env python3

def main() :
    maxa = 100
    maxb = 100
    maxsum = 0
    for a in range(1, maxa):
        for b in range(1, maxb):
            maxsum = max(maxsum, sum(map(int, str(a**b))))
    print('The maximum digital sum obtained from numbers of the form a**b'
           '\nwhere 1 <= a <', maxa, ', 1 <= b <', maxb, 'is:', maxsum)

if __name__ == '__main__':
    main()
