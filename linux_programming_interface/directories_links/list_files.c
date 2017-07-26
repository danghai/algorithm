/*
    Name: Hai Dang Hoang
    Email: goldsea5191@gmail.com

    list_file.c: uses opendir(), readdir(), and closedir() to list the contents
    of each of the directories specified in its command line (or in the current
    working directory if no arguments are supplied).
*/
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
int main(int argc, char * argv[])
{
  DIR *dir;
  struct dirent *dp;
  if(argc > 2)
  {
      fprintf(stderr,"Usage: %s [directory] \n",argv[0]);
      exit(EXIT_FAILURE);
  }
  else if(argc == 1)  // No arguments
  {
      if((dir = opendir(".")) == NULL)  // Open current directory
      {
          perror ("Cannot open directory \n");
          exit(EXIT_FAILURE);
      }
      // List all file
      while((dp= readdir(dir)) != NULL)
      {
          if(strcmp(dp-> d_name,".")== 0 || strcmp(dp-> d_name,"..")==0)
            continue;         // Skip . and  ..
          printf ("%s \n", dp->d_name);
      }
      // Close directory
      if((closedir(dir)) == -1 )
      {
          perror ("Cannot close directory \n");
          exit(EXIT_FAILURE);
      }
      exit(EXIT_SUCCESS);
  }
  else  // 2 arguments
  {
    if((dir = opendir(argv[1])) == NULL)  // Open current directory
    {
        perror ("Cannot open directory \n");
        exit(EXIT_FAILURE);
    }
    // List all file
    while((dp= readdir(dir)) != NULL)
    {
        if(strcmp(dp-> d_name,".")== 0 || strcmp(dp-> d_name,"..")==0)
          continue;         // Skip . and  ..
        printf ("%s \n", dp->d_name);
    }
    // Close directory
    if((closedir(dir)) == -1 )
    {
        perror ("Cannot close directory \n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
  }
  exit(EXIT_SUCCESS);
}
