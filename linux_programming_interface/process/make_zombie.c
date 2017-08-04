/*
    Name: Hai Dang Hoang
    Email: goldsea5191@gmail.com

    make_zombie.c: The program demonstrates the creation of a zombie
    and that a zombie cannot killed by SIGKILL. It should be killed by
    kill their parent.
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
#include <signal.h>
#include <libgen.h>
#include <time.h>

#define CMD_SIZE 100

int main(int argc, char * argv[])
{
  char cmd[CMD_SIZE];
  pid_t childPid;
  printf("Parent PID = %ld \n",(long)getpid());

  switch(childPid = fork())
  {
    case -1:
        perror("Error fork \n");
        exit(EXIT_FAILURE);

   case 0:     /* Child: immediately exits to become zombie */
      printf("Child (PID = %ld) exiting \n", (long)getpid());
      _exit(EXIT_SUCCESS);

   default:   /* Parent */
      sleep (3);  // Give child a chance to start and exit
      snprintf(cmd, CMD_SIZE, "ps | grep %s", basename(argv[0])); // cmd = ps | grep "make_zombie"
      system(cmd);

      /* Send the SIGKILL to kill child zombie */
      if (kill(childPid,SIGKILL)== -1)
      {
          perror ("Error kill \n");
          exit(EXIT_FAILURE);
      }
      sleep(3);
      printf("After sending SIGKILL to zombie (PID = %ld): \n",(long)childPid);
      system(cmd);  /* View and see result that zombie cannot be killed by signal*/


      sleep(3);
      if (kill(getpid(), SIGKILL) == -1)
      {
          perror ("Error kill \n");
          exit (EXIT_FAILURE);
      }
      //printf("After sending SIGKILL to parent (PID = %ld): \n",(long)getpid());
      //system(cmd); /* View and see result that zombie is kill when we terminate parent */

      exit(EXIT_SUCCESS);

  }
}
