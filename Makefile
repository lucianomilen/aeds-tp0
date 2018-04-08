CC = gcc
CFLAGS = -g -Wall -std=c99
demo: grafo.o
	$(CC) $(CFLASGS) main.c grafo.c -o tp0