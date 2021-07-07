#include <stdio.h>
#include <stdlib.h>

#include "ARN.h"

struct no {
    int chave;
    char cor;
    struct no *esq;
    struct no *dir;
    struct no *pai;
};

struct arvore {
    struct no *sentinela;
    struct no *sentinelaFolha;
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
    sentinela->cor = 'p';
    A->sentinela = sentinela;

    no *sentinelaFolha = (no*) malloc(sizeof(no));
    if(sentinelaFolha == NULL) {
        printf("Memória não alocada");
        exit(0);
    }

    sentinelaFolha->chave = -1000;
    sentinelaFolha->esq = NULL;
    sentinelaFolha->dir = NULL;
    sentinelaFolha->pai = NULL;
    sentinelaFolha->cor = 'p';
    A->sentinelaFolha = sentinelaFolha;  //AOHA

    return A;
}

no *retornaRaiz(arvore *A) {
    if(A == NULL) {
        printf("Árvore não encontrada!");
        exit(0);
    }

    return A->sentinela->dir;
}

int maior(int a, int b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

int profundidade(arvore *A, no *raiz) {
    if(raiz == A->sentinelaFolha ) {
        return -1;
    }

    return 1 + maior(profundidade(A, raiz->esq), profundidade(A, raiz->dir));
}

void percorreArvore(arvore *A, no *raiz) {
    if(raiz == A->sentinelaFolha) {
        return;
    }

    printf("%d-%c\n", raiz->chave, raiz->cor);
    percorreArvore(A, raiz->esq);
    percorreArvore(A, raiz->dir);
}

void rotEsq(arvore *A, no *noDesbalanceado) {
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
    if(esqFilho != A->sentinelaFolha) {
        esqFilho->pai = noDesbalanceado;
    }
}

void rotDir(arvore *A, no *noDesbalanceado) {
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
    if(dirFilho != A->sentinelaFolha) {
        dirFilho->pai = noDesbalanceado;
    }
}

void balanceamentoInsercao(arvore *A, no *no) {
    if(no->pai->cor == 'p') {
        A->sentinela->dir->cor = 'p';
        return;
    }

    struct no *pai = no->pai;
    struct no *avo = pai->pai;
    struct no *tio;

    if(no->chave < avo->chave) {
        tio = avo->dir;

        if(tio->cor == 'v') {
            pai->cor = 'p';
            tio->cor = 'p';
            avo->cor = 'v';
            if(avo->pai->cor == 'v') {
                balanceamentoInsercao(A, avo);
            }
        } else {
            if(no->chave >= pai->chave) {
                no = pai;
                rotEsq(A, no);
                pai = no->pai;
            }
            pai->cor = 'p';
            avo->cor = 'v';
            rotDir(A, avo);
        }
    } else {
        tio = avo->esq;

        if(tio->cor == 'v') {
            pai->cor = 'p';
            tio->cor = 'p';
            avo->cor = 'v';
            if(avo->pai->cor == 'v') {
                balanceamentoInsercao(A, avo);
            }
        } else {
            if(no->chave < pai->chave) {
                no = pai;
                rotDir(A, no);
                pai = no->pai;
            }
            pai->cor = 'p';
            avo->cor = 'v';
            rotEsq(A, avo);
        }
    }
    A->sentinela->dir->cor = 'p';
}

void balanceamentoRemocao(arvore *A, no *no) {
    struct no *irmao;
    struct no *pai = no->pai;

    while(no != A->sentinela->dir && no->cor == 'p') {
        if(pai->esq == no) {
            irmao = pai->dir;
            if(irmao->cor == 'v') {
                irmao->cor = 'p';
                pai->cor = 'v';
                rotEsq(A, pai);
                irmao = pai->dir;
            }
            if(irmao->esq->cor == 'p' && irmao->dir->cor == 'p') {
                irmao->cor = 'v';
                no = pai;
            } else {
                if(irmao->esq->cor == 'v' && irmao->dir->cor == 'p') {
                    irmao->esq->cor = 'p';
                    irmao->cor = 'v';
                    rotDir(A, irmao);
                    irmao = pai->dir;
                }
                irmao->cor = pai->cor;
                pai->cor = 'p';
                irmao->dir->cor = 'p';
                rotEsq(A, pai);
                no = A->sentinela->dir;
            }
        } else {
            irmao = pai->esq;
            if(irmao->cor == 'v') {
                irmao->cor = 'p';
                pai->cor = 'v';
                rotDir(A, pai);
                irmao = pai->esq;
            }
            if(irmao->esq->cor == 'p' && irmao->dir->cor == 'p') {
                irmao->cor = 'v';
                no = pai;
            } else {
                if(irmao->esq->cor == 'p' && irmao->dir->cor == 'v') {
                    irmao->dir->cor = 'p';
                    irmao->cor = 'v';
                    rotEsq(A, irmao);
                    irmao = pai->esq;
                }
                irmao->cor = pai->cor;
                pai->cor = 'p';
                irmao->esq->cor = 'p';
                rotDir(A, pai);
                no = A->sentinela->dir;
            }
        }
    }
    no->cor = 'p';
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
    novo->esq = A->sentinelaFolha;
    novo->dir = A->sentinelaFolha;
    novo->cor = 'v';

    if(retornaRaiz(A) == NULL) {
        A->sentinela->dir = novo;
        novo->pai = A->sentinela;
        novo->cor = 'p';
    } else {
        no *atual = retornaRaiz(A);
        no *ant;

        while(atual != A->sentinelaFolha) {
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
        balanceamentoInsercao(A, novo);
    }
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

    no *aux;
    no *sucessor;
    no *auxBalanceamento;

    aux = A->sentinela->dir;
    while(aux != A->sentinelaFolha && aux->chave != chave) {
        if(chave < aux->chave) {
            aux = aux->esq;
        } else {
            aux = aux->dir;
        }
    }
    if(aux == A->sentinelaFolha) {
        printf("Elemento não encontrado.");
        return;
    }

    if(aux->esq != A->sentinelaFolha && aux->dir != A->sentinelaFolha) {
        sucessor = aux->dir;
        while(sucessor->esq != A->sentinelaFolha) {
            sucessor = sucessor->esq;
        }
        aux->chave = sucessor->chave;
        aux = sucessor;
    }

    if(aux->esq == A->sentinelaFolha && aux->dir == A->sentinelaFolha) {
        if(aux->chave < aux->pai->chave) {
            aux->pai->esq = A->sentinelaFolha;
        } else {
            aux->pai->dir = A->sentinelaFolha;
        }

        if(aux->cor == 'p') {
            A->sentinelaFolha->pai = aux->pai;
            balanceamentoRemocao(A, A->sentinelaFolha);
        }
        A->sentinelaFolha->pai = NULL;
        free(aux);
        return;
    }

    if(aux->esq != A->sentinelaFolha || aux->dir != A->sentinelaFolha) {
        if(aux->esq != A->sentinelaFolha) {
            auxBalanceamento = aux->esq;
            if(aux->chave < aux->pai->chave) {
                aux->pai->esq = aux->esq;
            } else {
                aux->pai->dir = aux->esq;
            }
            aux->esq->pai = aux->pai;
        }
        if(aux->dir != A->sentinelaFolha) {
            auxBalanceamento = aux->dir;
            if(aux->chave < aux->pai->chave) {
                aux->pai->esq = aux->dir;
            } else {
                aux->pai->dir = aux->dir;
            }
            aux->dir->pai = aux->pai;
        }
        if(aux->cor == 'p') {
            balanceamentoRemocao(A, auxBalanceamento);
        }
        free(aux);
    }
}