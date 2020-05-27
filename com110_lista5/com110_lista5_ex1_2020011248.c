#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int escolha, var1, var2, var3, var4, var5, caractere = 1, largura, perimetro, area, linha = 0, coluna = 0;
    float espaco;
    
    while (escolha < 1 || escolha > 6)
    {
        printf("-----------------------------------\n");
        printf("           MENU DE OPCOES\n");
        printf("-----------------------------------\n");
        printf("1. Quadrado\n2. Retangulo\n3. Triangulo Equilatero\n");
        printf("4. Triangulo Retangulo (catetos iguais)\n5. Trapezio\n6. Sair");
        printf("\n\nEscolha uma das Formas Geometricas: ");
        scanf("%d", &escolha);
        if (escolha > 6 || escolha < 1) {
            printf("\nResposta invalida! Tente novamente.\n\n");
        }
        if (escolha == 1) {                              //Código do QUADRADO
            printf("Digite o comprimento dos lados: ");
            scanf("%d", &var1);
            area = var1 * var1;
            perimetro = var1 * 4; 

            printf("\n======= QUADRADO =======\n\n");

            printf("Area = %d\n", area);
            printf("Perimetro = %d\n\n", perimetro);
            printf(" ");
            for (var2 = var1; var2 > 0; var2--)
            {
                printf("_");
            }
            printf("\n");
            for (linha = 0; linha < var1; linha++)
            {
                printf("|");
                for (coluna = 0; coluna < var1; coluna++)
                {
                    printf("O");
                }
                printf("|");
                printf("\n");
            }
            printf(" ");
            for (var2 = var1; var2 > 0; var2--)
            {
                printf("-");
            }
            printf("\n");
        }           
        if (escolha == 2) {                               //Código do RETÂNGULO
            printf("Digite a base e a altura: ");
            scanf("%d%d", &var1, &var2);
            area = var1 * var2;
            perimetro = (var1 * 2) + (var2 * 2);

            printf("\n======= RETANGULO =======\n");

            printf("Area = %d\n", area);
            printf("Perimetro = %d\n\n", perimetro);
            printf(" ");
            for (var3 = var1; var3 > 0; var3--)
            {
                printf("_");
            }
            printf("\n");
            for (linha = 0; linha < var2; linha++)
            {
                printf("|");
                for (coluna = 0; coluna < var1; coluna++)
                {
                    printf("O");
                }
                printf("|");
                printf("\n");
            }
            printf(" ");
            for (var3 = var1; var3 > 0; var3--)
            {
                printf("-");
            }
            printf("\n");
        }
        if (escolha == 3) {                                            //Código do TRIÂNGULO EQUILÁTERO
            printf("Digite o comprimento dos lados e a altura: \n");
            scanf("%d", &var1);
            area = (pow(var1, 2) * sqrt(3)) / 4;
            perimetro = var1 * 3;
            largura = var1 * 2;

            printf("\n======= TRIANGULO EQ =======\n");

            printf("Area = %d\n", area);
            printf("Perimetro = %d\n\n", perimetro);
            for (var2 = 0; var2 < var1; var2++)
            {
                for (var3 = 1; var3 <= largura; var3++)
                {
                    printf(" ");
                }
                largura--;
                for (var4 = 0; var4 < caractere; var4++)
                {
                     if (var4 == 0)
                   {
                       printf("/");
                   }
                   printf("O");
                   if (var4 == caractere - 1)
                   {
                       printf("\\");
                   }
                }
                printf("\n");
                caractere += 2;  
            } 
            printf("      ");
            for (largura = largura * 2; largura > 0; largura--)
            {
                printf("-");
            }
            
        }
        if (escolha == 4) {                                    //Código do TRIÂNGULO RETÂNGULO
            printf("Digite o comprimento dos catetos: ");
            scanf("%d", &var1);
            area = (var1 * var1) / 2; 
            perimetro = sqrt(var1 * var1 * 2) + (var1 * 2);

            printf("\n======= TRIANGULO RET =======\n");

            printf("Area = %d\n", area);
            printf("Perimetro = %d\n\n", perimetro);
            printf(" ");
            for (var2 = var1; var2 > 0; var2--)
            {
                printf("_");
            }
            printf("\n");
            for (var1; var1 > 0; var1--)
            {
                printf("|");
                for (coluna = var1; coluna > 0; coluna--)
                {
                    printf("O");
                    if (coluna == 1)
                    {
                        printf("/");
                    }
                    
                }
                printf("\n");
            }
            
        }
        if (escolha == 5) {                                                            //Código do TRAPÉZIO
            printf("Digite o comprimento da base maior, da base menor e sua altura: ");
            scanf("%d%d%d", &var1, &var2, &var3);
            area = (var2 * var3) + (((var1 - var2) * 2 * var3) / 2);
            perimetro = var1 + var2 + (sqrt(pow(var3, 2) * pow(var1 - var2, 2)) * 2); 
            var4 = var1 / 2;

            printf("\n======= TRAPEZIO =======\n");
            printf("Area = %d\n", area);
            printf("Perimetro = %d\n\n", perimetro);
            
            for (var3; var3 > 0; var3--)
            {
                for (var4; var4 > 0; var4--)  //Espaços
                {
                    printf(" ");
                }
                for (var5 = var1; var5 > 0; var5--)  //Caracteres
                {
                    printf("O");
                }
                printf("\n");
            }
            

        }

        if (escolha == 6) {
            break;
        }
    }
    printf("\nObrigado por utilizar este programa!\n\n");

    return 0;
}