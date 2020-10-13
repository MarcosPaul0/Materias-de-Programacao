#include <stdio.h>

#ifndef _TAD_BITMAP
#define _TAD_BITMAP

int* criar_bitmap(int id);
void imprime_bitmap(int* bitmap, int lim);
int liberar_bitmap(int* bitmap);
void comandos_bitmap(int* bitmap, int cod);


//Índice bitsliced para a idade - cria a matriz, recebe os dados, imprime a matriz.
int* criar_matriz(int id);
void liberar_matriz(int* matriz, int id);
//void idade_slice(int** bitsliced);
//void imprime_bitsliced(int** bitsliced);
void blaus(int* matriz);
void preenche_matriz(int* matriz);
int consulta_bitmap(int* matriz);
#endif