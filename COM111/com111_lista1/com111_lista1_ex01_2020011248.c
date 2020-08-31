#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void preencheVetor(int *p, int linhas, int colunas) {
    for (int i = 0; i < linhas * colunas; i++)
    {
        printf("Preencha o vetor na posição [%d]: ", i + 1);
        scanf(" %d", &p[i]);
    }
}

void imprimeVetor(int *p, int linhas, int colunas) {
    printf("\n\nOs números do vetor são:\n\n");
    for (int i = 0; i < linhas * colunas; i++) {
        printf("%d", p[i]);
        if (i < linhas * colunas - 1)
        {
            printf(" - ");
        }
    }
    printf("\n\n");
}

void preencheMatriz(int **p, int *v, int linhas, int colunas) {
    int k = (linhas * colunas) - 1;
    for (int i = linhas - 1; i >= 0; i--) {
        for (int j = colunas - 1; j >= 0; j--)
        {
            p[i][j] = v[k];
            k--;
        }
    }
}

void imprimeMatriz(int **p, int linhas, int colunas) {
    printf("\n\nOs números da matriz são:\n\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
        { 
            printf("%d", p[i][j]);
            if (j < colunas - 1)
            {
                printf(" - ");
            }
            
        }
        printf("\n");
    }
}

int main() {
    int linhas, colunas, *ptrV,**ptrM;

    setlocale(LC_ALL, "Portuguese");

    printf("Digite o número de linhas: ");
    scanf(" %d", &linhas);
    printf("Agora digite o número de colunas: ");
    scanf(" %d", &colunas);
    printf("\n\n");

    //Alocação do Vetor
    ptrV = (int*) malloc(sizeof(int) * (linhas * colunas));
    if (ptrV == NULL) {
        printf("Memória insuficiente!");
    }
    
    preencheVetor(ptrV, linhas, colunas);
    imprimeVetor(ptrV, linhas, colunas);

    //Alocação da Matriz
    ptrM = (int**) malloc(sizeof(int) * linhas);
    for (int i = 0; i < linhas; i++)
    {
        ptrM[i] = (int*) malloc(sizeof(int) * colunas);
    }
    if (ptrM == NULL) {
        printf("Memória insuficiente!");
    }

    preencheMatriz(ptrM, ptrV, linhas, colunas);
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    imprimeMatriz(ptrM, linhas, colunas);
    
    //Liberação de memória
    for (int i = 0; i < linhas; i++)
    {
        free(ptrM[i]);
    }
    free(ptrM);
    free(ptrV);

    return 0;
}

