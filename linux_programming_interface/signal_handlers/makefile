CC = gcc
FLAG = -o
CFLAG = -c

all: ouch intquit sig_sender sig_receiver signal_flaw fix_signal_flaw

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

signal_flaw: signal_flaw.c
	$(CC) $(FLAG) signal_flaw signal_flaw.c

fix_signal_flaw: fix_signal_flaw.c
	$(CC) $(FLAG) fix_signal_flaw fix_signal_flaw.c

clean:
	rm ouch intquit sig_receiver sig_sender signal_functions.o signal_flaw fix_signal_flaw
