#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct aluno {
    int matricula;
    char nome[50];
    int diaNas;
    int mesNas;
    int anoNas;
    float nota;
};

void preencheVetor(struct aluno *dados, int n) {
    printf("\n\nPREENCHA OS DADOS DOS ALUNOS:\n\n");
    for (int i = 0; i < n; i++) {
        printf("Matrícula do aluno: ");
        scanf(" %d", &dados[i].matricula);
        printf("Nome do aluno: ");
        scanf(" %s", &dados[i].nome);
        printf("Dia de nascimento: ");
        scanf(" %d", &dados[i].diaNas);
        printf("Mês de nascimento: ");
        scanf(" %d", &dados[i].mesNas);
        printf("Ano de nascimento: ");
        scanf(" %d", &dados[i].anoNas);
        printf("Nota: ");
        scanf(" %f", &dados[i].nota);
    }
    printf("\n\n");
}

void imprimeVetor(struct aluno *dados, int n) {
    printf("DADOS DOS ALUNOS REGISTRADOS:\n\n");
    for (int i = 0; i < n; i++) {
        printf("Matrícula - %i\n", dados[i].matricula);
        printf("Nome - %s\n", dados[i].nome);
        printf("Data de nascimento - %d/%d/%d\n", dados[i].diaNas, dados[i].mesNas, dados[i].anoNas);
        printf("Nota - %f\n\n", dados[i].nota);
    }
}

int main() {
    int numeroAlunos;
    setlocale(LC_ALL, "Portuguese");

    printf("Digite o número de alunos: ");
    scanf(" %d", &numeroAlunos);

    struct aluno *dados = (struct aluno*) malloc(sizeof(struct aluno) * numeroAlunos); //Aloca Memória

    preencheVetor(dados, numeroAlunos);
    imprimeVetor(dados, numeroAlunos);
    free(dados);

    system("pause");
}

/*
(a) Alocar memória dinamicamente para um vetor do tipo ALUNO.
(b) Preencher o vetor de alunos.
(c) Imprimir o vetor de alunos.
(d) Preencher o registro de um aluno.
(e) Imprimir o registro de um aluno.
*/