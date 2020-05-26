#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int numeros[8], j, i, num;

    for (i = 0; i < 8; i++)
    {
        printf("Digite os numeros: ");
        scanf("%d", &numeros[i]);
    }

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if (numeros[j] < numeros[i])
            {
                num = numeros[j];
                numeros[j] = numeros[i];
                numeros[i] = num;
            }
        }
    }

    printf("Os valores em ordem crescente sao: ");
    for (i = 7; i > -1; i--)
    {
        printf("%d ", numeros[i]);
    }

    return 0;
}