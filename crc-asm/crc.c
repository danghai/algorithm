#define POLYNOMIAL 0xD5
#include <stdio.h>

static char crcTable[256] = {0}; /* Global Initialized to 0. DATA Segment*/

void crcInit(void)
{
  char remainder;
  int dividend;
  char bit;

  /*
   * Compute the remainder of each possible dividend.
   */
  for (dividend = 256; dividend > 0; --dividend)
  {
      /*
       * Start with the dividend followed by zeros.
       */
      remainder = dividend;

      /*
       * Perform modulo-2 division, a bit at a time.
       */
      for (bit = 8; bit > 0; --bit)
	{
	  /*
	   * Try to divide the current data bit.
	   */
	  if (remainder & 0x80)
	    {
	      remainder = (remainder << 1) ^ POLYNOMIAL;
	    }
	  else
	    {
	      remainder = (remainder << 1);
	    }
	}

      /*
       * Store the result into the table.
       */
      crcTable[dividend] = remainder;
    }

}

char crcFast(char* message, long nBytes)
{
  unsigned char data;
  char remainder = 0;
  long byte;

  /*
   * Divide the message by the polynomial, a byte at a time.
   */
  for (byte = 0; byte < nBytes; ++byte)
    {
      data = message[byte] ^ remainder;
      remainder = crcTable[data];
    }

  /*
   * The final remainder is the CRC.
   */
  return remainder;
}
