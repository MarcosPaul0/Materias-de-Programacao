#include <stdio.h>
#include <stdlib.h>

#include "bolha.h"

int main(void) {
  int tam;
  printf("\nDigite o número de números para serem gravados:");
  scanf("%d", &tam);
  int vetNum[tam];
  int vetNum2[tam];

  geraNumerosAleatorios(tam, "numeros.txt");
  carregaVetor(vetNum, tam, "numeros.txt");
  carregaVetor(vetNum2, tam, "numeros.txt");
  bolha(vetNum, tam);
  bolhaInteligente(vetNum, tam);
  printf("\n\n");
  imprimeVetor(vetNum, tam);
  printf("\n\n");
  imprimeVetor(vetNum2, tam);
  
  return 0;
}