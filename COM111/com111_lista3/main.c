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
  Lista *li2 = NULL;
  int opcao, ok, pos, lista2;
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
    printf("\n11 - Concatena listas");
    printf("\n12 - Copia dados retirando os repetidos");
    printf("\n13 - Inverter lista");
    printf("\n14 - Verificar se está ordenado");
    printf("\n15 - Tamanho da Lista");
    printf("\n16 - Cria segunda lista (você não pode modificar a lista 1)");
    printf("\n17 - Imprimir lista");
    printf("\n18 - Sair");
    
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1:
        if (lista2 == 1) {
          li2 = criar_lista();

          if (li2 != NULL) {
            printf("\n Lista criada com sucesso!");
          } else {
            printf("\n Lista não criada!");
          }
        } else {
          li = criar_lista();

          if(li != NULL){
            printf("\n Lista criada com sucesso!");
          }else{
            printf("\n Lista não criada!");
          }
        }
        
        break;


      case 2:
        // liberar lista
        if (lista2 = 1) {
          ok = liberar_lista(li2);
        } else {
          ok = liberar_lista(li);
        }

        if(ok){
          printf("\n Lista liberada com sucesso!");
        }else{
          printf("\n Lista não liberada!");
        }
        break;

      case 3:
        // inserir elemento no início
        ok = criar_dado(&dado);
        if (lista2 = 1) {
          ok = inserir_lista_inicio(li2, dado);
        } else {
          ok = inserir_lista_inicio(li, dado);
        }

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 4:
        // inserir elemento no final
        ok = criar_dado(&dado);
        if (lista2 == 1) {
          ok = inserir_lista_final(li2, dado);
        } else {
          ok = inserir_lista_final(li, dado);
        }

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 5:
        // inserir elemento de forma ordenada
        ok = criar_dado(&dado);
        if (lista2 == 1) {
          ok = inserir_lista_ordenada(li2, dado);
        } else {
          ok = inserir_lista_ordenada(li, dado);
        }

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 6:
        // remover elemento do início
        if (lista2 == 1) {
          ok = remover_lista_inicio(li2);
        } else {
          ok = remover_lista_inicio(li);
        }

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 7:
        // remover elemento do final
        if (lista2 == 1) {
          ok = remover_lista_final(li2);
        } else {
          ok = remover_lista_final(li);
        }

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

        if (lista2 == 1) {
          ok = remover_lista_meio(li2, dado);
        } else {
          ok = remover_lista_meio(li, dado);
        }

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

        if (lista2 == 1) {
          ok = buscar_lista_posicao(li2, pos, &dado);
        } else {
          ok = buscar_lista_posicao(li, pos, &dado);
        }

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

        if (lista2 == 1) {
          ok = buscar_lista_dado(li2, dado, &pos);
        } else {
          ok = buscar_lista_dado(li, dado, &pos);
        }

        if(ok){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento da %dª posição: ", pos);
          printf("%d", dado);
        }else{
          printf("\n Elemento não encontrado!");
        }

        break;

      case 11:
        // concatena duas listas
        if (lista2 != 1) {
          printf("\nNão é possivel concatenar!");
          printf("\nCrie outra lista");
        } else {
          li2 = concatena_lista(li, li2);
          printf("\nListas concatenadas!");
        }
        break;

      case 12:
          if (lista2 == 1) {
            li = copia_lista(li2);
            printf("Os itens copiados foram: ");
            imprimir_lista(li);
          } else {
            li2 = copia_lista(li);
            printf("Os itens copiados foram: ");
            imprimir_lista(li2);
          }
          
          break;
          
      case 13:
      if (lista2 == 1) {
        li2 = inverte_lista(li2);
        printf("\nLista invertida!");
      } else {
        li = inverte_lista(li);
        printf("\nLista invertida!");
      }
          break;
      
      case 14:
          // indica se a lista está em ordem
          if (lista2 == 1) {
            ok = verifica_ordem(li2);
            if (ok == 1) {
              printf("\nA lista está em ordem decrescente!");
            } else if (ok == 2) {
              printf("\nA lista está em ordem crescente!");
            } else {
              printf("\nA lista não está ordenada!");
            }
          } else {
            ok = verifica_ordem(li);
            if (ok == 1) {
              printf("\nA lista está em ordem decrescente!");
            } else if (ok == 2) {
              printf("\nA lista está em ordem crescente!");
            } else {
              printf("\nA lista não está ordenada!");
            }
          }
          break;

      case 15:
        // retorna o tamanho da lista
        if (lista2 == 1) {
          printf("\nA lista possui tamanho %d\n\n", calcula_tamanho(li2));
        } else {
          printf("\nA lista possui tamanho %d\n\n", calcula_tamanho(li));
        }
        break;

      case 16:
        lista2 = 1;
        printf("\n\nAgora você não pode modificar a lista 1");
          break;

      case 17:
        // imprime a lista
        printf("\n Lista encadeada: ");
        if (lista2 == 1) {
          ok = imprimir_lista(li2);
        } else {
          ok = imprimir_lista(li);
        }

        if(!ok){
          printf("\n Lista não encontrada!");
        }
        break;
      
      case 18:
        // libera memória e finaliza programa
        liberar_lista(li2);
        liberar_lista(li);

        printf("\nFinalizando...");
        break;

      default:
        printf("\nOpção inválida!");
        break;
    }
  }while(opcao != 18);

  return 0;
}