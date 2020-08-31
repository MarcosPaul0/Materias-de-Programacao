#include <stdio.h>
#include <stdlib.h>

int main() {
    float num1, num2, adicao, subtracao, multiplicacao, divisao;
    char resposta;
    do {printf("Digite dois numeros Reais: ");
        scanf("%f%f", &num1, &num2);

        adicao = num1 + num2;
        subtracao = num1 - num2;
        multiplicacao = num1 * num2;
        divisao = num1 / num2;

        printf("----------------------\n");
        printf("%.2f + %.2f = %.2f\n", num1, num2, adicao);
        printf("%.2f - %.2f = %.2f\n", num1, num2, subtracao);
        printf("%.2f x %.2f = %.2f\n", num1, num2, multiplicacao);
        printf("%.2f / %.2f = %.2f\n", num1, num2, divisao);
        printf("----------------------\n\n");
        printf("Deseja repetir? [s/n] ");
        scanf(" %c", &resposta);
    } while (resposta == 's');
    printf("\nObrigado por utilizar este programa!");

    return 0;
}