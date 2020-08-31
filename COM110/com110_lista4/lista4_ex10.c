#include <stdio.h>
#include <stdlib.h>

int main() {
    int dia_nas, mes_nas, ano_nas, dia_atu, mes_atu, ano_atu, idade;
    char resposta;
    do {printf("Digite o dia, mes e ano atual: ");
        scanf("%i%i%i", &dia_atu, &mes_atu, &ano_atu);
        printf("Digite o dia, mes e ano de seu nascimento: ");
        scanf("%i%i%i", &dia_nas, &mes_nas, &ano_nas);
        if (dia_atu >= dia_nas) {
            if(mes_atu >= dia_nas) {
                idade = ano_atu - ano_nas;
                printf("Voce possui %i anos.", idade);
            }
            else {
                idade = ano_atu - ano_nas - 1;
                printf("Voce possui %i anos.", idade);
            }
        }
        if (dia_atu < dia_nas) {
            if (mes_atu > mes_nas) {
                idade = ano_atu - ano_nas;
                printf("Voce possui %i anos.", idade);
            }
            else {
                idade = ano_atu - ano_nas - 1;
                printf("Voce possui %i anos.", idade);
            }
        }
        printf("Deseja repetir? [s/n]");
    } while (resposta == 's');

    return 0;
}
