#include <stdlib.h>
#include <stdio.h>

int main() {
    int hora;
    char resposta;

    do {
        printf("Que horas são atualmente? ");
        scanf("%i", &hora);
        if (hora >= 5 && hora <= 11){
            printf("Estamos no horário da Manhã\n");
        }
        if (hora >= 12 && hora <= 17){
            printf("Estamos no horário da Tarde\n");
        }
        if (hora >= 18 && hora <= 4){
            printf("Estamos no horário da Noite\n");
        }
        printf("Deseja continuar? [s/n]");
        scanf(" %c", &resposta);
    } while (resposta == 's');

    return 0;
}
