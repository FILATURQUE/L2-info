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
    c = *a;
    *a = *b; 
    *b = c;
}
   
  
    /* int x = 123;
    int y = 456;
    printf("Before: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After: x = %d, y = %d\n", x, y);
    
    prl; */

int main() {
    /* char c = 'c'; char* ptr_c = &c;
    char v = 'v'; char* ptr_v = &v;
    int i = 132; int* ptr_i = &i;
    double d = 43.12; double* ptr_d = &d;

    printf("prt_c = %p\n", ptr_c);
    printf("prt_i = %p\n", ptr_i); 
    printf("ptr_d = %p\n", ptr_d); prl;

    // + 1 en hexadecimal pour le char 
    printf("prt_c = %p\n", ptr_c + 1);
    // + 4 en hexadecimal pour le int 
    printf("prt_i = %p\n", ptr_i + 1);
    // + 8 en hexadecimal pour le double'v'
    printf("ptr_d = %p\n", ptr_d + 1); prl;

    // Valeur pointee par le pointeur
    printf("Valeur pointe par ptr_c: %d\n",*ptr_c);
    printf("Valeur pointe par ptr_i: %d\n",*ptr_i);
    printf("Valeur pointe par ptr_d: %g\n",*ptr_d); prl;

    // Adresse contenu par le pointeur
    printf("Valeur pointe par ptr_c: %p\n",ptr_c);
    printf("Valeur pointe par ptr_i: %p\n",ptr_i);
    printf("Valeur pointe par ptr_d: %p\n",ptr_d); prl;

    // L'adresse du pointeur
    printf("Valeur pointe par ptr_c: %p\n",&ptr_c);
    printf("Valeur pointe par ptr_i: %p\n",&ptr_i);
    printf("Valeur pointe par ptr_d: %p\n",&ptr_d); prl;

    // différence entre (ptr_t + 1) - ptr_t
    printf("%ld\n",(ptr_i + 1) - ptr_i);
    // difference entre un (ptr_t + 1) - ptr_t mais avec un cast long pour les deux 
    printf("%ld\n",(long)(ptr_i + 1) - (long)ptr_i);
    // difference entre un ptr_c - ptr_d 
    printf("%ld\n",(double*)ptr_c - ptr_d); prl;

    printf("AVANT c: %c, v: %c\n", *ptr_c, *ptr_v);
    swap_charptr(&ptr_c,&ptr_v);
    printf("APRES c: %c, v: %c\n", *ptr_c, *ptr_v); prl;

    char b; char* ptr_b = &b;  
    printf("ptr_c %p\n",*ptr_c);
    printf("ptr_b %p\n",*ptr_b);
    printf("AVANT c: %c, b: %c\n", *ptr_c, *ptr_b); 
    swap_charptr(&ptr_c,&ptr_b);
    printf("APRES c: %c, b: %c\n", *ptr_c, *ptr_b);
    printf("ptr_c %p\n",*ptr_c);
    printf("ptr_b %p\n",*ptr_b); prl; */

    unsigned int i;
    printf("Veuillez entrer un entier : ");
    scanf("%u", &i);
    printf("Vous avez entré %d\n", i);

    char s[5] = "\0\0\0\0\0"; 
    printf("Veuillez entrer une chaîne : ");
    scanf("%5s", s);
    printf("Vous avez entré %5s\n", s);

    char * c[4] = {"ENTER","NEW","POINT","FIRST"};
    char ** cp[4] = { c+3, c+2, c+1, c};
    char *** cpp = cp;
  
    printf("%s",**++cpp);
    printf("%s ",*--*++cpp+3);
    printf("%s",*cpp[-2]+3);
    printf("%s\n",cpp[-1][-1]+1);

    return EXIT_SUCCESS;      
}

