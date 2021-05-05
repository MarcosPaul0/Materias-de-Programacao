#include <stdio.h>
#include <stdlib.h>

#include "bolha.h"

void geraNumerosAleatorios(int qtNumeros, char nomeArquivo[]) {
  FILE *pa;
  int num;
  char strNum[3];
  pa = fopen(nomeArquivo, "w");

  for(int i = 0; i < qtNumeros; i++) {
    num = (rand() % 500) + 1;
    fprintf(pa, "%d\n", num);
  }

  fclose(pa);
}

void carregaVetor(int vet[], int tam, char nomeArquivo[]) {
  FILE *pa;
  char strNum[4];
  pa = fopen(nomeArquivo, "r");

  for(int i = 0; i < tam; i++) {
    fgets(strNum, 10, pa);
    vet[i] = atoi(strNum);
  }

  fclose(pa);
}

void bolha(int vet[], int tam) {
  int aux;

  for(int i = 0; i < tam; i++) {
    for(int j = 1; j < tam; j++) {
      if(vet[j] < vet[j - 1]) {
        aux = vet[j];
        vet[j] = vet[j - 1];
        vet[j - 1] = aux;
      }
    }
  }
}

void bolhaInteligente(int vet[], int tam) {
  int aux, troca;

  for(int i = tam - 1; i > 0; i--) {
    troca = 0;
    for(int j = 1; j <= i; j++) {
      if(vet[j] < vet[j - 1]) {
        troca = 1;
        aux = vet[j];
        vet[j] = vet[j - 1];
        vet[j - 1] = aux;
      }
    }
    if(troca == 0) {
      break;
    }
  }
}

void imprimeVetor(int vet[], int tam) {
  for(int i = 0; i < tam; i++) {
    printf("%d ", vet[i]);
  }
}