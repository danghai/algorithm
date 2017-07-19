CC = gcc
FLAG = -o
CFLAG = -c

all: fork_file_sharing multi_wait

fork_file_sharing: fork_file_sharing.c
		$(CC) $(FLAG) fork_file_sharing fork_file_sharing.c

multi_wait: multi_wait.c
		$(CC) $(FLAG) multi_wait multi_wait.c 


clean:
			rm fork_file_sharing multi_wait
