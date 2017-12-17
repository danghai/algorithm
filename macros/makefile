CC = gcc
FLAG = -o
CFLAG = -c

all: test_debug if_condition variadic

if_condition: if_condition.c
		$(CC) $(FLAG) if_condition if_condition.c

test_debug: test_debug.c
		$(CC) $(FLAG) test_debug test_debug.c

variadic: variadic.c
	  $(CC) $(FLAG) variadic variadic.c

clean:
		rm test_debug if_condition variadic
