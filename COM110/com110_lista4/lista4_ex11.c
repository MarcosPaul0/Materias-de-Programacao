#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero = 1;
    printf("De 1 a 20 -> ");
    while (numero <= 20) {
        printf("%i  ", numero);
        numero++;
    }
    printf("\n");
    printf("De 20 a 1 -> ");
    numero = 20;
    while (numero >= 1) {
        printf("%i  ", numero);
        numero--;
    }
    printf("\n");
    printf("De 1 a 20 somente os impares -> ");
    while (numero < 20) {
        if (numero % 2 != 0) {
            printf("%i  ", numero);
        }
        numero++;
    }

    return 0;
}