/*
    ouch.c: it is a simple example of a signal handler function and a main
    program that establishes it as the handler for the SIGINT signal. (The terminal
    driver generates this signal when we type the terminal interrupt character, usually
    Control-C). The handler simply prints a message Ouch and returnss
*/
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>


static void sigHandler (int sig)
{
  printf("    Ouch! \n");
}

int main(int argc, char *argv[])
{
  if (signal(SIGINT, sigHandler)== SIG_ERR)
  {
    perror("Error signal");
    exit(EXIT_FAILURE);
  }
  for(int i = 0 ; ; i++)
  {
    printf("%d\n",i);
    sleep(2);
  }

  exit(EXIT_SUCCESS);
}
