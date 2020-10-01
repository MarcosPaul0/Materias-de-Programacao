// TAD para Lista Dinâmica Encadeada baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#ifndef _LISTA_ENCADEADA
#define _LISTA_ENCADEADA

struct aluno {
    int matricula;
    char nome[30];
    float nota;
};

typedef struct elemento* Lista;

// funções para alocar e desalocar memória
Lista* criar_lista();
int liberar_lista(Lista *li);	

// funções para obter informações da lista
int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);
int lista_cheia(Lista *li);

// funções para inserção de elementos da lista
int inserir_lista_inicio(Lista *li, struct aluno dado);
int inserir_lista_final(Lista *li, struct aluno dado);
int inserir_lista_ordenada(Lista *li, struct aluno dado);

// funções para remoção de elementos da lista
int remover_lista_inicio(Lista *li);
int remover_lista_final(Lista *li);
int remover_lista_meio(Lista *li, struct aluno dado);

// funções para buscar elementos na lista
int buscar_lista_posicao(Lista *li, int pos, struct aluno *dado);
int buscar_lista_dado(Lista *li, struct aluno dado, int *pos);

int imprimir_lista(Lista *li);

/*i. Receba duas listas e retorne uma terceira contendo as duas primeiras concatenadas.
ii. Dada uma lista L1, crie e retorne uma cópia dela em L2 eliminando os valores repetidos
(matrícula do aluno).
iii. Dada uma lista L1, inverta a lista e armazene em L2. A função deve retornar a lista L2.
iv. Verique se a lista está ordenada ou não (crescente ou decrescente), de acordo com a matrícula
do aluno.
v. Calcule e retorne o tamanho da lista dinâmica encadeada. A função deve ser recursiva.*/
Lista* concatena_lista(Lista *l1, Lista *l2);
Lista* copia_lista(Lista *li);
Lista* inverte_lista(Lista *l1);
int verifica_ordem(Lista *li);
int calcula_tamanho(Lista *li);

#endif