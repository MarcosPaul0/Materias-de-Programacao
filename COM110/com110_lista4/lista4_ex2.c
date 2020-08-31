#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) 
{
  int  intervalo, potencia;
  printf("-------------------\n");
  printf("Elevando o numero 3\n");
  printf("-------------------\n");
  printf("Digite ate que numero sera o intervalo: ");
  scanf("%i", &intervalo);

  for (intervalo; intervalo >= 0; intervalo--) {
    potencia = pow(3, intervalo);
    printf("O numero 3 elevado a %i = %i\n", intervalo, potencia);
  }

  return 0;
}