#ifndef INC_5_QUICKSORT_QUICKSORT_H
#define INC_5_QUICKSORT_QUICKSORT_H

void geraNumerosAleatorios(int qtNumeros, char nomeArquivo[]);
//Essa função gera qtNumeros números inteiros aleatórios e salva no arquivo nomeArquivo.

void carregaVetor(int vet[], int tam, char nomeArquivo[]);
//Essa função lê o arquivo gerado pela função geraNumerosAleatorios e carrega os números em um vetor;

void imprimeVetor(int vet[], int tam);
//Essa função imprime na tela os valores de um vetor de inteiros
//A saída deve ser em linha. Exemplo : 1 2 3 4 5

void quickSort(int vet[], int inicio, int fim);
//Função quickSort que divide recursivamente o vetor e chama a função particiona.

int particiona(int vet[], int inicio, int fim);
//Função que encontra a posição correta do pivô no vetor e retorna essa posição.

#endif //INC_5_QUICKSORT_QUICKSORT_H