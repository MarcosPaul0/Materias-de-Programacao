#include <stdio.h>
#include <stdlib.h>

#include "ABP.h"

struct no {
    int chave;
    struct no *esq;
    struct no *dir;
    struct no *pai;
};

struct arvore {
    struct no *sentinela;
};

arvore* criaArvore() {
    arvore *A = (arvore*) malloc(sizeof(arvore));

    if(A == NULL) {
        printf("Memória não alocada!");
        exit(0);
    }

    no *sentinela = (no*) malloc(sizeof(no));
    if(sentinela == NULL) {
        printf("Memória não alocada!");
        exit(0);
    }

    sentinela->chave = -1000;
    sentinela->esq = NULL;
    sentinela->dir = NULL;
    sentinela->pai = NULL;
    A->sentinela = sentinela;
    return A;
}

void insereNo(arvore *A, int chave) {
    if(A == NULL) {
        printf("Árvore não encontrada!");
        exit(0);
    }

    no *novo = (no*) malloc(sizeof(no));
    if(novo == NULL) {
        printf("Memória não alocada!");
        exit(0);
    }
    novo->chave = chave;
    novo->pai = NULL;
    novo->esq = NULL;
    novo->dir = NULL;

    if(retornaRaiz(A) == NULL) {
        A->sentinela->dir = novo;
    } else {
        no *atual = retornaRaiz(A);
        no *ant = NULL;

        while(atual != NULL) {
            ant = atual;
            
            if(chave < atual->chave) {
                atual = atual->esq;
            } else {
                atual = atual->dir;
            }
        }

        novo->pai = ant;
        if(chave < ant->chave) {
            ant->esq = novo;
        } else {
            ant->dir = novo;
        }
    }
}

void insereArquivo(arvore *A, char nomeArquivo[]) {
    if(A == NULL) {
        printf("Árvore não encontrada!");
        exit(0);
    }

    FILE *pa;
    char strNum[10];
    pa = fopen(nomeArquivo, "r");

    while(fgets(strNum, 10, pa) != NULL) {
        insereNo(A, atoi(strNum));
    }

    fclose(pa);
}

void removeNo(arvore *A, int chave) {
    if(A == NULL) {
        printf("Árvore não encontrada!");
        exit(0);
    }

    no *aux = retornaNo(A, chave);
    no *sucessor = NULL;

    if(aux->esq != NULL && aux->dir != NULL) {
        sucessor = aux->dir;
        while(sucessor->esq != NULL) {
            sucessor = sucessor->esq;
        }
        aux->chave = sucessor->chave;
        aux = sucessor;
    }

    if(aux->esq == NULL && aux->dir == NULL) {
        if(aux->chave < aux->pai->chave) {
            aux->pai->esq = NULL;
        } else {
            aux->pai->dir = NULL;
        }
        free(aux);
    } else if(aux->esq != NULL || aux->dir !=NULL) {
        if(aux->esq != NULL) {
            aux->chave = aux->esq->chave;
            free(aux->esq);
            aux->esq = NULL;
        } else {
            aux->chave = aux->dir->chave;
            free(aux->dir);
            aux->dir = NULL;
        }
    }
}

void percorreArvore(no *raiz) {
    if(raiz == NULL) {
        return;
    }

    percorreArvore(raiz->esq);
    printf("%d ", raiz->chave);
    percorreArvore(raiz->dir);
}

no *retornaRaiz(arvore *A) {
    if(A == NULL) {
        printf("Árvore não encontrada!");
        exit(0);
    }

    return A->sentinela->dir;
}

no *retornaNo(arvore *A, int chave) {
    if(A == NULL) {
        printf("Árvore não encontrada!");
        exit(0);
    }

    no *atual = retornaRaiz(A);
    no *ant = NULL;

    while(atual != NULL && atual->chave != chave) {
        ant = atual;
        
        if(chave < atual->chave) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }

    return atual;
}

void imprimeDados(no *elemento) {
    if(elemento == NULL) {
        printf("Elemento inválido!");
        exit(0);
    }

    printf("Chave:%d", elemento->chave);

    if(elemento->esq == NULL) {
        printf("\nEsq:NULO");
    } else {
        printf("\nEsq:%d", elemento->esq->chave);
    }

    if(elemento->dir == NULL) {
        printf("\nDir:NULO");
    } else {
        printf("\nDir:%d", elemento->dir->chave);
    }

    if(elemento->pai == NULL) {
        printf("\nPai:NULO");
    } else {
        printf("\nPai:%d", elemento->pai->chave);
    }
}