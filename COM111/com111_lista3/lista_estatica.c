#include <stdio.h>
#include <stdlib.h>
#include "lista_estatica.h"

#define MAX 100

struct lista {
    int qtd;
    struct aluno dados[MAX];
};

Lista* criar_lista() {
    Lista *li = (Lista*) malloc(sizeof(Lista));

    if (li != NULL) {
        li->qtd = 0;
    }

    return li;
}

int liberar_lista(Lista *li) {
    if (li == NULL) {
        return 0;
    }

    free(li);

    return 1;
}

// funções para obter informações da lista
int tamanho_lista(Lista *li)
{
  if(li == NULL){
    return -1;
  }else{
      return li->qtd;
  }
}

int lista_vazia(Lista *li)
{
  if(li == NULL){
    return -1;
  }

  if(li->qtd == 0){
    return 1;
  }

  return 0;
}

int lista_cheia(Lista *li)
{
  if(li == NULL){
    return -1;
  }

  if(li->qtd == MAX){
    return 1;
  }

  return 0;
}

// funções para inserção de elementos da lista
int inserir_lista_inicio(Lista *li, struct aluno dado) {
  if(li == NULL){
    return 0;
  }

  if(lista_cheia(li) == 1){
    return 0;
  }

  for(int i=li->qtd-1; i>=0; i--){
    li->dados[i+1] = li->dados[i];
  }

  li->dados[0] = dado;

  li->qtd++;

  return 1;
}

int inserir_lista_final(Lista *li, struct aluno dado) {
  if (li == NULL) {
    return 0;
  }

  if (lista_cheia(li) == 1) {
    return 0;
  }

  li->dados[li->qtd] = dado;
  li->qtd += 1;

  return 1;
}

int inserir_lista_ordenada(Lista *li, struct aluno dado) {
  if(li == NULL){
    return 0;
  }

  if(lista_cheia(li) == 1){
    return 0;
  }

  int i = 0;
  while(i < li->qtd && li->dados[i].matricula < dado.matricula){
    i++;
  }

  for(int k=li->qtd-1; k>=i; k--){
    li->dados[k+1] = li->dados[k];
  } 

  li->dados[i] = dado;

  li->qtd++;

  return 1;
}

// funções para remoção de elementos da lista
int remover_lista_inicio(Lista *li) {
  if(li == NULL){
    return 0;
  }

  if(lista_vazia(li) == 1){
    return 0;
  }

  for(int k=0; k<li->qtd-1; k++){
    li->dados[k] = li->dados[k+1];
  } 

  li->qtd--;

  return 1;
}

int remover_lista_final(Lista *li) {
  if(li == NULL){
    return 0;
  }

  if(lista_vazia(li) == 1){
    return 0;
  }

  li->qtd--;

  return 1;
}

int remover_lista_meio(Lista *li, int dado) {
  if(li == NULL){
    return 0;
  }

  if(lista_vazia(li) == 1){
    return 0;
  }

  int i = 0;
  while(i < li->qtd && li->dados[i].matricula != dado){
    i++;
  }

  if(i == li->qtd){
    return 0;
  }

  for(int k=i; k<=li->qtd-1; k++){
    li->dados[k] = li->dados[k+1];
  } 

  li->qtd--;

  return 1;
}

// funções para buscar elementos na lista
int buscar_lista_posicao(Lista *li, int pos, struct aluno *dado) {
  dado = (struct aluno*) malloc(sizeof(struct aluno));

  if (li == NULL || pos <= 0 || pos > li->qtd) {
    return 0;
  }

  *dado = li->dados[pos-1];

  return 1;
}

int buscar_lista_dado(Lista *li, int dado, int *pos) {
  if (li == NULL){
    return 0;
  }

  int i = 0;
  while (i < li->qtd && li->dados[i].matricula != dado){
    i++;
  }

  if(i == li->qtd){ 
    return 0;
  }

  *pos = i+1; 

  return 1;
}

int imprimir_lista(Lista *li)
{
  if(li == NULL){
    return 0;
  }

  for(int i=0; i<li->qtd; i++){
    printf("\n%d \n", li->dados[i].matricula);
    printf("%s \n", li->dados[i].nome);
    printf("%.2f \n", li->dados[i].nota);
  }

  return 1;
}
