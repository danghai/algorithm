/*
    Name: Hai Dang Hoang
    Email: goldsea5191@gmail.com

    sig_sender.c: The program send signal to specific PID:
    $ ./sig_sender PID num-sigs sig_numm [sig-num-2]

    The first argument: is the process ID of a process wo thich the program
    should send signals.
    The second argument: specifies the number of signals to be sent to the target process
    The third argument: specifies the signal number that is to be sent to the target process
    If a signal number is supplied as the fourth argument, then the program sends one
    instance of that signal after sending the signals specified by the previous arguments.
*/
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "signal_functions.h"

int main(int argc, char * argv[])
{
  if ((argc<3) || (argc >5))
  {
      fprintf(stderr,"Usage: %s PID  num-sigs  sig-num  [sig-num-2] \n",argv[0]);
      exit(EXIT_FAILURE);
  }

  pid_t pid;
  int num_sigs, sig;
  /* Convert argument and assign to variable*/
  pid = atoi(argv[1]);
  num_sigs = atoi(argv[2]);
  sig = atoi(argv[3]);

  /* Sending signal to specific PID process */
  printf("%s: sending signal %d to process %ld : %d times \n", argv[0], sig, (long)pid, num_sigs);
  for (int i =0 ;i < num_sigs; i++)
  {
    if ((kill(pid,sig)) == -1)
    {
        perror("Error sending signal \n");
        exit(EXIT_FAILURE);
    }
  }

  /* If a fourth command-line argument was specified, send that signal*/
  if (argc = 4)
  {
      if(kill(pid, atoi(argv[4]))== -1)
      {
          perror("Error sending signal with argument 4 \n");
          exit (EXIT_FAILURE);
      }
  }

  exit(EXIT_SUCCESS);
}
