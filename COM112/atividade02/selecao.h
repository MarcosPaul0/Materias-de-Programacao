#ifndef INC_3_SELECAO_SELECAO_H
#define INC_3_SELECAO_SELECAO_H

void geraNumerosAleatorios(int qtNumeros, char nomeArquivo[]);

void carregaVetor(int vet[], int tam, char nomeArquivo[]);

void selecao(int vet[], int tam);
//Essa função recebe o vetor que foi carregado pela função carregaVetor e o ordena
// usando o algoritmo selecao.

void dualselecao(int vet[], int tam);
//Essa função recebe o vetor que foi carregado pela função carregaVetor e o ordena
// usando a variação do algoritmo seleção, onde o menor e o maior são procurados na mesma passada.

int encontraMenor(int inicio, int fim, int vet[]);
//Essa função encontra a posição do menor elemento no vetor, entre as posicoes inicio e fim

void encontraMaiorMenor(int inicio, int fim, int vet[], int res[]);
//Essa função encontra a posição do menor e do maior elemento no vetor, entre as posicoes inicio e fim

void insercao(int vet[], int tam);
//Essa função recebe o vetor que foi carregado pela função carregaVetor e o ordena
// usando o algoritmo insercao.

void imprimeVetor(int vet[], int tam);

#endif //INC_3_SELECAO_SELECAO_H