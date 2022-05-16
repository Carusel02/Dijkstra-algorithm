CC = gcc
CFLAGS = -Wall -g -std=c11 -lm

all: build

build: tema3

quadtree: tema3.c
	$(CC) tema3.c -o tema3 $(CFLAGS)

run: build
	./tema3
val: build
	valgrind --leak-check=full ./tema3

clean:
	rm -f *.o tema3

.PHONY: clean run build
