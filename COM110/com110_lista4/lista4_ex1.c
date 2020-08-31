#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  int contador, numero, potencia;
    printf("~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Cauculador de potencia\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Digite um numero inteiro: ");
    scanf("%i", &numero);

  for(contador = 0; contador <= 10; contador++)
  {
    potencia = pow(numero, contador);
    printf("O numero %i elevado a %i = %i\n", numero, contador, potencia);
  }
  
  return(0);
}