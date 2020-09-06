#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int fibonacci (int posicao) {
    if (posicao <= 1) {
        return posicao;
    }
    return fibonacci(posicao - 1) + fibonacci(posicao - 2);
}

int main() {
    int pos;

    setlocale(LC_ALL, "Portuguese");

    printf("Digite a posição na sequência de fibonacci: ");
    do
    {
        scanf(" %d", &pos);
    } while (pos <= 0);
    
    printf("O número na %dº posição é %d", pos, fibonacci(pos));

    return 0;
}