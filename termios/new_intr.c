/*  new_intr.c: changing the terminal interrupt character
*   it uses tcgetattr() and tcsetattr() to change the terminal
*   character. This program sets the interupt  character to be
*   the character whose numeric value is supplied as the program's
*   command-line argument, or disables the interrupt character if no
*   command-line  argument is supplied.
*   Ascii: https://en.wikipedia.org/wiki/ASCII
*   How to use:  ./new_intr 12 --> change intr = ^L
*                stty          --> list information
*                stty sane     --> return terminal to a sane state 
*/
#include <termios.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
  struct termios tp;
  int intrChar;

  if (argc == 1){   /* Disable */
      intrChar = fpathconf(STDIN_FILENO, _PC_VDISABLE);
      if (intrChar == -1)
          perror("Could not determine VDISABLE");
  } else if (isdigit((unsigned char) argv[1][0])) {
      intrChar = strtoul (argv[1], NULL, 0);
  } else {
      intrChar = argv[1][0];
  }

  /* Fetch current terminal setting, modify INTR character, and
     push changes back to the terminal driver */
     if(tcgetattr(STDIN_FILENO, &tp) == -1)
        perror ("tcgetattr");
     tp.c_cc[VINTR] = intrChar;
     if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &tp)== -1)
        perror ("tcsetattr");

    exit(0);

}
