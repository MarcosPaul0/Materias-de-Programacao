#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char palavra[10];
    int contador;

    printf("Digite uma palavra de 10 letras: ");
    for (contador = 0; contador < 10; contador++)
    {
        scanf("%c", &palavra[contador]);
    }
    
    printf("O inverso da palavra e: ");
    for (contador = 9; contador > -1; contador--)
    {
        printf("%c", palavra[contador]);
    }
    

    return 0;
}