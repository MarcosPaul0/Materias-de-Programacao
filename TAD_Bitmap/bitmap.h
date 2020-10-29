#include <stdio.h>

#ifndef _TAD_BITMAP
#define _TAD_BITMAP


// Cria, libera, preenche e imprime a matriz
bool* criar_bitmap(int id);
void liberar_bitmap(bool* matriz);
void preenche_bitmap(bool* matriz);
void imprime_bitmap(bool* matriz);

// Consultar os dados
void consultar (bool* matriz, int codigo);
void consulta_bitmap(bool* matriz, int id);

#endif