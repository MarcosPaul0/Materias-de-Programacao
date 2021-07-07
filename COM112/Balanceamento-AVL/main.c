#include <stdio.h>
#include <stdlib.h>

#include "AVL.h"

int main(void) {
  struct arvore *A = NULL;
  A = criaArvore();

  /*insereNo(A, 170);
  insereNo(A, 148);
  insereNo(A, 279);
  insereNo(A, 399);
  insereNo(A, 185);
  insereNo(A, 306);
  insereNo(A, 142);
  insereNo(A, 79);
  insereNo(A, 197);
  insereNo(A, 458);*/
  insereArquivo(A, "numeros.txt");
  percorreArvore(retornaRaiz(A));
  printf("\n");
  removeNo(A, 7);
  removeNo(A, 11);
  removeNo(A, 144);
  removeNo(A, 75);
  removeNo(A, 73);
  removeNo(A, 150);
  removeNo(A, 35);
  removeNo(A, 33);
  removeNo(A, 3);
  removeNo(A, 65);
  percorreArvore(retornaRaiz(A));
  return 0;
}