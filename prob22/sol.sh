#!/bin/sh

rm -f input.txt parse.txt temp.txt
sed 's/"//g' names.txt > parse.txt
sed -i 's/,/\n/g' parse.txt
sort -d parse.txt -o parse.txt
wc -w < parse.txt > temp.txt
cat temp.txt parse.txt > input.txt
rm -f parse.txt temp.txt
make -s main
./main < input.txt
rm -f input.txt
