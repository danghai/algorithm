#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
int main(void) {
    struct termios attribs;
    speed_t speed;
    if(tcgetattr(STDIN_FILENO, &attribs) < 0) {
        perror("stdin");
        return EXIT_FAILURE;
    }
    /*
     * The following mess is to retrieve the input
     * speed from the returned data. The code is so messy,
     * because it has to take care of a historic change in
     * the usage of struct termios. Baud rates were once
     * represented by fixed constants, but later could also
     * be represented by a number. cfgetispeed() is a far
     * better alternative.
     */
    if(attribs.c_cflag & CIBAUDEXT) {
        speed = ((attribs.c_cflag & CIBAUD) >> IBSHIFT)
                 + (CIBAUD >> IBSHIFT) + 1;
    }
    else
    {
        speed = (attribs.c_cflag & CIBAUD) >> IBSHIFT;
    }
    printf("input speed: %ul\n", (unsigned long) speed);
    /*
     * Check if received carriage-return characters are
     * ignored, changed to new-lines, or passed on
     * unchanged.
     */
    if(attribs.c_iflag & IGNCR) {
        printf("Received CRs are ignored.\n");
    }
    else if(attribs.c_iflag & ICRNK)
    {
        printf("Received CRs are translated to NLs.\n");
    }
    else
    {
        printf("Received CRs are not changed.\n");
    }
    return EXIT_SUCCESS;
}
