/*
  Name: Hai Dang Hoang
  Email: goldsea5191@gmail.command

  program demonstrates the use of lseek() in conjunction
  with read() and write(). The first command-line argument to this
  program is the name of a file to be opened. The remaining
  arguments specify I/O operations to be performed on the file
  Each of these operations consists of a letter followed by an associated value
*/
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include "get_num.h"

int main (int argc, char * argv[])
{
  int fd, argument;
  mode_t filePerms;                    // File permission
  ssize_t numRead, numWritten;
  size_t len;
  off_t offset;


  /*Check argument */
  if(argc < 3 )
  {
    perror("Error argument. It should: file r<length>| R<length> | w<string> | s<offset>");
    exit(1);
  }

  /* Open the file */
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; /* rw-rw-rw*/
    fd = open(argv[1], O_RDWR | O_CREAT,filePerms);
    if(fd == -1)
    {
        perror("Cannot open the file");
        return -1;
    }
/*
    for (argument = 2; argument < argc; argument++)
    {
      switch(argv[argument][0])
      {
        case 'r':     /* Display bytes at current offset, as text */
      //  case 'R':     /* Display bytes at current offset, in hex */
//      }
//    }








      exit(EXIT_SUCCESS);
    }
