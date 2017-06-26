CC= g++
CFLAGS = -c -Wall

all: main
main: main.o hashTable.o
	$(CC) main.o hashTable.o -o main
hashTable.o: hashTable.cpp
	$(CC) $(CFLAGS) hashTable.cpp

clean:
	rm *o main
