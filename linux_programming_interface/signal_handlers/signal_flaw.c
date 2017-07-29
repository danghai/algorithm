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

#define MAXBUF 1024
static void sigHandler(int sig)
{
  pid_t pid;
  pid = wait(NULL);     // Wait for children terimnal
  if(pid == -1)
  {
      perror("Error wait \n");
      exit(EXIT_FAILURE);
  }

  printf("Handler reaped child %d\n",(int) pid);
  sleep(2);
  return;
}


int main (int argc, char * argv[])
{
  char buf[MAXBUF];
  ssize_t n;
  if(argc > 2)
  {
      fprintf(stderr,"Usage: %s num_child \n",argv[0]);
      exit(EXIT_FAILURE);
  }

  pid_t pid;

  if(signal(SIGCHLD, sigHandler) == SIG_ERR)     // Signal handling for child
  {
      perror("Error Signal \n");
      exit(EXIT_FAILURE);
  }
  for(int i = 0 ;i < atoi(argv[1]); i++)
  {
      pid = fork();
      switch(pid)
      {
          case -1:
                    perror("Error fork !");
                    exit(EXIT_FAILURE);
          case 0:  // Child
                    printf("Hello from child %d \n",(int)getpid());
                    sleep(1);
                    _exit(EXIT_SUCCESS);
          default: break;
      }
  }

  /* Parent waits for terminal input and then processes it */
  if(n= read(STDIN_FILENO,buf,sizeof(buf)) < 0)
  {
        perror("Error read \n");
        exit(EXIT_FAILURE);
  }

   printf("Parent processing input \n");
  while(1)  // Loop forever
  ;
  exit(EXIT_SUCCESS);
}
