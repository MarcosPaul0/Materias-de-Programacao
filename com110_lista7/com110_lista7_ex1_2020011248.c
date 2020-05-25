#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int M [2][2], R [2][2];
    int max = 0, num, i, j;

    printf("Adicione 4 numeros inteiros para a matriz: ");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            scanf(" %d", &M[i][j]);
            num = M[i][j];
            if (num > max)
            {
                max = num;
            }
        }
    }

    printf("O nova R matriz possui os valores: ");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            R[i][j] = M[i][j] * max;
            printf("R [%d][%d} = %d\n", i + 1, j + 1, R[i][j]);
        }
    }

    return 0;
}