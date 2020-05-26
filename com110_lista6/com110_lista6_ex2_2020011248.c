#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int gabarito[8], prova_alunos[10][8], notas_alunos[10];
    int i, m = 0, num_aprovados, porcentagem, nota = 0;

    //ENTRADA DO GABARITO
    printf("----------- GABARITO -----------\n\n");
    printf("As opções são [1] [2] [3] e [4].");
    for (i = 0; i < 8; i++)
    {
        printf("Digite a resposta da questao [%d]: ", i + 1);
        scanf("%d", &gabarito[i]);
    }

    //ENTTRADA DAS RESPOSTAS DOS ALUNOS
    printf("----------- PROVA -----------\n\n");
    for (i = 0; i < 10; i++)
    {
        printf("Aluno %d: \n", i + 1);
        for (m = 0; m < 8; m++)
        {
            printf("Resposta da questao %d: ", m + 1);
            scanf("%d", &prova_alunos[i][m]);
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
    for (i = 0; i < 10; i++)
    {
        printf("O aluno [%d] obteve nota %d.", i + 1, notas_alunos[i]);
        if (notas_alunos[i] >= 6)
        {
            num_aprovados += 1;
        }
    }

    //MOSTRANDO A PORCENTAGEM DE APROVADOS
    porcentagem = (num_aprovados / 10) * 100;
    printf("A porcentagem de aprovados foi de %d%%.", porcentagem);
    
    return 0;
}