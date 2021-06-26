#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quickSortHibrido.h"

void geraNumerosAleatorios(int qtNumeros, char nomeArquivo[], int variacao) {
    FILE *pa;
    int num;
    pa = fopen(nomeArquivo, "w");
  
    srand(time(NULL));

    for(int i = 0; i < qtNumeros; i++) {
        num = (rand() % variacao) + 1; //Gera números de 1 a 5000 (nesse caso)
        fprintf(pa, "%d\n", num);
    }

    fclose(pa);
}

void carregaVetor(int vet[], int tam, char nomeArquivo[]) {
    FILE *pa;
    char strNum[tam];
    pa = fopen(nomeArquivo, "r");

    for(int i = 0; i < tam; i++) {
        fgets(strNum, tam, pa);
        vet[i] = atoi(strNum);
    }

    fclose(pa);
}

void imprimeVetor(int vet[], int tam) {
    for(int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void insercao(int vet[], int inicio, int fim, int metricas[]) {
    int validacao = 0;
    int valor, pos;

    for (int i = inicio + 1; i <= fim; i++) {
        valor = vet[i];
        pos = i;
 
        while (pos > inicio && vet[pos - 1] > valor) {
            validacao = 1;
            metricas[0]++;
            metricas[1]++;

            vet[pos] = vet[pos - 1];
            pos--;
        }
        if(validacao == 0) {  //validação para a contabilização das métricas corretamente
            metricas[0]++;
        } else if(validacao == 1) {
            metricas[1]++;
        }
        vet[pos] = valor;
        validacao = 0;
    }
}
 
int particiona(int vet[], int inicio, int fim, int metricas[]) {
    int pivo = vet[fim];
    int aux;
 
    int posPivo = inicio;

    for (int i = inicio; i < fim; i++) {
        metricas[0]++;
        if (vet[i] <= pivo) {
            metricas[1]++;
            aux = vet[i];
            vet[i] = vet[posPivo];
            vet[posPivo] = aux;
            posPivo++;
        }
    }
    metricas[1]++;
    aux = vet[posPivo];
    vet[posPivo] = vet[fim];
    vet[fim] = aux;

    return posPivo;
}
 
void quickSortHibrido(int vet[], int inicio, int fim, int metricas[], clock_t t_inicio) {
    int posPivo;

    while (inicio < fim) {
        if (fim - inicio <= 10) {
            insercao(vet, inicio, fim, metricas);
            break;
        } else {
            posPivo = particiona(vet, inicio, fim, metricas);
 
            if (posPivo - inicio < fim - posPivo) {
                quickSortHibrido(vet, inicio, posPivo - 1, metricas, t_inicio);
                inicio = posPivo + 1;
            } else {
                quickSortHibrido(vet, posPivo + 1, fim, metricas, t_inicio);
                fim = posPivo - 1;
            }
        }
    }

    double tempo = 0.0;
    clock_t t_fim = clock();

    FILE *pa;
    pa = fopen("metricas.txt", "w");

    fprintf(pa, "Comparacoes = %d\n", metricas[0]);
    fprintf(pa, "Trocas = %d\n", metricas[1]);
    tempo += (double)(t_fim - t_inicio) / CLOCKS_PER_SEC;;
    fprintf(pa, "Tempo = %f\n", tempo);

    fclose(pa);
}

void leMetricas(char nomeArquivo[]) {
    FILE *pa;
    char strMetrica[100];
    pa = fopen(nomeArquivo, "r");

    for(int i = 0; i < 3; i++) {
        fgets(strMetrica, 100, pa);
        printf("%s", strMetrica);
    }

    fclose(pa);
}

int buscaLinear (int vet[], int chave, int tam) {
    for(int i = 0; i < tam; i++) {
        if(chave == vet[i]) {
            return i;
        }
    }
    return -1;
}

int buscaBinaria (int vet[], int chave, int tam) {
    int ini = 0;
    int fim = tam-1;
    int meio;
    
    while (ini <= fim) {
        meio = (ini + fim) / 2;
        if (chave == vet[meio]) {
            return meio;
        } else if (chave < vet[meio]) {
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }
    return -1;
}