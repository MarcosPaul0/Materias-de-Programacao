#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char alfabeto[26] = "abcdefghijklmnopqrstuvwxyz";
    char palavra[10], letra_pa, letra_alfa, codigo;
    int i, j, num;

    printf("Digite uma palavra de 10 letras: ");
    scanf("%s", &palavra);
    printf("Digite o fator de traducao: ");
    scanf("%d", &num);

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 26; j++)
        {
            letra_pa = palavra[i];
            letra_alfa = alfabeto[j];
            if (letra_pa == letra_alfa)
            {
                codigo = alfabeto[j + num];
                printf("%c", codigo);
            }
        }
    }

    return 0;
}