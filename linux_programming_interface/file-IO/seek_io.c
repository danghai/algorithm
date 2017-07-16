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
  char *buf;


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

    for (argument = 2; argument < argc; argument++)
    {
      switch(argv[argument][0])
      {
        case 'r':     /* Display bytes at current offset, as text */
        case 'R':     /* Display bytes at current offset, in hex */
          //  Convert a numeric command-line argument string to a long integer.
          len = getLong(&argv[argument][1],GN_ANY_BASE, argv[argument]);
          buf = malloc(len);
          if (buf == NULL)
          {
            perror ("Error memory allocation \n");
            return -1;
          }
          /* Read the file*/
          numRead = read(fd,buf,len);
          if(numRead == -1)
          {
            perror ("Cannot read the file");
            return -1;
          }

          if(numRead == 0)
            printf("%s: end of file \n", argv[argument]);
          else
          {
            printf("%s: ", argv[argument]);
            for(int j = 0 ;j < numRead; j++)
            {
              if(argv[argument][0] == 'r')    // Case r --> print text format
                printf("%c ", isprint((unsigned char) buf[j]) ? buf[j]: '?');
              else                      // print hex format
                printf("%02x ", (unsigned int) buf[j]);
            }
            printf("\n");
          }
          free(buf);
          break;

          /* Write string at current offset*/
          case 'w':
            numWritten = write(fd, &argv[argument][1], strlen(&argv[argument][1]));
            if(numWritten == -1)
            {
              perror ("Cannot write ");
              return -1;
            }
            else
              printf("%s: wrote %ld bytes \n",argv[argument],(long) numWritten);
            break;

          /* Change file offset */
          case 's':
            offset = getLong(&argv[argument][1],GN_ANY_BASE, argv[argument]);
            if(lseek(fd,offset,SEEK_SET)== -1)
            {
              perror ("Error lseek");
              return -1;
            }
            printf("%s: seek succeeded \n", argv[argument]);
            break;

            /* Default case*/
          default:
            printf("Argument must start with [rRws] \n");
      }
   }   // End Switch

      exit(EXIT_SUCCESS);
} // End main
