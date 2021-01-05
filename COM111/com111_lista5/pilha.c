#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"


//criando elemento
struct elemento{
    char dado;
    struct elemento *prox;
};


//typedef do elemento
typedef struct elemento Elemento;

//criando nó descritor
struct descritor{
    struct elemento *inicio;
    struct elemento *fim;
    int quant;
};


// função para alocar memória do tipo Pilha
Pilha* criar_pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->inicio = NULL;
        pi->fim = NULL;
        pi->quant = 0;
    }
    return pi;
}

// função para liberar memória
int liberar_pilha(Pilha *pi){

  if(pi == NULL){    
    return 0;
  }

  Elemento *atual;

  if(pi->inicio == NULL){
      pi->fim = NULL;

  }else{
    while (pi->fim != NULL){
      atual = pi->inicio;
      pi->inicio = atual->prox;
      free(atual);

      if(pi->inicio == NULL){
        pi->fim = NULL;
      }
    }

    free(pi);
  }

  return 1;
}

// função para alocar memória do tipo Elemento
Elemento* criar_elemento(){
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));

    if(no == NULL){
        return 0;
    }

    return no;
}


// função para inserir elemento no topo da pilha (início da lista)
int empilhar(Pilha *pi, char dado){

  if(pi == NULL){
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;
  no->prox = pi->inicio;

  // insere elemento no início da pilha
  pi->inicio = no;
  pi->fim = no;
  pi->quant++;

  return 1;
}

// função para remover elemento do topo da pilha (início da lista)
char desempilhar(Pilha *pi){
  char dado;
  if(pi == NULL){
    return 0;
  }

  // pilha vazia, não remove nada
  if((pi->inicio) == NULL){
    return 0;
  }

  dado = pi->inicio->dado;
  // muda inicio para o proximo elemento
  Elemento *no;
  no = pi->inicio;
  pi->inicio = no->prox;
  pi->quant--;

  // libera Elemento no
  free(no);

  return dado;
}

// função para consultar o primeiro elemento
int consultar_topo_pilha(Pilha *pi, char *dado){

  // verifica se a pilha foi criada corretamente e se não está vazia
  if(pi == NULL || pi->inicio == NULL){
    *dado = NULL;
    return 0;
  }

  Elemento *no = pi->inicio;

  // copia o dado do topo da pilha (início da lista)
  *dado = no->dado;

  return 1;
}

// função que devolve o tamanho da pilha
int tamanho_pilha(Pilha *pi){
    if(pi == NULL){
        return -1;
    }
    return pi->quant;
}

void passa_pilha(Pilha *pi, Pilha *pi_aux) {
  Elemento *no = criar_elemento();
  no = pi->inicio;

  while(no != NULL) {
    empilhar(pi_aux, no->dado);
    no = no->prox;
  }

  free(no);
}

void imprime_pilha(Pilha *pi, Pilha *pi1, Pilha *pi2) {
  Pilha *pi_aux = criar_pilha();
  passa_pilha(pi, pi_aux);
  Pilha *pi1_aux = criar_pilha();
  passa_pilha(pi1, pi1_aux);
  Pilha *pi2_aux = criar_pilha();
  passa_pilha(pi2, pi2_aux);

  Elemento *no_aux = criar_elemento();
  no_aux = pi_aux->inicio;
  Elemento *no1_aux = criar_elemento();
  no1_aux = pi1_aux->inicio;
  Elemento *no2_aux = criar_elemento();
  no2_aux = pi2_aux->inicio;

  printf("\n\n\n\n");
  printf("        Tubo 1      Tubo 2      Tubo 3\n\n");
  for (int i = 0; i < 5; i++) {
    //Imprime pilha 1
    if (no_aux == NULL) {
      printf("         | |");
    } else {
      printf("         |%c|", no_aux->dado);
    }
    //Imprime pilha 2
    if (no1_aux == NULL) {
      printf("         | |");
    } else {
      printf("         |%c|", no1_aux->dado);
    }
    //Imprime pilha 3
    if (no2_aux == NULL) {
      printf("         | |");
    } else {
      printf("         |%c|", no2_aux->dado);
    }
    printf("\n");
    //Pega o proximo valor da pilha 1
    if (no_aux == NULL) {

    } else if (no_aux->prox == NULL) {
      no_aux = NULL;
    } else {
      no_aux = no_aux->prox;
    }
    //Pega o proximo valor da pilha 2
    if (no1_aux == NULL) {
      
    } else if (no1_aux->prox == NULL) {
      no1_aux = NULL;
    } else {
      no1_aux = no1_aux->prox;
    }
    //Pega o proximo valor da pilha 3
    if (no2_aux == NULL) {
      
    } else if (no2_aux->prox == NULL) {
      no2_aux = NULL;
    } else {
      no2_aux = no2_aux->prox;
    }
  }
  printf("         / /         / /         / /");
  liberar_pilha(pi_aux);
  liberar_pilha(pi1_aux);
  liberar_pilha(pi2_aux);
}

int verifica_alfa(Pilha *pi) {
  char ordem[5] = "AEIOU";
  char atual[5];
  char aux;
  int i = 0;
  Elemento *no = criar_elemento();
  no = pi->inicio;

  while (no != NULL) {
    aux = no->dado;
    atual[i] = aux;
    i++;
    no = no->prox;
  }

  free(no);
  
  if (strncmp(atual, ordem, 5) == 0) {
    return 7;
  } else {
    return 0;
  }
}