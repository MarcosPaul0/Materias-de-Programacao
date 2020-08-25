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
    printf("Os números do vetor são:\n\n");
    for (int i = 0; i < linhas * colunas; i++) {
        printf("%d", p[i]);
        if (i < linhas * colunas - 1)
        {
            printf(" - ");
        }
    }
    printf("\n\n");
}

void preencheMatriz(int **p, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
        {
            printf("Preencha a matriz na posição [%d][%d]: ", i + 1, j + 1);
            scanf(" %d", &p[i][j]);
        }
    }
}

void imprimeMatriz(int **p, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
        { 
            printf("%d ", p[i][j]);
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

    //Alocão do Vetor
    ptrV = (int*) malloc(sizeof(int) * (linhas * colunas));
    
    preencheVetor(ptrV, linhas, colunas);
    imprimeVetor(ptrV, linhas, colunas);
    free(ptrV);

    //Alocação da Matriz
    ptrM = (int**) malloc(sizeof(int) * linhas);
    for (int i = 0; i < linhas; i++)
    {
        ptrM[i] = (int*) malloc(sizeof(int) * colunas);
    }

    preencheMatriz(ptrM, linhas, colunas);
    imprimeMatriz(ptrM, linhas, colunas);
    free(ptrM);

    return 0;
}

