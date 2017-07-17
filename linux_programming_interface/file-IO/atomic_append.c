/*
    Name: Hai Dang Hoang
    Email: goldsea5191@gmail.command

    This program is designed to demonstrate why the atomicity guaranteed
    by opening a file with the O_APPEND flag is necessary. Write a program
    that takes up to three command-line arguments:

          $ ./atomic_append <filename> <num-bytes> [x]

    This program should open the specified filename (creating it if necessary)
    and append num-bytes to the file by using write() to write a byte at a time.
    By default, the program should open the file with the O_APPEND flag, but if a
    third command-line argument (x) is supplied, O_APPEND flag should be omitted,
    and instead, the program should perform and lseek(fd, 0, SEEK_END) call before
    each write(). Run two instances of this program at the same time without the x
    argument to write 1 million bytes to the same file:

        $ ./atomic_append f1 10000000 & ./atomic_append f1 10000000

   Repeat the same steps, writing to a different file, but this time specifying the x argument:

        $ atomic_append f2 10000000 x & ./atomic_append f2 10000000 x

Result: f2 was run without O_APPEND. f2 has less number of bytes, as well as number of
time than f1. Because its seeking to the end of the file do not take place at the same time as the write
*/
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int main (int argc, char * argv[])
{
  int fd;
  mode_t filePerms;
  int flag;
  long num_bytes;
  ssize_t numWritten;
  off_t offset;
  /* Check argument*/
  if((argc < 3) || (argc > 4))
  {
    fprintf(stderr, "Usage: %s filename num-bytes [x] \n",argv[0]);
    exit (EXIT_FAILURE);
  }
  else if (argc ==3)
    flag = O_WRONLY | O_CREAT  | O_APPEND;  // Add O_APPEND flag
  else
  {
    if(argv[3][0] != 'x')
    {
      fprintf(stderr, "Usage: %s filename num-bytes [x] \n",argv[0]);
      exit (EXIT_FAILURE);
    }

    flag = O_WRONLY | O_CREAT ;             // No O_APPEND flag

  }
  filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; /* rw-rw-rw*/;
  /* Open the file */
  if((fd=open(argv[1],flag,filePerms))== -1)
  {
    perror ("Error open file \n");
    exit (EXIT_FAILURE);
  }

  num_bytes = atol(argv[2]);  // Take number of bytes
  for (int i =0; i< num_bytes; i++)
  {
    if(argc == 3)
    {
      // Write value into file
      if((numWritten = write(fd,"h",1)) ==-1)
      {
          perror ("Error write \n ");
          exit (EXIT_FAILURE);
      }
    }
    else // argc == 4
    {

      if(offset = lseek(fd,0,SEEK_END) == -1)    // Move fd at the end because this option does not have O_APPEND
      {
          perror("Error lseek \n");
          exit (EXIT_FAILURE);
      }
      // Write value into file
      if((numWritten = write(fd,"h",1)) ==-1)
      {
          perror ("Error write \n ");
          exit (EXIT_FAILURE);
      }
    }
  } // End for

  close(fd);
  exit(EXIT_SUCCESS);
}
