#include <stdio.h>

#define X 10
#define Y 0
#define Z 100

int main(void) {

int x = 10, y = 0, z = 100;

#ifndef X
    printf("x is %d\n", X);
#elif y
    printf("y is %d\n", Y);
#else
    printf("z is %d\n", Z);
#endif

    return 0;
}
