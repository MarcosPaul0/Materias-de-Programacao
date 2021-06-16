#ifndef INC_5_QUICKSORT_QUICKSORT_H
#define INC_5_QUICKSORT_QUICKSORT_H

void geraNumerosAleatorios(int qtNumeros, char nomeArquivo[], int variacao);

void carregaVetor(int vet[], int tam, char nomeArquivo[]);

void imprimeVetor(int vet[], int tam);

void insercao(int vet[], int inicio, int fim, int metricas[]);
//Realiza a ordenação por inserção

int particiona(int vet[], int inicio, int fim, int metricas[]);
//Função que separa os números menores que o pivô para a esquerda e os maiores para a direita

void quickSortHibrido(int vet[], int inicio, int fim, int metricas[], clock_t t_inicio);
//Ordena o vetor por recursãoe o Particiona quando o vetor é mair que 10 e usa o Inserção quando menor ou igual a 10, o parametro métricas deve possuir 2 posisições, onde o indice 0 = comparações e 1 = trocas, deve ser já inicialisado para contabilização correta das métricas, t_inicio marca o inicio da execução da função também deve ser definido antes da chamada da função

void leMetricas(char nomeArquivo[]);
//Lê e imprime as métricas que foram gravadas na execução da função do QuickSortHibrido

int buscaLinear (int vet[], int chave, int tam);

int buscaBinaria (int vet[], int chave, int tam);

#endif