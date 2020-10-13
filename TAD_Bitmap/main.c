#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitmap.h"


void obter_dados(char *nome, char *sexo, int *idade, char *nacion, char *comprou);

int main(void) {
  int opcao, ok, i, cont;
  int *bitmapS, *bitmapN, *bitmapI, *bitmapP, *bitmapD, *bitmapE;
  int *matriz;
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
 

	do{
		printf("Escolha uma opção:\n");
		printf("1: Inserir um novo dado na lista\n"); //será inserido no final
		printf("2: Imprimir os dados registrados\n");
		printf("3: Sair\n");
		printf("4: Criar e imprimir o bitmap de sexo\n");
		printf("5: Criar e imprimir o bitmap de nacionalidade\n");
		printf("6: Criar e imprimir o bitmap de pacote\n");
  		printf("7: Criar e imprimir o bitmap de promoção (OR)\n");
		printf("8: Criar e imprimir o bitmap de promoção especial (AND)\n");
    	printf("9: Criar matriz (AND)\n");
    	printf("10: Finalizar programa\n");
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
						printf(" Registro %d", i);
						printf("\nId: %d", id);
						printf("\nNome: %s", nome);
						printf("\nSexo: %c", sexo);
						printf("\nIdade: %d", idade);
						printf("\nNacionalidade: %c", nacion);
						printf("\nComprou pacote? %c\n\n", comprou);
						auxc = fgetc(dados);
					}
				fclose(dados);


				break;

			case 3: //encerra
				system("clear");

				printf("Encerrando...");

				break;

			case 4: //bitmap sexo, igualdade
				system("clear");

				bitmapS = criar_bitmap(id);
				comandos_bitmap(bitmapS, 1);
				liberar_bitmap(bitmapS);

				printf("\n\n");

				break;

			case 5: //bitmap nacionalidade, igualdade

				system("clear");

				bitmapN = criar_bitmap(id);
				comandos_bitmap(bitmapN, 2);
				liberar_bitmap(bitmapN);

				printf("\n\n");

				break;
			
			case 6: //bitmap comprou pacote, igualdade

				system("clear");

				bitmapI = criar_bitmap(id); 
				comandos_bitmap(bitmapI, 3);
				liberar_bitmap(bitmapI);

				printf("\n\n");

				break;

			case 7: //bitmap promoção, igualdade

				system("clear");

				bitmapP = criar_bitmap(id);
				comandos_bitmap(bitmapP, 4);
				liberar_bitmap(bitmapP);

				printf("\n\n");

				break;

			case 8: //bitmap promoção especial, AND

				system("clear");

				bitmapE = criar_bitmap(id);
				comandos_bitmap(bitmapE, 5);
				liberar_bitmap(bitmapE);

				printf("\n\n");

				break;

			case 9: //bitsliced
				system("clear");

				matriz = criar_matriz(id);
        
        		preenche_matriz(matriz);
				//free(matriz);

				liberar_matriz(matriz, id);
				//idade_slice(bitsliced);
				//imprime_bitsliced(bitsliced);
				//liberar_bitsliced(bitsliced, id);
				//printf("\n\n");
				
				break;

			case 10:
				system("clear");

				liberar_matriz(matriz, 10);
				printf("Matriz liberada, encerrando programa...\n\n");
				break;
			
			default:
				printf("Digite uma opção válida! ");
		}
	} while (opcao != 10);
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
