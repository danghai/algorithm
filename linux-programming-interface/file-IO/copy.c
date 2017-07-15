/*
  Name: Hai Dang Hoang
  Email: goldsea5191@gmail.com
  Using I/O system calls to implemnt copy file

  This program is a siimple version of the cp(1) command.
  It copies the contents of the existing file named in its
  first command-line argument to the new file named in its second
  command-line argument
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main (int argc, char * argv[])
{
  int inputFd, outputFd, openFlags;
  mode_t filePerms;                    // File permission
  ssize_t numRead;
  char buf[BUF_SIZE];

  /*Check argument */
  if(argc != 3 )
  {
    perror("Error argument. It should ./copy file1 file2");
    exit(1);
  }
  /* Setting flag and permission*/
  openFlags = O_CREAT | O_WRONLY | O_TRUNC;
  filePerms = S_IRUSR | S_IWUSR  | S_IRGRP | S_IWGRP|
              S_IROTH | S_IWOTH;       /* rw-rw-rw*/
  /* Open input and output files */
  inputFd = open(argv[1], O_RDONLY);
  if  (inputFd == -1)
  {
    perror("Error opening file for read" );
    exit(-1);
  }
  outputFd = open(argv[2],openFlags, filePerms);
  if (outputFd == -1)
  {
    perror("Error opening file for write ");
    exit(-1);
  }
  /* Transfer data until we encounter end of input or an error*/
  while((numRead = read(inputFd,buf, BUF_SIZE))>0)
      if (write(outputFd,buf,numRead) != numRead)
      {
        perror("could not write whole buffer");
        exit(-1);
      }
  if(numRead == -1)
  {
    perror ("Error read");
    exit(-1);
  }
  /* Close the file*/
  if(close(inputFd)== -1)
  {
    perror("close input");
    exit(-1);
  }
  if(close(outputFd)== -1)
  {
    perror("close output");
    exit(-1);
  }

  exit(EXIT_SUCCESS);
}
