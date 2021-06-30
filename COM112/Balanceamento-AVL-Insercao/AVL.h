#ifndef ABP_H
#define ABP_H

typedef struct no no;
typedef struct arvore arvore;

arvore* criaArvore();
//Cria a estrutura árvore que contém um nó sentinela.

void insereNo(arvore *A, int chave);
//Insere um nó na árvore, cujo valor da raiz está no atributo chave.

void insereArquivo(arvore *A, char nomeArquivo[]);
//Esta função lê um arquivo e insere os valores lidos na árvore.
//A função chama a insereNo para cada valor lido no arquivo.

void removeNo(arvore *A, int chave);
//Remove um nó da árvore. O valor a ser removido está no atributo chave.

no *retornaRaiz(arvore *A);
//Retorna a raiz da árvore a partir da sentinela.

no *retornaNo(arvore *A, int chave);
//Retorna o elemento (nó) da árvore que possui a chave informada.

void imprimeDados(no *elemento);
//Imprime os dados de um nó da seguinte forma:
//Chave:xx
//Esq:xx
//Dir:xx
//Pai:xx
//Se o filho da esquerda e/ou da direita for nulo, escreve "NULO"

//FUNÇÕES ESPECÍFICAS DA AVL

void rotEsq(no *noDesbalanceado);
//Implementa a rotação à esquerda no nó desbalanceado

void rotDir(no *noDesbalanceado);
//Implementa a rotação à direita no nó desbalanceado

void atualizaFB_Insercao(no *no, arvore *A);
//Atualiza o fator de balanceamento dos nós no caminho da inserção
//Atualização para quando atinge uma das condições de parada

void balanceamento_Insercao(no *no);
//Faz o correto balanceamento da árvore após detectado o desbalanceamento.
//Chama as rotações corretas

void percorreArvore(no *raiz);
//Imprime na tela o percorrimento em ordem na árvore.
//Deve-se imprimir a chave e o fator de balanceamento.
//EXEMPLO:
//5-1
//10-0 
//15--1

#endif //ABP_H