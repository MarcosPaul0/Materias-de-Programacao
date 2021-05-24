#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "selecao.h"

void geraNumerosAleatorios(int qtNumeros, char nomeArquivo[]) {
    FILE *pa;
    int num;
    pa = fopen(nomeArquivo, "w");
  
    srand(time(NULL));

    for(int i = 0; i < qtNumeros; i++) {
        num = (rand() % 1000) + 1;
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

void selecao(int vet[], int tam) {
    int aux, posMin;

    for(int i = 0; i < tam - 1; i++) {
        posMin = encontraMenor(i + 1, tam, vet);
        if(vet[i] > vet[posMin]) {
            aux = vet[i];
            vet[i] = vet[posMin];
            vet[posMin] = aux;
        }
    }
}

void dualselecao(int vet[], int tam) {
    int aux, minMax[2];

    for(int i = 0; i < tam; i++, tam--) {
        encontraMaiorMenor(i, tam, vet, minMax);
        if(vet[i] > vet[minMax[0]]) {
            if(minMax[1] == i) {
                minMax[1] = minMax[0];
            }
            aux = vet[i];
            vet[i] = vet[minMax[0]];
            vet[minMax[0]] = aux;
        }
        if(vet[tam - 1] < vet[minMax[1]]) {
            aux = vet[tam - 1];
            vet[tam - 1] = vet[minMax[1]];
            vet[minMax[1]] = aux;
        }
    }
}

int encontraMenor(int inicio, int fim, int vet[]) {
    int min = vet[inicio];
    int pos = inicio;

    for(int j = inicio + 1; j < fim; j++) {
        if(vet[j] < min) {
            min = vet[j];
            pos = j;
        }
    }

    return pos;
}

void encontraMaiorMenor(int inicio, int fim, int vet[], int res[]) {
    int min = vet[inicio];
    int max = vet[inicio];
    int posMin = inicio;
    int posMax = inicio;

    for(int i = inicio + 1; i < fim; i++) {
        if(vet[i] < min) {
            min = vet[i];
            posMin = i;
        }
        if(vet[i] > max) {
            max = vet[i];
            posMax = i;
        }
    }

    res[0] = posMin;
    res[1] = posMax;
}

void insercao(int vet[], int tam) {
    int aux;
    int pos;
    for(int i = 1; i < tam; i++) {
        pos = i - 1;
        aux = vet[i];
        while(aux < vet[pos] && pos >= 0) {
            vet[pos + 1] = vet[pos];
            pos--;
        }
        vet[pos + 1] = aux;
    }
}

void imprimeVetor(int vet[], int tam) {
    for(int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}