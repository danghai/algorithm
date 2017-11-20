/*  no_echo.c: demonstrates the use of tcgetattr() and tcsetattr()
*   to turn off the ECHO flag, so that input characters are not echoed.
*/

#include <termios.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 100

int main(int argc, char *argv[]){
    struct termios tp,save;
    char buf[BUF_SIZE];

    /* Retrieve current terminal setting, turn echoing off*/
    if(tcgetattr(STDIN_FILENO, &tp) == -1)
      perror ("tcgetattr ");
    save = tp;                /* Restore settings later */
    tp.c_lflag &= ~ECHO;      /* ECHO off, other bits unchanged */
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &tp) == -1)
      perror ("tcsetattr");

    /* Read some input and then display it back to the user */
    printf ("Enter text: ");
    fflush(stdout);
    if(fgets(buf,BUF_SIZE,stdin) == NULL)
      perror("fgets");
    else
      printf("\nRead: %s",buf);

    /* restore original terminal setting */
    if(tcsetattr(STDIN_FILENO, TCSANOW, &save) == -1)
      perror ("tcsetattr");
  exit(0);
}
