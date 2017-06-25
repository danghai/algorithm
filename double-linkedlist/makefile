CC= g++
CFLAGS = -c -Wall

all: main
main: main.o doublell.o
	$(CC) main.o doublell.o -o main
doublell.o: doublell.cpp
	$(CC) $(CFLAGS) doublell.cpp

clean:
	rm *o main
