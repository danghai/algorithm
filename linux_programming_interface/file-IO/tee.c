/*
  Name: Hai Dang Hoang
  Email: goldsea5191@gmail.com

  The tee command reads its standard input until end-of-file, writing a copy
  of the input to standard output and to the file named in its command-line
  argument. By default, tee overwrites any existing file with the given name.
  Implement the -a command-line option (tee -a file),  which causes
  tee to append text to the end of a file if it already exists.
*/
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
  int flag_command = 0;
  int fd;
  mode_t filePerms;
  ssize_t numRead, numWritten1, numWritten2;
  int flag;
  char buf[BUF_SIZE];
  off_t offset;
  if(argc < 2 )
  {
    perror("Error argument");
    exit(EXIT_FAILURE);
  }
  /* Set parameter open file */
  filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; /* rw-rw-rw*/;
  flag = O_WRONLY | O_CREAT  | O_APPEND;
  /* Parse command-line*/
  while((opt = getopt(argc, argv, "a")) !=-1)
  {
    switch(opt)
    {
      case 'a':         //  -a command-line
        flag_command  = 1; // It has command
        break;
      default:
        fprintf(stderr, "Usage: %s [-a] filename \n",argv[0]);
        exit(EXIT_FAILURE);
    }
  }  // end while


  if(flag_command ==  0)    // no parameter --> Create or open the file same name with first argument
  {
    if((fd = open(argv[1],flag,filePerms)) == -1)
    {
      perror ("Error open the file \n");
      exit (EXIT_FAILURE);
    }
  }
  else
  {
  /* Open the file */
    if((fd = open(argv[2],flag,filePerms)) == -1)
    {
      perror ("Error open the file \n");
      exit (EXIT_FAILURE);
    }
  }

  /* Read from standard input until end-of-file and put them in buffer,
      and then write buffer to file and standard output*/
  while ((numRead = read(STDIN_FILENO, buf,BUF_SIZE))!=0)
  {
    if(numRead == -1)
    {
      if (errno = EINTR)
        continue;
      perror("Error read the file \n");
      break;
    }

    // Write to standard output
    if((numWritten1 = write(STDOUT_FILENO,buf,numRead)) == -1 )
    {
      perror("Error write to the standard output \n");
      exit(EXIT_FAILURE);
    }

    // Write to file (append at the end)
    if((numWritten2 = write(fd,buf,numRead)) == -1)
    {
      perror("Error write to the file \n");
      exit(EXIT_FAILURE);
    }
  } // end while

  exit(EXIT_SUCCESS);
}
