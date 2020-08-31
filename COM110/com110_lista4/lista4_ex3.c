#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcao = 0;
    printf("------MENU------\n");
    printf("1) Pizza\n");
    printf("2) Hamburguer\n");
    printf("3) Cookie\n");

    while (opcao != 1 && opcao != 2 && opcao != 3)
    {
        printf("Qual e sua escolha? ");
        scanf("%i", &opcao);
        if (opcao != 1 && opcao != 2 && opcao != 3){
            printf("Opcao invalida! Tente novamente.\n");
        }
        else
        {
            printf("Otima escolha! Seu pedido ficara pronto logo logo.");
        }
    }
    
    return 0;
}