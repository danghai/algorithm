#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>


#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main (int argc, char * argv[])
{
  char opt;          //Option for getopt()
  int fd;
  mode_t filePerms;
  ssize_t numRead, numWritten1, numWritten2;
  int flag;
  char buf[BUF_SIZE];
  if(argc < 2 )
  {
    perror("Error argument");
    exit(EXIT_FAILURE);
  }
  /* Parse command-line*/
  while((opt = getopt(argc, argv, "a")) !=-1)
  {
    switch(opt)
    {
      case 'a':         //  -a command-line
        filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; /* rw-rw-rw*/;
        flag = O_WRONLY | O_CREAT  | O_TRUNC;
        break;
      default:
        fprintf(stderr, "Usage: %s [-a] filename \n",argv[0]);
        printf("%d \n",opt);
        exit(EXIT_FAILURE);
    }
  }

  /* Open the file */
  if((fd = open(argv[argc-1],flag,filePerms)) == -1)
  {
    perror ("Error open the file \n");
    exit (EXIT_FAILURE);
  }

  /* Read from standard input until end-of-file and put them in buffer,
      and then write buffer to file and standard output*/
  while ((numRead = read(STDIN_FILENO, buf,BUF_SIZE))!=0)
  {
    if(numRead == -1)
    {
      perror("Error read the file \n");
      exit(EXIT_FAILURE);
    }

    // Write to standard output
    if((numWritten1 = write(STDOUT_FILENO,buf,numRead)) == -1 )
    {
      perror("Error write to the standard output \n");
      exit(EXIT_FAILURE);
    }

    // Write to file
    if((numWritten2 = write(fd,buf,numRead)) == -1)
    {
      perror("Error write to the file \n");
      exit(EXIT_FAILURE);
    }
  } // end while

  exit(EXIT_SUCCESS);
}
