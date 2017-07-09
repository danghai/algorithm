CC= g++
CFLAGS = -c -Wall

all: main
main: main.o linkedlist.o
	$(CC) main.o linkedlist.o -o main
linkedlist.o: linkedlist.cpp
	$(CC) $(CFLAGS) linkedlist.cpp

clean:
	rm *o main
