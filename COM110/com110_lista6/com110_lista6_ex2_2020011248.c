#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int notas_alunos[10];
    int i, m = 0, num_aprovados = 0, nota = 0, porcentagem;
    char gabarito[8], prova_alunos[10][8];

    //ENTRADA DO GABARITO
    printf("\n----------- GABARITO -----------\n\n");
    printf("As opcoes sao [a] [b] [c] e [d].\n\n");
    for (i = 0; i < 8; i++)
    {
        printf("Digite a resposta da questao [%d]: ", i + 1);
        scanf(" %c", &gabarito[i]);
    }

    //ENTTRADA DAS RESPOSTAS DOS ALUNOS
    printf("\n\n--------- PROVA DOS ALUNOS ---------\n\n");
    for (i = 0; i < 10; i++)
    {
        printf("Aluno %d: \n", i + 1);
        for (m = 0; m < 8; m++)
        {
            printf("Resposta da questao %d: ", m + 1);
            scanf(" %c", &prova_alunos[i][m]);
        }
    }

    //CÓDIGO DO CORRETOR
    for (i = 0; i < 10; i++)
    {
        for (m = 0; m < 8; m++)
        {
           if (prova_alunos[i][m] == gabarito[m])
           {
              nota += 1;
           }
        }
        notas_alunos[i] = nota;
        nota = 0;
    }

    //MOSTRANDO AS NOTAS INDIVIDUAIS
    printf("\n\n");
    for (i = 0; i < 10; i++)
    {
        printf("O aluno [%d] obteve nota %d.\n", i + 1, notas_alunos[i]);
        if (notas_alunos[i] >= 6)
        {
            num_aprovados += 1;
        }
    }

    //MOSTRANDO A PORCENTAGEM DE APROVADOS
    porcentagem = num_aprovados * 10;
    printf("\nA porcentagem de aprovados foi de %d%%.\n", porcentagem);
    
    return 0;
}