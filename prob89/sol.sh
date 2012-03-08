#!/bin/sh

make all -s
./parse < roman.txt | ./main
