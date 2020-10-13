#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitmap.h"

// Função para criar o bitmap
int* criar_bitmap(int id){

	int *bitmap = (int*) calloc(id, sizeof(int*));

	return bitmap;
}


// Função para liberar o bitmap
int liberar_bitmap(int* bitmap){
	if(bitmap == NULL){
		return 0;
	}

	free(bitmap);

	return 1;
}


// Função para imprimir o bitmap
void imprime_bitmap(int* bitmap, int lim){
	int i;

	for(i=0; i<lim; i++){
		printf("%d ", bitmap[i]);
	}

}


// Função com os comandos do bitmap, para ficar organizado
void comandos_bitmap(int* bitmap, int cod){
	int i;
	//printf("A");
	FILE *dados;

	char auxc;
	char *nome, codigo, sexo, nacion, comprou;
	int cont;
	int idade, id;


	auxc = 'a';
	cont = 0;
	//observa quantos dados tem no arquivo
	dados = fopen("dados.txt", "r");
		rewind(dados);
		while(auxc != EOF){
			auxc = fgetc(dados);
			if(auxc == '\n')
				cont++;
		}
	fclose(dados);
	
	//comandos
	switch(cod){
		case 1: //bitmap sexo

			dados = fopen("dados.txt", "r");
				rewind(dados);

				for(i=0; i<cont; i++){
					fscanf(dados, " %s %c %d %c %c %d", nome, &sexo, &idade, &nacion, &comprou, &id);
					//printf("\nsexo = %c", sexo);

					// Faz o bitmap em si
					if(sexo == 'F')
						bitmap[i] = 1;
					else //sexo == 'M'
						bitmap[i] = 0;
					auxc = fgetc(dados);
				}
			fclose(dados);

			printf("\nBitmap igualdade (sexo) (1 = F, 0 = M):\n");
			imprime_bitmap(bitmap, id);

			break;

		case 2: //bitmap nacionalidade

			dados = fopen("dados.txt", "r");
				rewind(dados);

				for(i=0; i<cont; i++){
					fscanf(dados, " %s %c %d %c %c %d", nome, &sexo, &idade, &nacion, &comprou, &id);

					// Faz o bitmap em si
					if(nacion == 'N')
						bitmap[i] = 1;
					else //nacion == E
						bitmap[i] = 0;
					auxc = fgetc(dados);
				}
			fclose(dados);

			printf("\nBitmap igualdade (nacionalidade) (1 = Nativo, 0 = Estrangeiro):\n");
			imprime_bitmap(bitmap, id);

			break;
		case 3: //bitmap comprou pacote

      dados = fopen("dados.txt", "r");
				rewind(dados);

				for(i=0; i<cont; i++){
					fscanf(dados, " %s %c %d %c %c %d", nome, &sexo, &idade, &nacion, &comprou, &id);

					// Faz o bitmap em si
					if(comprou == 'S')
						bitmap[i] = 1;
					else //comprou == 'N'
						bitmap[i] = 0;
					auxc = fgetc(dados);
				}
			fclose(dados);

			printf("\nBitmap igualdade (pacote) (1 = Sim, 0 = Não):\n");
			imprime_bitmap(bitmap, id);

			break;
		case 4: //bitmap promoção

			dados = fopen("dados.txt", "r");
				rewind(dados);

				for(i=0; i<cont; i++){
					fscanf(dados, " %s %c %d %c %c %d", nome, &sexo, &idade, &nacion, &comprou, &id);

					// Faz o bitmap em si
					if(idade < 18 || idade > 60)
						bitmap[i] = 1;
					else //idade >= 18 || idade <=60
						bitmap[i] = 0;
					auxc = fgetc(dados);
				}
			fclose(dados);

			printf("\nBitmap igualdade (promoção) (1 = Sim, 0 = Não):\n");
			imprime_bitmap(bitmap, id);

			break;

		case 5: //bitmap promoção especial

			dados = fopen("dados.txt", "r");
				rewind(dados);

				for(i=0; i<cont; i++){
					fscanf(dados, " %s %c %d %c %c %d", nome, &sexo, &idade, &nacion, &comprou, &id);

					// Faz o bitmap em si
					if(idade > 18 && nacion == 'E' && comprou == 'N')
						bitmap[i] = 1;
					else
						bitmap[i] = 0;
					auxc = fgetc(dados);
				}
			fclose(dados);

			printf("\nBitmap AND -- promoção especial\n");
			printf("Acontece quando a pessoa tem mais de 18 anos, é estrangeira e não comprou o pacote ainda\n");
			printf("1 = Promoção especial disponível, 0 = Não disponível:\n");
			imprime_bitmap(bitmap, id);

			break;
		default:
			break;
	}

	return;
}


