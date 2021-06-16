#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quickSortHibrido.h"

int main() { //Aqui apresentamos algumas utilizações de funções do quickSortHibrido.c
    int tam;
    int compTroc[2] = {0, 0}; //Índice 0 = comparações, 1 = trocas
    int menu = 0;
    int variacao, numero, posicao;
    clock_t t_ini;
    clock_t buscaIni, buscaFim;
    double tempoBusca = 0.0;

    printf("\nEscolhar o tamanho do vetor: "); //Define o tamanho do vetor
    scanf("%d", &tam);
    int vet[tam];

    while(menu != 8) {
        printf("\n\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
        printf("\n            MENU");
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
        printf("\n1) Gera números aleatórios");
        printf("\n2) Carrega vetor");
        printf("\n3) Ordena com Quick Sort Híbrido com Insertion");
        printf("\n4) Lê métricas de ordenação");
        printf("\n5) Imprime vetor");
        printf("\n6) Busca linear");
        printf("\n7) Busca binária (o vetor será ordenado)");
        printf("\n8) Sair do programa");
        printf("\nDigite sua escolha: ");
        scanf("%d", &menu);

        switch(menu) {
            case 1:
                printf("\n\nOs números irão varia de 1 à: ");
                scanf("%d", &variacao);
                geraNumerosAleatorios(tam, "numeros.txt", variacao); //Gera números aleatórios no arquivo numeros.txt, pode ser inserido antes, 
                printf("\n\nNúmeros Gerados!");                      //com a criação do arquivo
                break;
            
            case 2:
                carregaVetor(vet, tam, "numeros.txt");  //Carrega os números de numeros.txt no vetor
                printf("\n\nNúmeros carregados.");
                printf("\nO vetor está pronto!");
                break;

            case 3:
                t_ini = clock();
                quickSortHibrido(vet, 0, tam - 1, compTroc, t_ini);  //Ordena o vetor com o método QuickSort Hibrido com Insetion
                printf("\n\nVetor ordenado!");
                break;

            case 4:
                printf("\n\n\nMétricas");
                leMetricas("metricas.txt");  //Lê e imprime as métricas gravadas durante a ordenação
                break;

            case 5:
                printf("\n\nVetor: ");
                imprimeVetor(vet, tam);  //Imprime o vetor
                break;

            case 6:
                printf("\n\n\nQual número deseja procurar? ");
                scanf("%d", &numero);

                buscaIni = clock();
                posicao = buscaLinear(vet, numero, tam);  //Busca o número de forma sequêncial
                buscaFim = clock();
                tempoBusca += (double) (buscaFim - buscaIni) / CLOCKS_PER_SEC;

                if(posicao == -1) {
                    printf("\nNúmero não encontrado");
                } else {
                    printf("\nNúmero está na posição %d do vetor", posicao);
                }
                printf("\nTempo de busca %f", tempoBusca);
                break;

            case 7:
                printf("\n\n\nQual número deseja procurar? ");
                scanf("%d", &numero);

                buscaIni = clock();
                quickSortHibrido(vet, 0, tam - 1, compTroc, t_ini); //Ordena o vetor para a busca binária
                posicao = buscaBinaria(vet, numero, tam); //Busca o número de forma binária, ou seja, dividindo
                buscaFim = clock();
                tempoBusca += (double) (buscaFim - buscaIni) / CLOCKS_PER_SEC;

                if(posicao == -1) {
                    printf("\nNúmero não encontrado");
                } else {
                    printf("\nNúmero está na posição %d do vetor", posicao);
                }
                printf("\nTempo de busca %f", tempoBusca);
                break;

            case 8:
                printf("Volte Sempre!");
                break;

            default:
                printf("\nOpção Inválida!");
        }
    }
    return 0;
}