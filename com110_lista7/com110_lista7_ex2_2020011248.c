#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int matriz[8][8];
    int i, j, num;

    printf("Preencha a matriz com numeros inteiros.\n");
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            printf("Posicao [%d][%d]: ", i + 1, j + 1);
            scanf(" %d", &matriz[i][j]);
        }
    }

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (matriz[i][j] == matriz[j][i])
            {
                num++;
            }
        }
    }

    if (num == 16)
    {
        printf("A matriz e simetrica.");
    }
    else
    {
        printf("A matriz não é simetrica.");
    }

    return 0;
}