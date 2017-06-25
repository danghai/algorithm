CC= g++
CFLAGS = -c -Wall

all: main
main: main.o bstTree.o
	$(CC) main.o bstTree.o -o main
bstTree.o: bstTree.cpp
	$(CC) $(CFLAGS) bstTree.cpp

clean:
	rm *o main
