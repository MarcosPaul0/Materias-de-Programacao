#include <stdio.h>
#include <stdlib.h>
#include "lista_estatica.h"

struct aluno le_dados() {
  struct aluno dado;

  printf("\nMatricula: ");
  scanf(" %d", &dado.matricula);
  printf("Nome: ");
  scanf(" %s", &dado.nome);
  printf("Nota: ");
  scanf(" %f", &dado.nota);

  return dado;
}

int main() {
    Lista *li = NULL;
    int opcao, verif, matricula, pos;
    struct aluno dado;
    
    do {
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("\n           Menu de opções\n");
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("\n1 - Criar lista");
        printf("\n2 - Liberar lista");
        printf("\n3 - Inserir elemento no início");
        printf("\n4 - Inserir elemento no final");
        printf("\n5 - Inserir elemento (ordenado)");
        printf("\n6 - Remover elemento do início");
        printf("\n7 - Remover elemento do final");
        printf("\n8 - Remover elemento (qualquer)");
        printf("\n9 - Buscar elemento pela posição");
        printf("\n10 - Buscar elemento pelo dado");
        printf("\n11 - Imprimir lista");
        printf("\n12 - Sair");
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("\nOpção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            li = criar_lista();

            if (li != NULL) {
                printf("\nLista criada com sucesso!\n");
            } else {
                printf("\nLista não criada!\n");
            }
            
            break;

        case 2:
            verif = liberar_lista(li);

            if (verif == 1) {
                printf("\nLista liberada com sucesso!\n");
            }
            break;

        case 3:
            dado = le_dados();
            verif = inserir_lista_inicio(li, dado);

           if (verif == 1) {
                printf("\nDados adicionados com sucesso!\n");
            } else {
                printf("\nFalha na inserção!");
            }
            break;

        case 4:
            dado = le_dados();
            verif = inserir_lista_final(li, dado);

            if (verif == 1) {
                printf("\nDados adicionados com sucesso!\n");
            } else {
                printf("\nFalha na inserção!");
            }
            break;

        case 5:
            dado = le_dados();
            verif = inserir_lista_ordenada(li, dado);

            if (verif == 1) {
                printf("\nDados adicionados com sucesso!\n");
            } else {
                printf("\nFalha na inserção!");
            }
            break;

        case 6:
            verif = remover_lista_inicio(li);

            if(verif == 1){
                printf("\nRemoção realizada com sucesso!");
            }else{
                printf("\nFalha na remoção!");
            }
            break;

        case 7:
            verif = remover_lista_final(li);

            if(verif == 1){
                printf("\nRemoção realizada com sucesso!");
            }else{
                printf("\nFalha na remoção!");
            }
            break;

        case 8:
            printf("\nMatrícula do aluno que será removido: ");
            scanf("%d", &matricula);

            verif = remover_lista_meio(li, matricula);

            if(verif == 1){
                printf("\nRemoção realizada com sucesso!");
            }else{
                printf("\nFalha na remoção!");
            }
            break;

        case 9:
            printf("\nPosição do elemento a ser buscado: ");
            scanf("%d", &pos);

            verif = buscar_lista_posicao(li, pos, &dado);

            if(verif){
                printf("\nBusca realizada com sucesso!");
                printf("\nElemento da %dª posição: ", pos);
                printf("\nMatrícula: %d", dado.matricula);
                printf("\nNome: %s", dado.nome);
                printf("\nNota: %.2f", dado.nota);
            }else{
                printf("\nPosição não existe!");
            }
            break;

        case 10:
            printf("\nMatrícula do aluno a ser buscado: ");
            scanf("%d", &matricula);

            verif = buscar_lista_dado(li, matricula, &pos);

            if(verif){
                printf("\nBusca realizada com sucesso!");
                printf("\nElemento da %dª posição: ", pos);
                printf("\nMatrícula: %d", dado.matricula);
                printf("\nNome: %s", dado.nome);
                printf("\nNota: %.2f", dado.nota);
            }else{
                printf("\nElemento não encontrado!");
            }
            break;

        case 11:
            verif = imprimir_lista(li);
            break;

        case 12:
            printf("\nFinalizado!");
            break;
        
        default:
            break;
        }
    } while (opcao !=12);
    
    return 0;
}