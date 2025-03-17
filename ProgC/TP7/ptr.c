#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void f(){
  int* p;
  p = malloc(100 * sizeof(int));

  if (p != NULL){
    printf("true \n");
  } else {
    printf("false \n");
  }
}
   
int main() {
    int *p = NULL;
    f();
    printf("Contenu de *p : %d\n", *p);
    return EXIT_SUCCESS;
} 