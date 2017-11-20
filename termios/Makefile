CC = gcc
FLAG = -o
CFLAG = -c

all: new_intr no_echo

new_intr: new_intr.c
		$(CC) $(FLAG) new_intr new_intr.c

no_echo: no_echo.c
		$(CC) $(FLAG) no_echo no_echo.c

clean:
		rm new_intr no_echo
