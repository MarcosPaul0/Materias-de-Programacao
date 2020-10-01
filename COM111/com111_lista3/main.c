#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

int criar_dado(struct aluno *dado) {
    printf("\nMatrícula: ");
    scanf("%d", &dado->matricula);
    printf("Nome: ");
    scanf("%s", &dado->nome);
    printf("Nota: ");
    scanf("%f", &dado->nota);

    return 1;
}

int main(void) {
  Lista *li = NULL;
  int opcao, ok, pos;
  struct aluno dado;

  do
  {
    printf("\n\nMenu de opções");
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
    printf("\n17 - Tamanho da Lista");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1:
        li = criar_lista();

        if(li != NULL){
          printf("\n Lista criada com sucesso!");
        }else{
          printf("\n Lista não criada!");
        }
        break;


      case 2:
        // liberar lista
        ok = liberar_lista(li);

        if(ok){
          printf("\n Lista liberada com sucesso!");
        }else{
          printf("\n Lista não liberada!");
        }
        break;

      case 3:
        // inserir elemento no início
        ok = criar_dado(&dado);
        ok = inserir_lista_inicio(li, dado);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 4:
        // inserir elemento no final
        ok = criar_dado(&dado);
        ok = inserir_lista_final(li, dado);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 5:
        // inserir elemento de forma ordenada
        ok = criar_dado(&dado);
        ok = inserir_lista_ordenada(li, dado);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 6:
        // remover elemento do início
        ok = remover_lista_inicio(li);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 7:
        // remover elemento do final
        ok = remover_lista_final(li);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 8:
        // remover elemento do meio
        printf("\n Número a ser removido: ");
        scanf("%d", &dado);

        ok = remover_lista_meio(li, dado);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 9:
        // busca elemento pela posicao
        printf("\n Posição do elemento a ser buscado: ");
        scanf("%d", &pos);

        ok = buscar_lista_posicao(li, pos, &dado);

        if(ok){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento da %dª posição: ", pos);
          printf("%d", dado);
        }else{
          printf("\n Posição não existe!");
        }

        break;

      case 10:
        // busca elemento pelo dado
        printf("\n Código do produto a ser buscado: ");
        scanf("%d", &dado);

        ok = buscar_lista_dado(li, dado, &pos);

        if(ok){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento da %dª posição: ", pos);
          printf("%d", dado);
        }else{
          printf("\n Elemento não encontrado!");
        }

        break;

      case 11:
        // imprime a lista
        printf("\n Lista encadeada: ");
        ok = imprimir_lista(li);

        if(!ok){
          printf("\n Lista não encontrada!");
        }

        break;

      case 12:
        // libera memória e finaliza programa
        liberar_lista(li);
        printf("\nFinalizando...");
        break;

      case 17:
        printf("\nA lista possui tamanho %d\n\n", calcula_tamanho(li));
        break;

      default:
        printf("\nOpção inválida!");
        break;
    }

  }while(opcao != 12);

  return 0;
}