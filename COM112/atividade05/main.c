#include <stdio.h>
#include <stdlib.h>

#include "ABP.h"

int main(void) {
  arvore *A = NULL;
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
  imprimeDados(retornaNo(A, 279));

  return 0;
}