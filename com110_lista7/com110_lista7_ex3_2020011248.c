#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int matriz[5][7], min, max, linha, coluna;
    int i, j;

    //PREENCHE A MATRIZ
    printf("Preencha a matriz com numeros inteiros diferentes.\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 7; j++)
        {
            printf("Posicao [%d][%d]: ", i + 1, j + 1);
            scanf(" %d", &matriz[i][j]);
        }
    }

    //ENCONTRA O MENOR NÚMERO
    min = matriz[0][0];
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if (matriz[i][j] < min)
            {
                min = matriz[i][j];
            }
        }
    }

    //DEFINE A LINHA ONDE ESTÁ O MENOR NÚMERO
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if (min == matriz[i][j])
            {
                linha = i;
            }
        }
    }

    //ENCONTRA O MAIOR ELEMENTO DA LINHA
    max = min;
    for (j = 0; j < 7; j++)
    {
        if (matriz[linha][j] > max)
        {
            max = matriz[linha][j];
        }
    }
    printf("O MINMAX desta matriz e o valor %d", max);

    return 0;
}