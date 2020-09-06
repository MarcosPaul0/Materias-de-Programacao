#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int fatorial(int num) {
    if (num <= 0) {
        return 1;
    }
    return num * fatorial(num - 1);
}

int main() {
    int numero;

    setlocale(LC_ALL, "Portuguese");

    printf("Digite um número inteiro: ");
    scanf(" %d", &numero);
    while (numero <= 0) {
        printf("Número Inválido!\nTente Novamente");
        scanf(" %d", &numero);
    } 
    
    printf("Fatorial de [%d] é [%d].", numero, fatorial(numero));
    
    return 0;
}