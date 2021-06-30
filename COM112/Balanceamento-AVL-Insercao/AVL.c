#include <stdio.h>
#include <stdlib.h>

#include "AVL.h"

struct no {
    int chave;
    int fb;
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
        return;
    }

    no *sentinela = (no*) malloc(sizeof(no));
    if(sentinela == NULL) {
        printf("Memória não alocada!");
        return;
    }

    sentinela->chave = -1000;
    sentinela->esq = NULL;
    sentinela->dir = NULL;
    sentinela->pai = NULL;
    sentinela->fb = 0;
    A->sentinela = sentinela;
    return A;
}

no *retornaRaiz(arvore *A) {
    if(A == NULL) {
        printf("Árvore não encontrada!");
        return;
    }

    return A->sentinela->dir;
}

no *retornaNo(arvore *A, int chave) {
    if(A == NULL) {
        printf("Árvore não encontrada!");
        return;
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

void removeNo(arvore *A, int chave) {
    if(A == NULL) {
        printf("Árvore não encontrada!");
        return;
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
        sucessor = aux->pai;
        if(aux->chave < aux->pai->chave) {
            aux->pai->esq = NULL;
        } else {
            aux->pai->dir = NULL;
        }
        free(aux);
    } else if(aux->esq != NULL || aux->dir !=NULL) {
        sucessor = aux;
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
    if(raiz != NULL) {
        printf("%d-%d\n", raiz->chave, raiz->fb);
    }
    percorreArvore(raiz->dir);
}

void imprimeDados(no *elemento) {
    if(elemento == NULL) {
        printf("Elemento inválido!");
        return;
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

    if(elemento->pai == NULL || elemento->pai->chave == -1000) {
        printf("\nPai:NULO");
    } else {
        printf("\nPai:%d", elemento->pai->chave);
    }
}

void rotEsq(no *noDesbalanceado) {
    no *filhoDir = noDesbalanceado->dir;
    no *esqFilho = filhoDir->esq;

    filhoDir->pai = noDesbalanceado->pai;
    if(noDesbalanceado->chave < noDesbalanceado->pai->chave) {
        noDesbalanceado->pai->esq = filhoDir;
    } else {
        noDesbalanceado->pai->dir = filhoDir;
    }

    filhoDir->esq = noDesbalanceado;
    noDesbalanceado->pai = filhoDir;
    if(esqFilho != NULL) {
        noDesbalanceado->dir = esqFilho;
        esqFilho->pai = noDesbalanceado;
    } else {
        noDesbalanceado->dir = NULL;
    }
    noDesbalanceado->fb = 0;
    filhoDir->fb = 0;
}

void rotDir(no *noDesbalanceado) {
    no *filhoEsq = noDesbalanceado->esq;
    no *dirFilho = filhoEsq->dir;

    filhoEsq->pai = noDesbalanceado->pai;
    if(noDesbalanceado->chave < noDesbalanceado->pai->chave) {
        noDesbalanceado->pai->esq = filhoEsq;
    } else {
        noDesbalanceado->pai->dir = filhoEsq;
    }

    filhoEsq->dir = noDesbalanceado;
    noDesbalanceado->pai = filhoEsq;
    if(dirFilho != NULL) {
        noDesbalanceado->esq = dirFilho;
        dirFilho->pai = noDesbalanceado;
    } else {
        noDesbalanceado->esq = NULL;
    }
    noDesbalanceado->fb = 0;
    filhoEsq->fb = 0;
}

void balanceamento_Insercao(no *no) {
    struct no *filho;
    int fbNeto = 0;

    if(no->fb == 2) {
        filho = no->dir;
        if(filho->fb == -1) {
            fbNeto = filho->esq->fb;
            rotDir(filho);
        }
        rotEsq(no);
        if(fbNeto == -1) {
            filho->fb = 1;
        } else if(fbNeto == 1) {
            no->fb = -1;
        }
    } else {
        filho = no->esq;
        if(filho->fb == 1) {
            fbNeto = filho->dir->fb;
            rotEsq(filho);
        }
        rotDir(no);
        if(fbNeto == -1) {
            no->fb = 1;
        } else if(fbNeto == 1) {
            filho->fb = -1;
        }
    }
}

void atualizaFB_Insercao(no *no, arvore *A) {
    if(no == NULL || A == NULL) {
        return;
    }

    if(no->pai != A->sentinela) {
        if(no->chave < no->pai->chave) {
            no->pai->fb--;
        } else {
            no->pai->fb++;
        }
        no = no->pai;
    }

    while(no->fb != 2 && no->fb != -2 && no->fb != 0 && no->pai != A->sentinela) {
        if(no->chave < no->pai->chave) {
            no->pai->fb--;
        } else {
            no->pai->fb++;
        }
        no = no->pai;
    }

    if(no->fb == 2 || no->fb == -2) {
        balanceamento_Insercao(no);
    }
}

void insereNo(arvore *A, int chave) {
    if(A == NULL) {
        printf("Árvore não encontrada!");
        return;
    }

    no *novo = (no*) malloc(sizeof(no));
    if(novo == NULL) {
        printf("Memória não alocada!");
        return;
    }
    novo->chave = chave;
    novo->pai = NULL;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->fb = 0;

    if(retornaRaiz(A) == NULL) {
        A->sentinela->dir = novo;
        novo->pai = A->sentinela;
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

    atualizaFB_Insercao(novo, A);
}

void insereArquivo(struct arvore *A, char nomeArquivo[]) {
    if(A == NULL) {
        printf("Árvore não encontrada!");
        exit(0);
    }

    FILE *pa;
    int num;
    pa = fopen(nomeArquivo, "r");

    while(!feof(pa)) {
        fscanf(pa, "%d\n", &num);
        insereNo(A, num);
    }

    fclose(pa);
}