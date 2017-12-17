#include <stdio.h>
#define log_printf(fmt,...) \
    fprintf(stderr,fmt, ##__VA_ARGS__)
int main(void) {
  log_printf("Hello world \n");
  return 0;
}
