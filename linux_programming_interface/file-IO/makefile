CC = gcc
FLAG = -o
CFLAG = -c

all: copy seek_io tee atomic_append

copy: copy.c
	$(CC) $(FLAG) copy copy.c

seek_io: seek_io.c get_num.o
	$(CC) $(FLAG) seek_io get_num.o seek_io.c
get_num.o: get_num.c
		$(CC)  $(CFLAG) get_num.c

tee: tee.c
	$(CC) $(FLAG) tee tee.c

atomic_append: atomic_append.c
	$(CC) $(FLAG) atomic_append atomic_append.c

clean:
	rm *o copy tee atomic_append
