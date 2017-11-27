#include <termios.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

char *getpass(const char *);

#define MAX_PASS_LEN 8    /* Maximum character for user to enter */

char *
getpass(const char *prompt){
  static char buf[MAX_PASS_LEN + 1];   /* Null byte at end */
  char            *ptr;
  sigset_t        sig, osig;
  struct termios  ts, ots;
  FILE            *fp;
  int             c;
  char            termid[1025];

  if (ctermid(termid) == NULL){
    perror("ctermid() error \n");
    return NULL;
  }
  printf ("The control terminal is %s \n",termid);

  if((fp = fopen(termid,"+r")) == NULL){
    perror ("fopen \n");
    return (NULL);
  }

  setbuf(fp, NULL);

  sigemptyset(&sig);
  sigaddset(&sig, SIGINT);  /* block SIGINT */
  sigaddset(&sig, SIGTSTP); /* block SIGTSTP */
  sigprocmask(SIG_BLOCK, &sig, &osig); /* and save mask */

  tcgetattr(fileno(fp), &ts);     /* save tty state */
  ots = ts;                       /* structure copy */
  ts.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL);
  tcsetattr(fileno(fp), TCSAFLUSH, &ts);

  fputs(prompt,fp);

  ptr = buf;
  while ((c = getc(fp)) != EOF && c != '\n')
      if (ptr < &buf[MAX_PASS_LEN])
          *ptr++ = c;
  *ptr = 0;                  /* null terminate */
  putc('\n', fp);            /* we echo a newline */

  tcsetattr(fileno(fp), TCSAFLUSH, &ots); /* restore TTY state */
  sigprocmask(SIG_SETMASK, &osig, NULL);  /* restore mask */
  fclose(fp);         /* done with /dev/tty */
  return(buf);
}

int
main(void)
{
    char   *ptr;

    if ((ptr = getpass("Enter password:")) == NULL)
        perror("ptr = NULL \n");
    printf("password: %s\n", ptr);

    /* now use password (probably encrypt it) ... */

    while (*ptr != 0)
        *ptr++ = 0;      /* zero it out when we're done with it */
    exit(0);
}
