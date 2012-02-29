#!/bin/sh

rm -f parse.txt temp.txt
sed 's/"//g' words.txt | sed 's/,/\n/g' > parse.txt
wc -Lw < parse.txt > temp.txt
cat temp.txt parse.txt > input.txt
rm -f parse.txt temp.txt
make -s main.cpp
./main < input.txt
rm -f input.txt
