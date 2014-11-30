#!/bin/sh

sort -u keylog.txt | sed 's/\([0-9]\)\([0-9]\)\([0-9]\)/\1 \2 \3 /' > data.txt
wc -l < data.txt > temp.txt
make main -s
cat temp.txt data.txt | ./main
rm -f temp.txt data.txt input.txt
