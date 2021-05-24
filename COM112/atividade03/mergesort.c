#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "mergesort.h"

void geraNumerosAleatorios(int qtNumeros, char nomeArquivo[]) {
    FILE *pa;
    int num;
    pa = fopen(nomeArquivo, "w");
  
    srand(time(NULL));

    for(int i = 0; i < qtNumeros; i++) {
        num = (rand() % 5000) + 1;
        fprintf(pa, "%d\n", num);
    }

    fclose(pa);
}

void carregaVetor(int vet[], int tam, char nomeArquivo[]) {
    FILE *pa;
    char strNum[tam];
    pa = fopen(nomeArquivo, "r");

    for(int i = 0; i < tam; i++) {
        fgets(strNum, tam, pa);
        vet[i] = atoi(strNum);
    }

    fclose(pa);
}

void imprimeVetor(int vet[], int tam) {
    for(int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void mergeSort(int vet[], int inicio, int fim) {
    int meio;

    if(inicio < fim) {
        meio = (inicio + fim) / 2;
        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio + 1, fim);
        merge(vet, inicio, meio, fim);
    }
}

void merge(int vet[], int inicio, int meio, int fim) {
    int marcadorV1 = inicio;
    int marcadorV2 = meio + 1;
    int vetAux[fim - inicio + 1];
    int i = 0;
    int k;

    while(marcadorV1 <= meio && marcadorV2 <= fim) {
        if(vet[marcadorV1] < vet[marcadorV2]) {
            vetAux[i] = vet[marcadorV1];
            marcadorV1++;
        } else {
            vetAux[i] = vet[marcadorV2];
            marcadorV2++;
        }
        i++;
    }

    while(marcadorV1 <= meio) {
        vetAux[i] = vet[marcadorV1];
        i++;
        marcadorV1++;
    }

    while(marcadorV2 <= fim) {
        vetAux[i] = vet[marcadorV2];
        i++;
        marcadorV2++;
    }

    for(i = inicio; i <= fim; i++) {
        vet[i] = vetAux[i - inicio];
    }
}