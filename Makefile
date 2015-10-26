# Makefile

CC=gcc
SH = bash
CFLAGS = -g -c
LDFLAGS = -lpthread

all:matmul

matmul:matmul.o matlib.o
	$(CC) $^ $(LDFLAGS) -o $@

matmul.o: matmul.c matlib.h
	$(CC) $(CFLAGS) $< -o $@

matlib.o: matlib.c matlib.h
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm matmul
	rm *.o
