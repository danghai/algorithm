CC = gcc
FLAG = -o
CFLAG = -c

all: ouch intquit sig_sender sig_receiver

ouch: ouch.c
	$(CC) $(FLAG) ouch ouch.c

intquit: intquit.c
	$(CC) $(FLAG) intquit intquit.c

sig_sender: sig_sender.c
	$(CC) $(FLAG) sig_sender sig_sender.c
sig_receiver: sig_receiver.c
	$(CC)  $(FLAG) sig_receiver sig_receiver.c

clean:
	rm ouch intquit sig_receiver sig_sender
