#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero, num2 = 0, max, min;
    do {
        printf("Digite um numero inteiro positivo para adiciona-lo: ");
        scanf("%i", &numero);
        if (numero < 0) {
            break;
        }
        if (num2 == 0) {
            max = min = numero;
        }
        if (numero > max) {
            max = numero;
        }
        if (numero < min) {
            min = numero;
        }
        num2 = numero;
    } while (numero >= 0);
    printf("O maior numero digitado foi %i e o menor foi %i.", max, min);

    return 0;
}