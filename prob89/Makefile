CC = g++
CFLAGS = -Wall -O2 -Wextra -Weffc++ -FORTIFY_SOURCE -pedantic -ansi

all: parse main

parse: parse.cpp
	$(CC) $(CFLAGS) $^ -o $@

main : main.cpp
	$(CC) $(CFLAGS) $^ -o $@
