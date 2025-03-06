#include <stdlib.h>
#include <stdio.h>

int* f(int n) {
    int j;
    int* q;
    printf("  0 - In f: %p, %d\n", &n, n);
    q = &j;
    printf("  1 - In f: %p, %d\n", q, *q);
    j = n;
    printf("  2 - In f: %p, %d\n", q, *q);
    return q;
  }
   
  void* g(int n) {
    int k;
    int* r;
    printf("  0 - In g: %p, %d\n", &n, n);
    r = &k;
    printf("  1 - In g: %p, %d\n", r, *r);
    k = n;
    printf("  2 - In g: %p, %d\n", r, *r);
    return NULL;
  }
   
  int main() {
    int i = 0;
    int* p = &i;
    printf("Before f: %p, %d\n", p, *p);
    p = f(1234);
    printf("After f: %p, %d\n", p, *p);
    g(4321);
    printf("After g: %p, %d\n", p, *p);
    return EXIT_SUCCESS;
  } 