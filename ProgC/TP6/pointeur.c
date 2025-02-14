#include <stdlib.h>
#include <stdio.h>
#define prl  printf("\n");

void swap(int* a, int* b) {
    int c;
    printf("Before: a = %d, b = %d\n", *a, *b);
    c = *a; *a = *b; *b = c;
    printf("After: a = %d, b = %d\n", *a, *b);
  }

void swap_charptr(char** a, char** b){
    char* c;
    printf("before: a = %s, b = %s\n", *a, *b);
    c = *a; *a = *b; *b = c;
    printf("After: a = %s, b = %s\n", *a, *b);
}
   
  int main() {
    /* int x = 123;
    int y = 456;
    printf("Before: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After: x = %d, y = %d\n", x, y);
    
    prl;

    char c = 'c'; char* ptr_c = &c;
    int i; int* ptr_i = &i;
    double d; double* ptr_d = &d;

    printf("Valeur contenue par le pointeur \n");
    printf("c: %hhd \n",*ptr_c);
    printf("i: %d \n",*ptr_i);
    printf("d: %f \n",*ptr_d); prl;

    printf("Adresse du pointeur \n"); 
    printf("prt_c = %p\n", ptr_c);
    printf("prt_i = %p\n", ptr_i);
    printf("prt_d = %p\n", ptr_d); prl;

    printf("Valeur du pointee \n");
    printf("c: %hhd \n",c);
    printf("i: %d \n",i);
    printf("d: %f \n",d); prl;

    // Ca change rien du tout de cast le long.
    int a = ((long)ptr_c + 1) - (long)ptr_c;
    printf("ptr_c :%d \n",a);

    a = ((double*)ptr_c) - ptr_d;
    printf("ptr_c - ptr_d :%d \n",a); prl;

    char* v = "owo";
    char* s = "uwu";
    swap_charptr(&v,&s); prl;

    char b = 'a'; char* ptr_b = &b;
    swap_charptr(&ptr_b,&ptr_c); prl; */

    /* char s[5] = "\0\0\0\0\0"; 
    printf("Veuillez entrer une chaîne : ");
    scanf("%4s", s);
    printf("Vous avez entré %4s\n", s); */

    char * c[4] = {"ENTER","NEW","POINT","FIRST"};
    char ** cp[4] = { c+3, c+2, c+1, c};
    char *** cpp = cp;
    
    printf("%s",**++cpp);
    printf("%s ",*--*++cpp+3);
    printf("%s",*cpp[-2]+3);
    printf("%s\n",cpp[-1][-1]+1);
    
    return EXIT_SUCCESS;
  } 