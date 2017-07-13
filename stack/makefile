CC= g++
CFLAGS = -c -Wall

all: main
main: main.o stack.o
	$(CC) main.o stack.o -o main
stack.o: stack.cpp
	$(CC) $(CFLAGS) stack.cpp

clean:
	rm *o stack
