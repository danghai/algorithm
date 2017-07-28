CC = gcc
FLAG = -o
CFLAG = -c

all: ouch intquit sig_sender sig_receiver

ouch: ouch.c
	$(CC) $(FLAG) ouch ouch.c

intquit: intquit.c
	$(CC) $(FLAG) intquit intquit.c

sig_sender: sig_sender.c signal_functions.o
	$(CC) $(FLAG) sig_sender sig_sender.c signal_functions.o

sig_receiver: sig_receiver.c signal_functions.o
	$(CC)  $(FLAG) sig_receiver sig_receiver.c signal_functions.o

signal_function.o: signal_functions.c
	$(CC) $(CFLAG) signal_functions.c

clean:
	rm ouch intquit sig_receiver sig_sender signal_functions.o
