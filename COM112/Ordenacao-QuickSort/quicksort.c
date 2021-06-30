#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quicksort.h"

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

void quickSort(int vet[], int inicio, int fim) {
    int posPivo;
    if(inicio < fim) {
        posPivo = particiona(vet, inicio, fim);
        quickSort(vet, inicio, posPivo - 1);
        quickSort(vet, posPivo + 1, fim);
    }
}

int particiona(int vet[], int inicio, int fim) {
    int pivo = vet[inicio];
    int pos = inicio;
    int aux;

    for(int i = inicio + 1; i <= fim; i++) {
        if(vet[i] < pivo) {
            pos++;
            if(i != pos) {
                aux = vet[i];
                vet[i] = vet[pos];
                vet[pos] = aux;
            }
        }
    }
    aux = vet[inicio];
    vet[inicio] = vet[pos];
    vet[pos] = aux;
    return pos;
}