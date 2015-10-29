# Makefile

CC=gcc
SH = bash
CFLAGS = -g -c
LDFLAGS = -lpthread

all:matmul graph data

matmul:matmul.o matlib.o
	$(CC) $^ $(LDFLAGS) -o $@

matmul.o: matmul.c matlib.h
	$(CC) $(CFLAGS) $< -o $@

matlib.o: matlib.c matlib.h
	$(CC) $(CFLAGS) $< -o $@

data:createDat.c
	$(CC) $< -o $@

graph:time.c
	$(CC) $< -o $@

clean:
	rm matmul
	rm *.o
	rm graph
	rm data