/*
	void bitmap_igualdade(int* bitmap){
		int i;

		FILE *dados;

		char auxc = 'a', *nome, codigo, sexo;
		int cont = 0, idade, id;

		dados = fopen("dados.txt", "r");
			while(auxc != EOF){
				auxc = fgetc(dados);
				if(auxc == '\n')
					cont++;
			}
			rewind(dados);
			for(i=0; i<cont; i++){

				fscanf(dados, " %s %c %d %c %d", nome, &sexo, &idade, &codigo, &id);
				if(sexo == 'M'){
					bitmap[0][i] = 1;
					bitmap[1][i] = 0;	
				}
				else{
					bitmap[1][i] = 1;
					bitmap[0][i] = 0;
				}
				auxc = fgetc(dados);
			}
		fclose(dados);


		return;
	}*/
	
	int* criar_matriz(int id){
		int i, j;
		//id = id-1;
		//Matriz de numero de linhas = id e numero de colunas = 7 (numero de campos bitmap)
		printf("\nLinhas: %d Colunas %d\n\n", id, 7);
    int *matriz = (int*) malloc(id * 7 * sizeof(int) );
    //int *matriz = (int*) calloc(id * 7, sizeof(int) );
    //printf("\nLinhas: %d Colunas: %d\n\n", id, 7);


    if (matriz != NULL) {
      printf("\nMatriz criada com sucesso!\n\n");
      //printf("\nPonteiro memoria: %p\n\n", bitsliced);
      return matriz;
    } else {//(bitsliced == NULL)
      printf("\nMemória Insuficiente!\n\n");
		  return NULL ;
    }
	}

	void liberar_matriz(int* matriz, int id){

		int i;

    //printf("0000");


		free(matriz);
	}

  /*for (int i = 0; i < linhas; i++)
    {
        free(ptrM[i]);
    }
    free(ptrM);*/
	
	/*	Alocação de matrizes dinamicamente tem que alocar um vetor de vetores dinamicamente (linhas), depois para cada elemento do vetor primário, alocar dinamicamente as colunas

		Int **var = (int**) malloc(10 * sizeof(int*));
		For(i=0; i<10; i++){
			var[i] = (int*) malloc(8 * sizeof(int));
		}

		Faz-se uma matriz 10x8
		Para liberar uma matriz tem que ser ao contrário

		For(i=0; i<10; i++){
			Free(var[i]);
		}
		Free(var);
	
	
	void idade_slice(int** bitsliced){
		int i, j;

		FILE *dados;

		char auxc = 'a', codigo, sexo;
		char *nome;
		int cont = 0, idade, id;
		
		dados = fopen("dados.txt", "r");
			while(auxc != EOF){
				auxc = fgetc(dados);
				//printf("\nauxc = %c", auxc);
				if(auxc == '\n')
					cont++;
			}
		fclose(dados);

		//	fseek(dados, 0, SEEK_SET);
		//	rewind(dados);

		dados = fopen("dados.txt", "r");
			for(i=0; i<cont; i++){

				
				fscanf(dados, " %s %c %d %c %d", nome, &sexo, &idade, &codigo, &id);
							//printf("\nauxc = %c", auxc);
							//printf("\nId: %d", id);
							//printf("\nNome: %s", nome);
							//printf("\nSexo: %c", sexo);
							//printf("\nIdade: %d", idade);
							//printf("\nCódigo: %c\n\n", codigo);
							

				for(j=6; j>=0; j--){
					//printf("\nidade = %d", idade);
					bitsliced[i][j] = idade%2;
					if(idade != 1)
						idade = idade/2;
					else
						idade = 0;
				}

				auxc = fgetc(dados);
			}
		fclose(dados);

	}
	void imprime_bitsliced(int** bitsliced){
		int i, j;

		FILE *dados;

		char auxc = 'a', *nome, codigo, sexo;
		int cont = 0, idade, id;
		

		dados = fopen("dados.txt", "r");
			while(auxc != EOF){
				auxc = fgetc(dados);
				if(auxc == '\n')
					cont++;
			}
			rewind(dados);
			for(i=0; i<cont; i++){

				fscanf(dados, " %s %c %d %c %d", nome, &sexo, &idade, &codigo, &id);

				if(idade < 10)
					printf("\n%d   = ", idade);
				else
					if(idade < 100)
						printf("\n%d  = ", idade);
					else
						printf("\n%d = ", idade);
				for(j=0; j<7; j++){
					printf("%d ", bitsliced[i][j]);
				}


				auxc = fgetc(dados);
			}
		fclose(dados);

	}
*/

