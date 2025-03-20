#include <stdlib.h>
#include <stdio.h>
 
int main() {
  /* int *p = NULL;
  printf("Contenu de *p : %d\n", *p);
   */

  /* int *p ;
  p = malloc(100*(sizeof(int)));
  int i = 0;
  for(;;){
    printf("Adresse de p: %p, valeur de p: %d et valeur i: %d \n",&p,p[i],i);
    i++;
  } */

  int* p1;
  p1 = malloc(100 * sizeof(int));
  printf("AVANT:\n");
  for(int i = 0; i < 100; i++){
    p1[i] = i;
    printf("Adresse p1: %p, Entier du tableau: %d, a l'index i: %d \n",&p1,p1[i],i);
  }
  printf("APRES:\n");
  free(p1);
  int* p2;
  p2 = malloc(100 * sizeof(int));
  for(int i = 0; i < 100; i++){
    // p2[i] = i;
    printf("Adresse p2: %p, Entier du tableau: %d, a l'index i: %d \n",&p2,p1[i],i);
  }
  free(p2+1);
  return EXIT_SUCCESS;
}