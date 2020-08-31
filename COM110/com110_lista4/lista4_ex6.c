#include <stdio.h>
#include <stdlib.h>

int main() {
    float peso, altura, imc;
    char resposta;

    printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Indice de Massa Corporal\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    do {
        printf("Digite seu peso e sua altura respectivamente: ");
        scanf("%f%f", &peso, &altura);
        imc = peso / (altura * altura);
        if (imc < 18.5){
            printf("Seu IMC e de %.1f -> Magreza\n", imc);
        }
        if (imc >= 18.5 && imc <= 24.9) {
            printf("Seu IMC e de %.1f -> Normal\n", imc);
        }
        if (imc >= 25 && imc <= 29.9){
            printf("Seu IMC e de %.1f -> Sobrepeso\n", imc);
        }
        if (imc >= 30 && imc <= 39.9){
            printf("Seu IMC e de %.1f -> Obesidade\n", imc);
        }
        if (imc >= 40){
            printf("Seu IMC e de %.1f -> Obesidade Grave\n", imc);
        }
        printf("Deseja continuar? [s/n]");
        scanf(" %c", &resposta);
    } while (resposta == 's');
    printf("\nObrigado por utilizar este programa!");

    return 0;
}