void preenche_matriz(int* matriz){
  int i, cont;
	char nome[30], sexo, nacion, comprou, auxc;
	int idade, id;

	FILE *dados;
  
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
      printf("\nId: %d", id);
      printf("\nNome: %s", nome);
      printf("\nSexo: %c", sexo);
      printf("\nIdade: %d", idade);
      printf("\nNacionalidade: %c", nacion);
      printf("\nComprou pacote? %c\n\n", comprou);

      // Preenche o campo de sexo da linha, Feminino = 1, Masculino = 0//
      if(sexo == 'F')
          matriz[i*7] = 1;
      else
          matriz[i*7] = 0;
      //--------------------------------------------------------------//

      // Preenche o campo de idade <18 da linha, idade esta subdividida em 3 faixas, logo usam-se 2 arrays de indices bitmap para salvar as categorias
      // Caso idade for < 18, campo do primeiro array é 1 e campo do segundo array é 0
      // Caso idade estiver entre 18 e 60 anos, ambos os campos são 0
      // Caso idade for > 60, campo do primeiro array é 0 e campo do segundo array é 1

      //Campo no primeiro array//
      if(idade < 18)
          matriz[i*7 + 1] = 1;
      else
          matriz[i*7 + 1] = 0;
      //---------------------//

      //Campo no segundo array//
      if(idade > 60)
          matriz[i*7 + 2] = 1;
      else
          matriz[i*7 + 2] = 0;
      //---------------------//




      // Preenche o campo de nacionalidade da linha, Nativo = 1, Estrangeiro = 0 //
      if(nacion == 'N')
          matriz[i*7 + 3] = 1;
      else
          matriz[i*7 + 3] = 0;
      //------------------------------------------------------------------------//


      // Preenche o campo que indica se o aluno comprou pacote de intercambio, caso tenha comprado, 1, caso nao tenha comprado, 0//
      if(comprou == 'S')
          matriz[i*7 + 4] = 1;
      else
          matriz[i*7 + 4] = 0;
      //-------------------------------------------------------------------------------------------------------------------------//

      // Verifica se o aluno tem direito a uma promocao, que tem condicao do aluno ser menor de 18 anos ou maior de 60.//
      // Caso tenha direito a promocao, campo = 1, caso nao, campo = 0//
      if(idade < 18 || idade > 60)
          matriz[i*7 + 5] = 1;
      else
          matriz[i*7 + 5] = 0;
      //------------------------------------------------------------------------------------------------------------------------//

      // Verifica se o aluno tem direito a uma promocao especial para estrangeiros maiores de idade.//
      // Caso tenha direito a promocao, campo = 1, caso nao, campo = 0//
      if(idade > 18 && nacion == 'E' && comprou == 'N')
          matriz[i*7 + 6] = 1;
      else
          matriz[i*7 + 6] = 0;
      //-------------------------------------------------------------------------------------------//
    }
  fclose(dados);
  blaus(matriz);
}


// Função para imprimir o bitmap
void blaus(int* matriz){
	int i, j;

	// for(i=0; i<lim; i++){
	// 	printf("%d ", bitmap[i]);
	// }

  printf("\n	Sexo	|  <18	|  >60	|Nacionalidade|	Pacote	|	Promo1  |	Promo2\n\n");
  for (i=0; i<10; i++){
    printf("	%d	    |	%d	|	%d	|   	%d    | 	  %d   	|   	%d	 |   	%d\n", matriz[(i*7)], matriz[(i*7)+1], matriz[(i*7)+2], matriz[(i*7)+3], matriz[(i*7)+4], matriz[(i*7)+5], matriz[(i*7)+6]);
  }
}

int consulta_bitmap(int* matriz) {
	int *vetor = (int*) malloc(sizeof(int) * 7);
	int opcao;

	printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("             Busca de Dados\n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
	printf("1 - Quantos compraram o Pacote e são Estrangeiros:\n");
	printf("2 - Quantos compraram o pacote e são Brasileiros:\n");
	printf("3 - Quantos tiveram a promoção 1 ou 2:\n");
	printf("4 - Quantos tiveram a promoção 1 e 2:\n");
	printf("5 - Sair da busca:\n");
	scanf(" %d", &opcao);
	
	do {
		switch (opcao)
		{
		case 1:
			
			break;
		
		default:
			break;
		}
	} while (opcao != 4);
	
	free(vetor);
}