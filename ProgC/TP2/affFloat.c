#include <stdlib.h>
#include <stdio.h>
#include <float.h>
 
int main() {
  printf("Size of float: %lu\n", sizeof(float));
  printf("Min/Max value of a float: %.5g/%.5g\n", FLT_MIN, FLT_MAX);
  printf("Precision of a float: %u digits\n\n", FLT_DIG);
  printf("Size of double: %lu\n", sizeof(double));
  printf("Min/Max value of a double: %.5g/%.5g\n", DBL_MIN, DBL_MAX);
  printf("Precision of a double: %u digits\n\n", DBL_DIG);
  printf("Size of long double: %lu\n", sizeof(long double));
  printf("Min/Max value of a long double: %.5Lg/%.5Lg\n", LDBL_MIN,LDBL_MAX);
  printf("Precision of a long double: %u digits\n", LDBL_DIG);
  return EXIT_SUCCESS;
}