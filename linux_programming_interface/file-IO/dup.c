/*
    Name : Hai Dang Hoang
    Email: goldsea5191.com

    dup.c: Implement dup(), dup2() using fcntl().
    main: Use for testing my_dup function by sharing between fd1, fd2, fd3, fd4

    my_dup(): According to dup (man 2 dup), it uses the lowest-numbered unused
    descriptor for the new descriptor.

    my_dup2(): makes newfd be the copy of oldfd, closing newfd first
              + If oldfd is not a valid file descriptor, then the call fails, and
                newfd is not closed

              + If oldfd is a valid file descriptor, and newfd has sthe same value
                as oldfd, then dup2() does nothing, and returns newfd.

    After a successful return from one of these system calls, the old and new file
    descriptors may be used together because they refer to the same open file description
    Therefore, they share file offset and file status flags; for example, if the file
    offset is modified by using lseek() on one of the descriptors, the offset is also changed
    for the other.

    $ ./dup <filename>                --> Only test my_dup
    $ ./dup <filename1> <filename2>   --> Test my_dup() and my_dup2()

*/
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int my_dup(int);
int my_dup2(int, int);

int main(int argc, char * argv[])
{
  int fd1, fd2, fd3;

  fd1 =   open(argv[1], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
  // Test my_dup function using fctnl();
  fd2 =   my_dup(fd1);              // it will share fd1 and fd2
  fd3 =   open(argv[1], O_RDWR);    // it will not sare fd1 and fd3
  write(fd1,"Hello ",6);            // Output: Hello
  write(fd2,"World ",6);            // Output: Hello Wrold ( because fd1 and fd2 share offset together)
  lseek(fd2,0,SEEK_SET);            // Move offset at beginning
  write(fd1, "HELLO,",6);           // Overwrite --> output HELLO World
  write(fd3,"Gidday ", 7);          // fd1 and fd3 are not share offset together --> Output: gidday World

  // Test my_dup2 function
  if(argc == 3)
  {
    int fd4;
    fd4 = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    write(fd4,"Trammie Le Duong ",17); // Open new file (fd4) and write 17 bytes
    fd4 = my_dup2(fd2,fd4);            // duplicate fd2 and save at fd4
    write(fd4," Hai Dang",9);          // Output will Gidday Hai Dang because fd4 and fd2 now share offset
                                       // <filename2> still remains because fd4 now share with fd2
    close(fd4);
  }

  close(fd1);
  close(fd2);
  close(fd3);

  exit(EXIT_SUCCESS);
}

int my_dup(int oldfd)
{
  int fd;
  if((fd=fcntl(oldfd, F_DUPFD,0)) == -1)   // man 2 fcntl to know information flag F_DUPFD
  {
    perror ("Error fcntl \n");
    return -1;
  }
  return fd;
}

int my_dup2(int oldfd, int newfd)
{
  // Check if oldfd is not valid --> Error for duplicating
  if(fcntl(oldfd,F_GETFL) < 0)
  {
    perror ("oldfd is not valid \n");
    return -1;
  }

  // oldfd  == newfd
  if(oldfd == newfd)
    return newfd;

  // Check to see if newfd is open
  	int ret = fcntl(newfd, F_GETFD);
  	if (ret < 0 && errno != EBADF)
  		return -1;
  	else if (ret >= 0)
  		close(newfd);

  	return fcntl(oldfd, F_DUPFD, newfd);
}
