#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

typedef struct elemento{
  struct aluno dado;
  struct elemento *prox;
}Elemento;

Lista* criar_lista()
{
  Lista *li = (Lista*) malloc(sizeof(Lista));  

  if(li != NULL){
    *li = NULL;
  } 

  return li;
}

int liberar_lista(Lista *li)
{
  if(!li){    
    return 0;
  }

  Elemento *no;
  while(*li){
    printf("lala");
    no = *li;
    *li = (*li)->prox;
    free(no);
  }

  free(li);

  return 1;  
}

int tamanho_lista(Lista *li)
{
  if(li == NULL){
    return 0;
  }

  int cont = 0;
  Elemento *no = *li;

  while(no != NULL){
    cont++;
    no = no->prox;
  }

  return cont;
}

int lista_vazia(Lista *li)
{
  if(li == NULL){
    return -1;
  }

  if(*li == NULL){
    return 1;
  }

  return 0;
}

int lista_cheia(Lista *li)
{
  return 0;
}

Elemento* criar_elemento()
{
  Elemento *no = (Elemento*) malloc(sizeof(Elemento));  

  return no;
}

int inserir_lista_inicio(Lista *li, struct aluno dado)
{
  if(li == NULL){
    return 0;
  }

  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  no->dado = dado;
  no->prox = (*li);

  *li = no;

  return 1;
}

int inserir_lista_final(Lista *li, struct aluno dado)
{
  if(li == NULL){
    return 0;
  }

  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  no->dado = dado;
  no->prox = NULL;

  if( (*li) == NULL ){
    *li = no;

  }else{

    Elemento *aux;
    aux = *li;

    while(aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = no;
  }

  return 1;
}

int inserir_lista_ordenada(Lista *li, struct aluno dado)
{
  if(li == NULL){
    return 0;
  }
  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  no->dado = dado;

  if( (*li) == NULL ){
    no->prox = NULL;
    *li = no;

  }else{

    Elemento *anterior, *atual;
    atual = *li;

    while(atual != NULL && atual->dado.matricula < dado.matricula){
      anterior = atual;
      atual = atual->prox;
    }
    
    if( atual == (*li) ){
      no->prox = (*li);
      *li = no;

    }else{
      no->prox = atual;
      anterior->prox = no;
    }
  }

  return 1;
}


int remover_lista_inicio(Lista *li)
{
  if(li == NULL){
    return 0;
  }

  if((*li) == NULL){
    return 0;
  }

  Elemento *atual;
  atual = *li;
  *li = atual->prox;

  free(atual);

  return 1;
}

int remover_lista_final(Lista *li)
{
  if(li == NULL){
    return 0;
  }

  if((*li) == NULL){
    return 0;
  }

  Elemento *anterior, *atual;
  atual = *li;
  
  while(atual->prox != NULL){
    anterior = atual;
    atual = atual->prox;
  }

  if(atual == (*li)){ 
    *li = atual->prox;  

  }else{
    anterior->prox = atual->prox;
  }

  free(atual);

  return 1;

}

int remover_lista_meio(Lista *li, struct aluno dado)
{
  if(li == NULL){
    return 0;
  }

  if((*li) == NULL){
    return 0;
  }

  Elemento *anterior, *atual;
  atual = *li;

  while(atual != NULL && atual->dado.matricula != dado.matricula){
    anterior = atual;
    atual = atual->prox;
  }

  if(atual == NULL){
    return 0;
  }

  if(atual == (*li)){
    *li = atual->prox;

  }else{
    anterior->prox = atual->prox;
  }

  free(atual);
  return 1;

}

int buscar_lista_posicao(Lista *li, int pos, struct aluno *dado)
{
  if(li == NULL || (*li) == NULL || pos <= 0){
    return 0;
  }

  Elemento *no = *li;
  int i = 1;

  while(no != NULL && i < pos){
    no = no->prox;
    i++;
  }

  if(no == NULL){
    return 0;
  }

  *dado = no->dado;

  return 1;
}


int buscar_lista_dado(Lista *li, struct aluno dado, int *pos)
{
  if(li == NULL || (*li) == NULL){
    return 0;
  }

  Elemento *no = *li;
  int i = 1;

  while(no != NULL && no->dado.matricula != dado.matricula){
    no = no->prox;
    i++;
  }
  
  if(no == NULL){ 
    return 0;
  }

  *pos = i; 

  return 1;
}

int imprimir_lista(Lista *li)
{
    if(li == NULL || (*li) == NULL){
      return 0;
    }

    Elemento *aux = (*li);

    while(aux->prox != NULL){
      printf("\n\nMatrícula: %d", aux->dado.matricula);
      printf("\nNome: %s", aux->dado.nome);
      printf("\nNota: %.2f", aux->dado.nota);
      aux = aux->prox;
    }

    printf("\n\nMatrícula: %d", aux->dado.matricula);
    printf("\nNome: %s", aux->dado.nome);
    printf("\nNota: %.2f", aux->dado.nota);
    printf("\n");

    return 1;
}

Lista* concatena_lista(Lista *l1, Lista *l2) {
  Lista *l3;
  l3 = criar_lista();
  Elemento *no = *l3;

  if (l1 != NULL) {
    Elemento *aux = *l1;
    while (aux != NULL) {
      inserir_lista_final(l3, aux->dado);
      aux = aux->prox;
    }
  }

  if (l2 != NULL) {
    Elemento *aux = *l2;
    while (aux != NULL) {
      inserir_lista_final(l3, aux->dado);
      aux = aux->prox;
    }
  }

  liberar_lista(l1);
  liberar_lista(l2);

  return l3;
}

Lista* copia_lista(Lista *li) {
  if (li == NULL) {
    return 0;
  }

  Elemento *no = *li;
  Lista *li2 = criar_lista();
  Elemento *aux = *li2;
  int pos;

  while (no->prox != NULL) {
    if (buscar_lista_dado(li2, no->dado, &pos) != 1) {
      aux->dado = no->dado;
    }
    no = no->prox;
    aux = aux->prox;
  }
  
  return li2;
}

Lista* inverte_lista(Lista *l1) {
  if (l1 == NULL) {
    return 0;
  }
  Elemento *no = *l1;
  Lista *l2 = criar_lista();

  while (no->prox != NULL) {
    inserir_lista_inicio(l2, no->dado);
    no = no->prox;
  }

  return l2;
}

int verifica_ordem(Lista *li) {
  if (li == NULL) {
    return 0;
  }

  Elemento *atual = *li;
  Elemento *anterior = *li;
  int cont_elementos = 0, cont_ordem = 0;

  while (atual->prox != NULL) {
    anterior = atual;
    if (anterior->dado.matricula > atual->dado.matricula) {
      cont_ordem++;
    }
    atual = atual->prox;
    cont_elementos++;
  }
  if (cont_elementos == cont_ordem) {
    return 1;
  }

  cont_elementos = 0;
  cont_ordem = 0;
  while (atual->prox != NULL) {
    anterior = atual;
    if (anterior->dado.matricula < atual->dado.matricula) {
      cont_ordem++;
    }
    atual = atual->prox;
    cont_elementos++;
  }
  if (cont_elementos == cont_ordem) {
    return 2;
  } else {
    return -1;
  }
}

int calcula_tamanho(Lista *li) {
  if (li == NULL) {
    return 0;
  }
  Elemento *no = *li;
  if (no != NULL) {
    return 1 + calcula_tamanho(&no->prox);
  } else {
    return 0;
  }
}