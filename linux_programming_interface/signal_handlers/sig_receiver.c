/*
    Name: Hai Dang Hoang
    Email: goldsea5191@gmail.com
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

static int sigCnt[NSIG];    // counts deliveries of each signal
static volatile sig_atomic_t gotSigint = 0;

static void handler(int sig)
{
  if (sig == SIGINT)
    gotSigint = 1;
  else
    sigCnt[sig]++;
}

int main(int argc, char * argv[])
{
  int n, numSecs;
  sigset_t pendingMask, blockingMask, emptyMask;

  printf("%s: PID is %ld \n", argv[0], (long) getpid());

  for(n = 1; n< NSIG; n++)      /*Same handler for all signals*/
    (void) signal(n,handler);

  /*
      If a sleep time was specified, temporarily block all signals,
      sleep (while another process sends us signals), and then display
      the mask of pending signals and unblock all signals
  */
  if (argc > 1)
  {
      numSecs = atoi(argv[1]);

      sigfillset(&blockingMask);
      if(sigprocmask(SIG_SETMASK, &blockingMask, NULL) == -1)
      {
          perror ("Error sigprocmask - blockMask \n");
          exit(EXIT_FAILURE);
      }

      printf("%s: sleeping for %d seconds \n", argv[0], numSecs);
      sleep(numSecs);

      if(sigpending(&pendingMask) == -1)
      {
          perror("Error sigpending \n");
          exit(EXIT_FAILURE);
      }

      printf("%s: pending signals are: \n", argv[0]);

      sigemptyset(&emptyMask);    // Unblock all signals
      if(sigprocmask(SIG_SETMASK, &emptyMask, NULL) == -1)
      {
          perror("Error sigprocmask - emptyMask \n");
          exit(EXIT_FAILURE);
      }
  }

  while(!gotSigint)       /* Loop until SIGINT caught*/
    continue;

  /* Display number of signals received */
  for(n = 1;n < NSIG;n++)
    if(sigCnt[n]!=0)
      printf("%s: signal %d caught %d time %s \n", argv[0],n,sigCnt[n], (sigCnt[n] == 1 ? "": "s"));


  exit(EXIT_SUCCESS);
}
