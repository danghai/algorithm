/*
    Name: Hai Dang Hoang
    Email: goldsea5191@gmail.com

    fork_file_sharing.c: Program opens a file, and then call fork() to create
    a child process. The child changes the file offset and status flags of the
    file, and exits. The parent then retrieves the file offset and flags to verify
    that it can see the changes made by the child. 
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


int main(int argc, char *argv[])
{
  int fd, flag;
  mode_t mode;
  off_t offset;
  /* Check argument */
  if(argc < 2)
  {
    fprintf(stderr, "Usage: %s filename [x] \n",argv[0]);
    exit(EXIT_FAILURE);
  }

  /* Set the mode and flag for fd before fork() */
  flag = O_WRONLY | O_CREAT ; // No O_APPEND flag
  mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; /* rw-rw-rw*/
  if((fd = open(argv[1],flag,mode) == -1))
  {
    perror ("Error open \n");
    exit (EXIT_FAILURE);
  }
  if((offset = lseek(fd,0,SEEK_CUR)) == -1)
  {
    perror("Error lseek - SEEK_CUR 0 ");
    exit (EXIT_FAILURE);
  }
  printf("File offset before fork(): %lld\n",(long long) offset);
  printf("O_APPEND flag before fork() is: %s\n",(flag & O_APPEND) ? "ON": "OFF");

  switch(fork())
  {
    case -1:
      perror ("Error fork \n");
      exit(EXIT_FAILURE);

    case 0:  // Child process: Change file offset and status flag
      if(lseek(fd,100,SEEK_SET) == -1)        // Move fd to 100 bytes
      {
        perror("Error lseek -100 \n");
        exit(EXIT_FAILURE);
      }

      flag = O_WRONLY | O_CREAT | O_APPEND;  // modify flag and set fd
      if(fcntl(fd,F_SETFL,flag) == -1)
      {
        perror("Error fcntl - F_SETFL \n");
        exit(EXIT_FAILURE);
      }
      exit(EXIT_SUCCESS);

    default: // Parrent: can see file changes mde by its Child
      if (wait(NULL) == -1)                 // Wait for child exit
      {
        perror ("Error wait \n");
        exit(EXIT_FAILURE);
      }
      printf("---------------------------------------- Child is exited \n");
      printf("File offset after fork(): %lld\n",(long long) lseek(fd,1,SEEK_CUR));

      if((flag = fcntl(fd, F_GETFL))== -1)
      {
        perror("Error fcntl - F_GETFL \n");
        exit(EXIT_FAILURE);
      }
      printf("O_APPEND flag after fork() is: %s\n",(flag & O_APPEND) ? "ON": "OFF");
      exit(EXIT_SUCCESS);
  }


  exit(EXIT_SUCCESS);
}
