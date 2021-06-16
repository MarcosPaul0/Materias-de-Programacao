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
    int marcadorVet1 = inicio;
    int marcadorVet2 = meio + 1;
    int vetAux[fim - inicio + 1];
    int i = 0;
    int k;

    while(marcadorVet1 <= meio && marcadorVet2 <= fim) {
        if(vet[marcadorVet1] < vet[marcadorVet2]) {
            vetAux[i] = vet[marcadorVet1];
            marcadorVet1++;
        } else {
            vetAux[i] = vet[marcadorVet2];
            marcadorVet2++;
        }
        i++;
    }

    while(marcadorVet1 <= meio) {
        vetAux[i] = vet[marcadorVet1];
        i++;
        marcadorVet1++;
    }

    while(marcadorVet2 <= fim) {
        vetAux[i] = vet[marcadorVet2];
        i++;
        marcadorVet2++;
    }

    for(i = inicio; i <= fim; i++) {
        vet[i] = vetAux[i - inicio];
    }
}