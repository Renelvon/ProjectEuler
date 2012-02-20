#!/usr/bin/env python3

# Open big-numbers' file
filename = 'nums.txt'
inFile = open(filename, "rt")
n = 0
while True:
    inLine = inFile.readline()
    if not inLine:
        break
    n = n + int(inLine)
s = 10
n = int(str(n)[:s])
print('The first', s, 'digits of the sum of all numbers in', filename, 'is:', n)

