
// bibliotecas do sistema
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "pilha.h"

int verifica_ordem(char caracIn, char caracSet);

// funcao principal
int main(void) {

  // no início a pilha está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da pilha
  Pilha *pi1 = NULL;
  Pilha *pi2 = NULL;
  Pilha *pi3 = NULL;
  int opcao, ok, pos;
  char dado_saida;
  char comp01, comp02;

  //cria as três pilhas
  pi1 = criar_pilha();
  pi2 = criar_pilha();
  pi3 = criar_pilha();

  ok = empilhar(pi1, 'U');
  if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }
  ok = empilhar(pi1, 'O');
  if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }
  ok = empilhar(pi1, 'I');
  if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }
  ok = empilhar(pi1, 'E');
  if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }
  ok = empilhar(pi1, 'A');
  if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }
  
  // menu de opções para execuções de operações sobre a pilha
  do {
    //imprime os blocos
    imprime_pilha(pi1, pi2, pi3);

    printf("\n\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("           Menu de opções\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n1 - Mover da pilha 1 para 2");
    printf("\n2 - Mover da pilha 1 para 3");
    printf("\n3 - Mover da pilha 2 para 1");
    printf("\n4 - Mover da pilha 2 para 3");
    printf("\n5 - Mover da pilha 3 para 1");
    printf("\n6 - Mover da pilha 3 para 2");
    printf("\n7 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1:
        consultar_topo_pilha(pi1, &comp01);      
        consultar_topo_pilha(pi2, &comp02);
        if (verifica_ordem(comp01, comp02) == 1) {
          printf("\n\n  Não é possível realizar este movimento!\n\n");
          break;
        }  

        dado_saida = desempilhar(pi1);
        printf("\n\n%c\n\n", dado_saida);
        ok = empilhar(pi2, dado_saida);

        if (ok != 1) {
          printf("\n\nFalha na execução!");
        }
        break;


      case 2:
        consultar_topo_pilha(pi1, &comp01);      
        consultar_topo_pilha(pi3, &comp02);
        if (verifica_ordem(comp01, comp02) == 1) {
          printf("\n\n  Não é possível realizar este movimento!\n\n");
          break;
        }

        dado_saida = desempilhar(pi1);
        ok = empilhar(pi3, dado_saida);

        if (ok != 1) {
          printf("\n\nFalha na execução!");
        }
        break;

      case 3:
        consultar_topo_pilha(pi2, &comp01);      
        consultar_topo_pilha(pi1, &comp02);
        if (verifica_ordem(comp01, comp02) == 1) {
          printf("\n\n  Não é possível realizar este movimento!\n\n");
          break;
        }

        dado_saida = desempilhar(pi2);
        ok = empilhar(pi1, dado_saida);

        if (ok != 1) {
          printf("\n\nFalha na execução!");
        }
        break;

      case 4:
        consultar_topo_pilha(pi2, &comp01);      
        consultar_topo_pilha(pi3, &comp02);
        if (verifica_ordem(comp01, comp02) == 1) {
          printf("\n\n  Não é possível realizar este movimento!\n\n");
          break;
        }

        dado_saida = desempilhar(pi2);
        ok = empilhar(pi3, dado_saida);

        if (ok != 1) {
          printf("\n\nFalha na execução!");
        }
        break;

      case 5:
        consultar_topo_pilha(pi3, &comp01);      
        consultar_topo_pilha(pi1, &comp02);
        if (verifica_ordem(comp01, comp02) == 1) {
          printf("\n\n  Não é possível realizar este movimento!\n\n");
          break;
        }

        dado_saida = desempilhar(pi3);
        ok = empilhar(pi1, dado_saida);

        if (ok != 1) {
          printf("\n\nFalha na execução!");
        }
        break;

      case 6:
        consultar_topo_pilha(pi3, &comp01);      
        consultar_topo_pilha(pi2, &comp02);
        if (verifica_ordem(comp01, comp02) == 1) {
          printf("\n\n  Não é possível realizar este movimento!\n\n");
          break;
        }

        dado_saida = desempilhar(pi3);
        ok = empilhar(pi2, dado_saida);

        if (ok != 1) {
          printf("\n\nFalha na execução!");
        }
        break;
      
      case 7:
        liberar_pilha(pi1);
        liberar_pilha(pi2);
        liberar_pilha(pi3);
        printf("\nFinalizando...");
        break;

      default:
        printf("\nOpção inválida!");
        break;
    }

    ok = verifica_alfa(pi3);
    if (ok == 7) {
      printf("Você venceu!\n  Parabéns!\n");
      opcao = ok;
    }
  }while(opcao != 7);


  return 0;
}

int verifica_ordem(char caracIn, char caracSet) { 
  // 2 VERDADEIRO 1 FALSO
  if (caracIn == 'A') {
      return 0;
  } else if (caracIn == 'E') {
    if (caracSet != 'A') {
      return 0;
    } else {
      return 1;
    }
  } else if (caracIn == 'I') {
    if (caracSet != 'A' && caracSet != 'E') {
      return 0;
    } else {
      return 1;
    }
  } else if (caracSet == 'O') {
    if (caracSet != 'A' && caracSet != 'E' && caracSet != 'I') {
      return 0;
    } else {
      return 1;
    }
  } else if (caracIn == 'U') {
    if (caracSet != 'A' && caracSet != 'E' && caracSet != 'I' && caracSet != 'O') {
      return 0;
    } else {
      return 1;
    }
  } else {
    return 1;
  }
}

//IMPLEMENTAÇÃO DAS REGRAS