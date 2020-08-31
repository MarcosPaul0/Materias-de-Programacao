#include <stdio.h>
#include <stdlib.h>

int main() {
    int minutos, segundos;
    char resposta;
    do {
        printf("Digite a quantidade de minutos: ");
        scanf("%i", &minutos);
        segundos = minutos * 60;
        printf("Em %i minutos existem %i segundos.\n", minutos, segundos);
        printf("Deseja repetir? [s/n] ");
        scanf(" %c", &resposta);
    } while (resposta == 's');
    printf("\nObrigado por utilizar este programa!");

    return 0;
}