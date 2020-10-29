// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "filaEncadeada.h"

// protótipo da função que cria um dado 
int criar_dado(int *dado);
int solicitar_limite();
int perfil_cliente();
int pegar_senha(Fila *fi);
void imprime_insercao(int ok, Fila *fi);
void chamada(Fila *fi, int tipo);


// funcao principal
int main(void) {

  // no início a fila está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da fila
  Fila *fi_senhas = NULL;
  Fila *fi_caixa_pre = NULL;
  Fila *fi_caixa_con = NULL;
  Fila *fi_negocial_pre = NULL;
  Fila *fi_negocial_con = NULL;
  int opcao, ok, pos, limite, cont = 1;
  int cont_mesa1, cont_mesa2, cont_mesa3, cont_mesa4;
  int dado, senha;
  char chamar;

  // menu de opções para execuções de operações sobre a fila
  limite = solicitar_limite();

  //cria fila ddo banco
  fi_senhas = criar_fila();
  if (fi_senhas != NULL) {
    printf("\n Fila criada com sucesso!\n\n");
  } else{
    printf("\n Fila não criada!");
  }

  //registra as senhas na fila
  for (int i = 0; i < limite; i++) {
    ok = enfileirar(fi_senhas, i);

    if(ok == 1){
      printf("\n Senha %d, registrada com sucesso!", i);
    }else{
      printf("\n Falha na inserção!");
    }
  }

  fi_caixa_con = criar_fila();
  fi_caixa_pre = criar_fila();
  fi_negocial_con = criar_fila();
  fi_negocial_pre = criar_fila();

  do
  {
    printf("\n\nMenu de opções");
    printf("\n1 - Caixa");
    printf("\n2 - Negocial");
    printf("\n3 - Finalizar serviço");
    if (verifica_qtd(fi_senhas) == 0) {
      opcao = 3;
    } else {
      printf("\nTipo de Atendimento: ");
      scanf("%d", &opcao);
    }

    switch(opcao){

      case 1:
        opcao = perfil_cliente();
        senha = desenfileirar(fi_senhas);
        if (opcao == 1) {
          printf("A senha retirada foi [CP%d]", senha);
          ok = enfileirar(fi_caixa_pre, senha);
          imprime_insercao(ok, fi_caixa_pre);
        } else {
          printf("A senha retirada foi [CC%d]", senha);
          ok = enfileirar(fi_caixa_con, senha);
          imprime_insercao(ok, fi_caixa_con);
        }
        break;


      case 2:
        opcao = perfil_cliente();
        senha = desenfileirar(fi_senhas);
        if (opcao == 1) {
          printf("A senha retirada foi [NP%d]", senha);
          ok = enfileirar(fi_negocial_pre, senha);
          imprime_insercao(ok, fi_negocial_pre);
        } else {
          printf("A senha retirada foi [NC%d]", senha);
          ok = enfileirar(fi_negocial_con, senha);
          imprime_insercao(ok, fi_negocial_con);
        }
        break;

      case 3:
        ok = liberar_fila(fi_senhas);
        
        if (ok) {
          printf("\n Serviço de registro de senhas finalizado!");
        } else {
          printf("\n Fila não liberada!");
        }
        break;

      default:
        printf("\nOpção inválida!");
        break;
    }

  }while(opcao != 3);

  cont_mesa1 = tamanho_fila(fi_caixa_pre);
  cont_mesa2 = tamanho_fila(fi_caixa_con);
  cont_mesa3 = tamanho_fila(fi_negocial_pre);
  cont_mesa4 = tamanho_fila(fi_negocial_con);
  //Menu para chamada de senha
  do {
    do {
      printf("\n\nChamar o próximo [S]? ");
      scanf(" %c", &chamar);
    } while (chamar != 'S' && chamar != 's');

    opcao = (rand() % 2) + 1;
    if (verifica_vazia(fi_caixa_pre) == 1 && verifica_vazia(fi_caixa_con) == 1) {
      opcao = 2;
    } else if (verifica_vazia(fi_negocial_pre) == 1 && verifica_vazia(fi_negocial_con) == 1) {
      opcao = 1;
    }

    if (verifica_vazia(fi_caixa_con) == 1 && verifica_vazia(fi_caixa_pre) == 1 && verifica_vazia(fi_negocial_con) == 1 && verifica_vazia(fi_negocial_pre) == 1) {
      opcao = 3;
    }

    switch(opcao){

      case 1: //Caixa
        if (verifica_qtd(fi_caixa_pre) == 0) { //Chama Convencional
          chamada(fi_caixa_con, 2);
        } else if (verifica_qtd(fi_caixa_con) == 0) { //Chama Preferencial
          chamada(fi_caixa_pre, 1);
        } else if (cont % 3 != 0 && verifica_qtd(fi_caixa_pre) != 0) { //Chama Preferencial
          chamada(fi_caixa_pre, 1);
        } else if (cont % 3 == 0 && verifica_qtd(fi_caixa_con) != 0) {  //Chama Convencional
          chamada(fi_caixa_con, 2);
        }
        cont++;
        break;


      case 2: //Negocial
        if (tamanho_fila(fi_negocial_pre) == 0) { //Chama Convencional
          chamada(fi_negocial_con, 4);
        } else if (tamanho_fila(fi_negocial_con) == 0) { //Chama Preferencial
          chamada(fi_negocial_pre, 3);
        } else if (cont % 3 != 0 && tamanho_fila(fi_negocial_pre) != 0) { //Chama Preferencial
          chamada(fi_negocial_pre, 3);
        } else if (cont % 3 == 0 && verifica_qtd(fi_negocial_con) != 0) {  //Chama Convencional
          chamada(fi_negocial_con, 4);
        }
        cont++;
        break;

      case 3:
        printf("\n\nNão possui mais clientes nas filas!");
        ok = liberar_fila(fi_caixa_con);
        ok = liberar_fila(fi_caixa_pre);
        ok = liberar_fila(fi_negocial_con);
        ok = liberar_fila(fi_negocial_pre);
        break;

      default:
        printf("\nOpção inválida!");
        break;
    }

  } while(opcao != 3);


  printf("\n\nA mesa 1 atendeu %d clientes", cont_mesa1);
  printf("\nA mesa 2 atendeu %d clientes", cont_mesa2);
  printf("\nA mesa 3 atendeu %d clientes", cont_mesa3);
  printf("\nA mesa 4 atendeu %d clientes", cont_mesa4);
  printf("\n\n\nServiço Concluído");

  return 0;
}




int perfil_cliente() {
  int opcao = 0;
  
  do {
    printf("\n\n1 - Preferencial");
    printf("\n2 - Convencional");
    printf("\nDigite o perfil:");
    scanf(" %d", &opcao);
  } while (opcao != 1 && opcao != 2);

  return opcao;
}

int solicitar_limite() {
  int limite;
  printf("\n\nDigite limite de atendimentos de hoje: ");
  scanf(" %d", &limite);
  return limite;
}

void imprime_insercao(int ok, Fila *fi) {
  if(ok == 1){
    imprime_fila(fi);
  }else{
    printf("\n Falha na inserção!");
  }
}

void chamada(Fila *fi, int tipo) {
  int senha;

  senha = desenfileirar(fi);
  if (tipo == 1) {
    printf("\n\nSenha atual [CP%d]\n\n", senha);
  } else if (tipo == 2) {
    printf("\n\nSenha atual [CC%d]\n\n", senha);
  } else if (tipo == 3) {
    printf("\n\nSenha atual [NP%d]\n\n", senha);
  } else if (tipo == 4){
    printf("\n\nSenha atual [NC%d]\n\n", senha);
  }
}