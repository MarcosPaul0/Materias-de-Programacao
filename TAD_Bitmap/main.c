#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitmap.h"


void obter_dados(char *nome, char *sexo, int *idade, char *nacion, char *comprou);

int main(void) {
  int opcao, ok, i, cont;
  int *matriz = NULL;
	char nome[30], sexo, nacion, comprou, auxc;
	int idade, id;

	FILE *dados;

	//O id recebe o último id registrado + 1
	dados = fopen("dados.txt", "r");
  auxc = 'a';
	//posiciona o cursor no final	
  fseek(dados, 0, SEEK_END);
	//lê um char até achar o dado de "comprou pacote"
  while(auxc != 'N' && auxc != 'S'){
		//vai andando pra trás e lendo o auxc
    fseek(dados, -(2*sizeof(char)), SEEK_CUR);
    auxc = fgetc(dados);
  }
	//quando o cursor estiver no "comprou pacote", lê o id
  fscanf(dados, "%d", &id);

	fclose(dados);
	id++;
	//printf("id = %d\n\n", id);
  

 
  //Iniciando a matriz de indices bitmap antes do menu
  //Caso o usuario tente usar sem "criar a matriz"ainda sera possivel
  matriz = criar_matriz(id);
  preenche_matriz(matriz);

	do{


		printf("\nEscolha uma opção:\n\n");
		printf("1: Inserir um novo dado na lista\n"); //será inserido no final
		printf("2: Imprimir os dados registrados\n");
    printf("3: Atualizar matriz de dados dos clientes (recomendado apos inserir nova entrada)\n");
		printf("4: Consultar numero de clientes homens e mulheres\n");
		printf("5: Consultar nacionalidade dos clientes que compraram o pacote de intercambio\n");
    printf("6: Consultar quantos clientes tem direito a promocao 1\n");
    //printf("(clientes menores de 18 anos ou maiores de 60)\n\n");
    printf("7: Consultar quantos clientes tem direito a promocao especial\n");
    //printf("(clientes estrangeiros, maiores de idade, que nao tenham comprado pacote de intecambio)\n\n");
    //printf("8: Consultar quantos clientes sao menores de 18 ou tem mais de 60 anos\n");
    printf("8: Consulta detalhada\n");
    printf("9: Finalizar programa\n");
		printf("Digite sua escolha: ");
		scanf("%d", &opcao);

		switch(opcao){
			case 1: //insere dados
				system("clear");

						obter_dados(nome, &sexo, &idade, &nacion, &comprou);


						dados = fopen("dados.txt", "a");
							ok = fprintf(dados, "%s %c %d %c %c %d\n", nome, sexo, idade, nacion, comprou, id);
						fclose(dados);

						id++;

				if(ok != EOF){
					printf("\nInseriu com sucesso!\n\n");
				}
				else{
					printf("\nNão foi possível fazer a inserção!\n\n");
				}
				
				break;
			case 2: //imprimir dados
				system("clear");

				auxc = 'a';
				cont = 0;
				dados = fopen("dados.txt", "r");
					while(auxc != EOF){
						auxc = fgetc(dados);
						if(auxc == '\n')
							cont++;
					}
					rewind(dados);
					for(i=0; i<cont; i++){
						fscanf(dados, " %s %c %d %c %c %d", nome, &sexo, &idade, &nacion, &comprou, &id);
            printf("\n\n-=-=-=-=-=-=-=-=--=-=--=\n");
						printf("\t\tRegistro %d\n", i+1);
            printf("-=-=-=-=-=-=-=-=--=-=--=\n");
						printf("\n Id: %d", id);
						printf("\n Nome: %s", nome);
						printf("\n Sexo: %c", sexo);
						printf("\n Idade: %d", idade);
						printf("\n Nacionalidade: %c", nacion);
						printf("\n Comprou pacote? %c\n\n", comprou);
						auxc = fgetc(dados);
					}
				fclose(dados);


				break;

			case 3: //matriz
				system("clear");

				matriz = criar_matriz(id);
        
        preenche_matriz(matriz);
        imprime_matr(matriz);

        //liberar_matriz(matriz);
				
				break;

			case 4:
				system("clear");

				consultar(matriz, 1);

				break;

			case 5:
				system("clear");

				consultar(matriz, 2);

				break;

       case 6:
        system("clear");

        consultar(matriz, 3);
        break;
      
       case 7:
				system("clear");

				consultar(matriz, 4);
        break;

      //  case 8:
			// 	system("clear");
				
      //   consultar(matriz, 5);
      //   break;
			
      case 8:
				system("clear");
        
        consulta_bitmap(matriz, id);
        break;

      case 9:
				system("clear");
        
        liberar_matriz(matriz);
				printf("Matriz liberada, encerrando programa...\n\n");
        break;
			
			default:
				printf("Digite uma opção válida! ");
		}
	} while (opcao != 9);
  return 0;
}


void obter_dados(char *nome, char *sexo, int *idade, char *nacion, char *comprou){
	//recebe o nome
	printf("\nDigite o nome: ");
	scanf(" %s", nome); //recebe até o espaço mesmo, porque será colocado no arquivo

	//recebe o Sexo
	do{
		printf("Digite o sexo - (M) ou (F): ");
		scanf(" %c", sexo);
	} while (*sexo != 'M' && *sexo != 'F');

	//recebe a idade
	do{
		printf("Digite a idade: ");
		scanf("%d", idade);
	} while ( (*idade) < 0);

	//recebe a nacionalidade
	do{
		printf("Digite a nacionalidade - (E)strangeiro ou  (N)ativo: ");
		scanf(" %c", nacion);
	} while(*nacion != 'E' && *nacion != 'N');

	//recebe se comprou o pacote
	do{
		printf("Comprou o pacote de intercâmbio? S/N");
		scanf(" %c", comprou);
	} while(*comprou != 'S' && *comprou != 'N');
}
