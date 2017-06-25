CFLAGS = -c -Wall
all: maze

maze: maze.o 
	gcc maze.o -o maze
maze.o: maze.c
	gcc $(CFLAGS) maze.c

clean:
	rm -f *.o maze

