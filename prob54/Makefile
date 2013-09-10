LEX = flex
LFLAGS = -fsvL

CC = gcc
CFLAGS = -Wall -O2 -Wextra -FORTIFY_SOURCE -std=c99

.PHONY: all clean distclean

all : main

lex.yy.c : main.ll
	$(LEX) $(LFLAGS) $^

main.o : lex.yy.c
	$(CC) $(CFLAGS) -c $^ -o $@

main : main.o
	$(CC) $^ -lfl -o $@

clean :
	$(RM) *.c *.o

distclean: clean
	$(RM) main
