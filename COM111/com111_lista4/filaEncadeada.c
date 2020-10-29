// TAD para Fila Dinâmica Encadeada baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#include <stdio.h>
#include <stdlib.h>

#include "filaEncadeada.h"


//criando elemento
struct elemento{
    int dado;
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


// função para alocar memória do tipo Fila
Fila* criar_fila()
{
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicio = NULL;
        fi->fim = NULL;
        fi->quant = 0;
    }
    return fi;
}

// função para liberar memória
int liberar_fila(Fila *fi)
{

  if(fi == NULL){    
    return 0;
  }

  Elemento *atual;

  while(fi->inicio != NULL){    
    atual = fi->inicio;
    fi->inicio = fi->inicio->prox;
    fi->quant--;
    free(atual);
  }

  free(fi);  

  return 1;
}

// função para alocar memória do tipo Elemento
Elemento* criar_elemento()
{
    return (Elemento*) malloc(sizeof(Elemento));
}


// função para inserir elemento no final da fila 
int enfileirar(Fila *fi, int dado)
{
  if(fi == NULL){
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
  no->prox = NULL;

  // se a fila estiver vazia, insere no início da fila
  if(fi->inicio == NULL){    
    fi->inicio = no;  

  // senão insere elemento no final da fila  
  }else{
    fi->fim->prox = no;    
  }

  fi->fim = no;
  fi->quant++;

  return 1;
}

// função para remover elemento do início da fila
int desenfileirar(Fila *fi)
{
  if(fi == NULL){
    return 0;
  }

  // fila vazia, não remove nada
  if(fi->inicio == NULL){
    return 0;
  }

  // remove elemento do início da fila
  Elemento *no;
  no = fi->inicio;
  int senha = fi->inicio->dado;
  fi->inicio = fi->inicio->prox;
  fi->quant--;

  // libera Elemento no
  free(no);

  // se a fila ficou vazia
  if(fi->inicio == NULL){
    fi->fim = NULL;
  }

  return senha;
}

// função para consultar o primeiro elemento
int consultar_inicio_fila(Fila *fi, int *dado)
{
  // verifica se a fila foi criada corretamente e se não está vazia
  if(fi == NULL || fi->inicio == NULL){
    return 0;
  }

  // copia o dado do início da fila
  *dado = fi->inicio->dado;

  return 1;
}

// função que devolve o tamanho da fila
int tamanho_fila(Fila *fi)
{
    if(fi == NULL){
        return -1;
    }
    return fi->quant;
}

void imprime_fila(Fila *fi) {
  int qtd;
  Elemento *no;
  no = criar_elemento();
  no = fi->inicio;

  printf("\n\nDados da Fila\n");

  while (no->prox != NULL) {
    printf("%d ", no->dado);
    no = no->prox;
  }
  printf("%d ", no->dado);
  free(no);
}

int verifica_qtd(Fila *fi) {
  if (fi == NULL) {
    return 0;
  }
  return fi->quant;
}

int verifica_vazia(Fila *fi) {
  if (fi->inicio == NULL) {
    return 1;
  } else {
    return 2;
  }
}