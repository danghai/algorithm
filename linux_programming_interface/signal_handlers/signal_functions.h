/*
  signal_function.h

  Header file for signal_function.c
*/

#ifndef SIGNAL_FUNCTIONS_H_
#define SIGNAL_FUNCTIONS_H_

#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int printSigMask(FILE *of, const char *msg);

int printPendingSigs(FILE *of, const char *msg);

void printSigset(FILE *of, const char *ldr, const sigset_t *mask);

#endif
