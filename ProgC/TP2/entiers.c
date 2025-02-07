#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
 
int main () {
  printf("Size of char: %lu\n", sizeof(char));
  printf("Signed char min/max: %hhd/%hhd\n", CHAR_MIN, CHAR_MAX );
  printf("Unsigned char min/max: %hhu/%hhu\n", 0, UCHAR_MAX );
  printf("Size of short: %lu\n", sizeof(short));
  printf("Signed short min/max: %hd/%hd\n", SHRT_MIN, SHRT_MAX );
  printf("Unsigned short min/max: %hu/%hu\n", 0, USHRT_MAX );
  printf("Size of int: %lu\n", sizeof(int));
  printf("Signed int min/max: %d/%d\n", INT_MIN, INT_MAX );
  printf("Unsigned int min/max: %u/%u\n", 0, UINT_MAX );
  printf("Size of long: %lu\n", sizeof(long));
  printf("Signed long min/max: %ld/%ld\n", LONG_MIN, LONG_MAX );
  printf("Unsigned long min/max: %lu/%lu\n", 0L, ULONG_MAX );
  printf("Size of llong: %lu\n", sizeof(long long)); 
  printf("Signed llong min/max: %lld/%lld\n", LLONG_MIN, LLONG_MAX );
  printf("Unsigned llong min/max: %llu/%llu\n", 0LL, ULLONG_MAX );
  return EXIT_SUCCESS;
}