/*
*  A simple code to test base64_encode for Tlog. ( Reference from Curl)
*  Run: make
*       ./base64
*/
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

/* ---- Base64 Encoding Table --- */
static const char base64[]=
  "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static int base64_encode(const char *table64,
                         const char *inputbuff, size_t insize,
                         char **outptr, size_t *outlen)
{
   unsigned char ibuf[3];
   unsigned char obuf[4];
   int i;
   int inputparts;
   char *output;
   char *base64data;
   const char *indata = inputbuff;

   *outptr = NULL;
   *outlen = 0;

   if(!insize) {
      insize = strlen(indata);
   }

   base64data = output = malloc(insize * 4 / 3 + 4);
   if(!output) {
    return 1;
   }

   while(insize > 0) {
         for(i = inputparts = 0; i < 3; i++) {
             if(insize > 0) {
                inputparts++;
                ibuf[i] = (unsigned char) *indata;
                indata++;
                insize--;
             }
             else
               ibuf[i] = 0;
         }

         obuf[0] = (unsigned char)  ((ibuf[0] & 0xFC) >> 2);
         obuf[1] = (unsigned char) (((ibuf[0] & 0x03) << 4) | \
                                    ((ibuf[1] & 0xF0) >> 4));
         obuf[2] = (unsigned char) (((ibuf[1] & 0x0F) << 2) | \
                                    ((ibuf[2] & 0xC0) >> 6));
         obuf[3] = (unsigned char)   (ibuf[2] & 0x3F);

         switch(inputparts) {
         case 1: /* only one byte read */
           snprintf(output, 5, "%c%c==",
                    table64[obuf[0]],
                    table64[obuf[1]]);
           break;

         case 2: /* two bytes read */
           snprintf(output, 5, "%c%c%c=",
                    table64[obuf[0]],
                    table64[obuf[1]],
                    table64[obuf[2]]);
           break;

         default:
           snprintf(output, 5, "%c%c%c%c",
                    table64[obuf[0]],
                    table64[obuf[1]],
                    table64[obuf[2]],
                    table64[obuf[3]]);
           break;
         }
         output += 4;
   }

   /* Zero terminate */
   *output = '\0';

   /* Return the pointer to the new data (allocated memory) */
   *outptr = base64data;

    /* Return the length of the new data */
    *outlen = strlen(base64data);

    return 0;
}

/*
 * Tlog_base64_encode()
 *
 * Given a pointer to an input buffer and an input size, encode it and
 * return a pointer in *outptr to a newly allocated memory area holding
 * encoded data. Size of encoded data is returned in variable pointed by
 * outlen.
 *
 * Input length of 0 indicates input buffer holds a NUL-terminated string.
 *
 * Returns 0 on success, otherwise 1 for error code.
 * When encoded data length is 0, returns NULL in *outptr.
 */

static int Tlog_base64_encode(const char *inputbuff, size_t insize,
                              char **outptr, size_t *outlen)
{
  return base64_encode(base64, inputbuff, insize, outptr, outlen);
}

int main (int argc, char * argv[]) {
  char *output;
  size_t size = 0;

  /* Suppose output: Output encode: aQ==, Size: 4 */
  Tlog_base64_encode("i", 1, &output, &size);
  printf("Output encode: %s, Size: %d\n", output, size);

  /* Suppose output: Output encode: aWk=, Size: 4 */
  Tlog_base64_encode("ii", 2, &output, &size);
  printf("Output encode: %s, Size: %d\n", output, size);

  /* Suppose output: Output encode: aWlp, Size: 4*/
  Tlog_base64_encode("iii", 3, &output, &size);
  printf("Output encode: %s, Size: %d\n", output, size);

  /* Suppose output: Output encode: aWlpAA==, Size: 8 */
  Tlog_base64_encode("iii", 4, &output, &size);
  printf("Output encode: %s, Size: %d\n", output, size);

  /* Suppose output: Output encode: TWFu, Size: 4*/
  Tlog_base64_encode("Man", 3, &output, &size);
  printf("Output encode: %s, Size: %d\n", output, size);

  return 0;
}
