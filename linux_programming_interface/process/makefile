CC = gcc
FLAG = -o
CFLAG = -c

all: fork_file_sharing multi_wait make_zombie

fork_file_sharing: fork_file_sharing.c
		$(CC) $(FLAG) fork_file_sharing fork_file_sharing.c

multi_wait: multi_wait.c
		$(CC) $(FLAG) multi_wait multi_wait.c

make_zombie: make_zombie.c
		$(CC) $(FLAG) make_zombie make_zombie.c

clean:
			rm fork_file_sharing multi_wait make_zombie
