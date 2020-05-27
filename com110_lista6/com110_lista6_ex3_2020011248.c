#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num_sorteado[20], i, m, numeros[6] = {1, 2, 3, 4, 5, 6}, aparicoes = 0;

    for (i = 0; i < 20; i++)
    {
        num_sorteado[i] = rand() %10;
    }
    
    printf("\n\nOs numeros sorteados foram: ");
    for (i = 0; i < 20; i++)
    {
        printf("%d ", num_sorteado[i]);
    }
    printf("\n\n");

    for (m = 0; m < 6; m++)
    {
        for (i = 0; i < 20; i++)
        {
            if (numeros[m] == num_sorteado[i])
            {
                aparicoes += 1;
            }
        }
        printf("O numero %d apareceu %d vezes.\n", m +1, aparicoes);
        aparicoes = 0;
    }
    

    return 0;
}