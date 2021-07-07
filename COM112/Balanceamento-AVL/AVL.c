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

void percorreArvore(no *raiz) {
    if(raiz == NULL) {
        return;
    }

    printf("%d-%d\n", raiz->chave, raiz->fb);
    percorreArvore(raiz->esq);
    percorreArvore(raiz->dir);
}

void imprimeDados(no *elemento) {
    if(elemento == NULL) {
        printf("Elemento inválido!");
        exit(0);
    }

    printf("\nChave:%d", elemento->chave);

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
    if(filhoDir->chave < noDesbalanceado->pai->chave) {
        noDesbalanceado->pai->esq = filhoDir;
    } else {
        noDesbalanceado->pai->dir = filhoDir;
    }

    filhoDir->esq = noDesbalanceado;
    noDesbalanceado->pai = filhoDir;
    noDesbalanceado->dir = esqFilho;
    if(esqFilho != NULL) {
        esqFilho->pai = noDesbalanceado;
    }
}

void rotDir(no *noDesbalanceado) {
    no *filhoEsq = noDesbalanceado->esq;
    no *dirFilho = filhoEsq->dir;

    filhoEsq->pai = noDesbalanceado->pai;
    if(filhoEsq->chave < noDesbalanceado->pai->chave) {
        noDesbalanceado->pai->esq = filhoEsq;
    } else {
        noDesbalanceado->pai->dir = filhoEsq;
    }

    filhoEsq->dir = noDesbalanceado;
    noDesbalanceado->pai = filhoEsq;
    noDesbalanceado->esq = dirFilho;
    if(dirFilho != NULL) {
        dirFilho->pai = noDesbalanceado;
    }
}

void balanceamento(no *no) {
    struct no *neto;
    struct no *filho;

    if(no->fb == -2) { //Rotação a direita
        filho = no->esq;
        if(filho->fb == 1) {
            neto = filho->dir;
            rotEsq(filho);
            rotDir(no);
            if(neto->fb == -1) {
                no->fb = 1;
                filho->fb = 0;
                neto->fb = 0;
            } else {
                if(neto->fb == 1) {
                    filho->fb = -1;
                } else {
                    filho->fb = 0;
                }
                no->fb = 0;
                neto->fb = 0;
            }
        } else {
            rotDir(no);
            if(filho->fb == 0) {
                no->fb = -1;
                filho->fb = 1;
            } else {
                no->fb = 0;
                filho->fb = 0;
            }
        }
    } else { //Rotação a esquerda
        filho = no->dir;
        if(filho->fb == -1) {
            neto = filho->esq;
            rotDir(filho);
            rotEsq(no);
            if(neto->fb == -1) {
                no->fb = 0;
                filho->fb = 1;
                neto->fb = 0;
            } else {
                if(neto->fb == 1) {
                    no->fb = -1;
                } else {
                    no->fb = 0;
                }
                filho->fb = 0;
                neto->fb = 0;
            }
        } else {
            rotEsq(no);
            if(filho->fb == 0) {
                no->fb = 1;
                filho->fb = -1;
            } else {
                no->fb = 0;
                filho->fb = 0;
            }
        }
    }
}

void atualizaFB_Insercao(no *no, arvore *A) {
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
        balanceamento(no);
    }
}

void atualizaFB_Remocao(no *no, arvore *A) {
    if(no->chave < no->pai->chave) {
        no->pai->fb++;
    } else {
        no->pai->fb--;
    }
    no = no->pai;

    while(no->fb == 0 && no->pai != A->sentinela) {
        if(no->chave < no->pai->chave) {
            no->pai->fb++;
        } else {
            no->pai->fb--;
        }
        no = no->pai;
    }

    if(no->fb == 2 || no->fb == -2) {
        balanceamento(no);
        if(no->pai->fb == 0 && no->pai != A->sentinela->dir) {
            atualizaFB_Remocao(no->pai, A);
        } 
    }
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

void insereArquivo(arvore *A, char nomeArquivo[]) {
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
        sucessor = aux->pai;
        if(aux->chave < aux->pai->chave) {
            aux->pai->esq = NULL;
        } else {
            aux->pai->dir = NULL;
        }
        atualizaFB_Remocao(aux, A);
        free(aux);
    } else if(aux->esq != NULL || aux->dir !=NULL) {
        sucessor = aux;
        if(aux->esq != NULL) {
            aux->chave = aux->esq->chave;
            atualizaFB_Remocao(aux, A);
            free(aux->esq);
            aux->esq = NULL;
        } else {
            aux->chave = aux->dir->chave;
            atualizaFB_Remocao(aux, A);
            free(aux->dir);
            aux->dir = NULL;
        }
    }
}