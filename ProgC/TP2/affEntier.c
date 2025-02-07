#include <stdio.h>
#include <stdlib.h>

int main() {
    long entiers[10] = { 0, -0, -1, 11, 96, 4567, -255, 582, 2147483700, 4294967416 };

    for (int i = 0; i < 10; i++) {
        // Utilisation du cast en unsigned long pour éviter le warning d'overflow
        printf("entiers[%d] = %ld\n", i,entiers[i]);
    }

    return EXIT_SUCCESS;
}
