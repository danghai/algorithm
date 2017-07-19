/*
    Name: Hai Dang Hoang
    Email: goldsea5191@gmail.com

    multi_wait.c: program demonstrates the use of wait(). This program
    creates multiple child processes, one per command-line argument.
    Each child sleeps for the number of second specified in the
    corresponding command-line argument and then exits. In the meantime,
    after all children have been created, the parent process repeatedly calls
    wait() to monitor the termination of its children. This loop continues until
    wait() returns -1.
*/
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>


int main(int argc, char *argv[])
{
  /* check argument */
  int i,time_delay;
  pid_t pid,childPid;
  int numChild;
  if (argc < 2)
  {
    fprintf(stderr,"Usage: %s <number1> <number2> <number3>... \n",argv[0] );
    exit(EXIT_FAILURE);
  }
  for( i = 1;i < argc; i++)
  {
      time_delay = atoi(argv[i]);
      pid = fork();
      switch(pid)
      {
        case -1:
                perror("Error Child \n");
                exit(EXIT_FAILURE);
        case 0:
                printf("Child %d startd with PID %d, sleeping %d seconds \n",i,(int)getpid(),time_delay);
                sleep(time_delay);
                _exit(EXIT_SUCCESS);
        default:
                break;
      }
  }
  numChild = 0;
  for(;;)
  {
    childPid = wait(NULL);
    if (childPid == -1)                 // Wait for child exit
    {
      if(errno == ECHILD)
      {
        printf("No more children - bye! \n ");
        exit(EXIT_SUCCESS);
      }
      perror ("Error wait \n");
      exit(EXIT_FAILURE);
    }

    numChild++;
    printf("wait() return child PID %d (numChild = %d) \n",(int)childPid,numChild);
  }
  exit(EXIT_SUCCESS);
}
