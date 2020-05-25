#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int matriz[5][7], min_line, max_colunm;
    int i, j;
    int linha[5], coluna[7], num_line, num_colunm;

    //PREENCHE A MATRIZ
    printf("Preencha a matriz com numeros inteiros.\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 7; j++)
        {
            printf("Posicao [%d][%d]: ", i +1, j + 1);
            scanf(" %d", &matriz[i][j]);
        }
    }
    
    //ENCOTRA O MENOR VALOR DE CADA LINHA
    for (i = 0; i < 5; i++)
    {
        min_line = matriz[i][0];
        for (j = 0; j < 7; j++)
        {
            if (matriz[i][j] <= min_line)
            {
                min_line = matriz[i][j];
            }
            linha[i] = min_line;
        }
    }

    //ENCONTRA O MAIOR VALOR DE CADA COLUNA
    for (j = 0; j < 7; j++)
    {
        max_colunm = 0;
        for (i = 0; i < 5; i++)
        {
            if (matriz[i][j] > max_colunm)
            {
                max_colunm = matriz[i][j];
            }
            coluna[j] = max_colunm;
        }
    }

    //COMPARA O MENOR VALOR DE CADA LINHA COM O MAIOR VALOR DE CADA COLUNA
    for (i = 0; i < 5; i++)
    {
        num_line = linha[i];
        for (j = 0; j < 7; j++)
        {
            num_colunm = coluna[j];
            if (num_line == num_colunm)
            {
                printf("Na posicao [%d][%d], foi encontrado um Ponte de Cela com valor %d.", i + 1, j + 1, num_line);
            }
        }
    }
    

    return 0;
}