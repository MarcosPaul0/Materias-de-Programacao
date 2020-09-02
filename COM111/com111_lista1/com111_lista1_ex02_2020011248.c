#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct aluno {
    unsigned int matricula;
    char nome[50];
    unsigned int diaNas;
    unsigned int mesNas;
    unsigned int anoNas;
    float nota;
};

void *alocaVetor(int numAlunos) {
    struct aluno *vetor;
    vetor = (struct aluno*) malloc(sizeof(struct aluno) * numAlunos);
    if (vetor == NULL) {
        printf("Memória Insuficiente!");
    } else {
        return vetor;
    }
}

void preencheVetor(struct aluno *dados, int numAlunos) {
    printf("\n\nPREENCHA OS DADOS DOS ALUNOS:\n\n");
    for (int i = 0; i < numAlunos; i++) {
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
        printf("\n");
    }
}

void imprimeVetor(struct aluno *dados, int numAlunos) {
    for (int i = 0; i < numAlunos; i++) {
        printf("Matrícula - %i.\n", dados[i].matricula);
        printf("Nome - %s.\n", dados[i].nome);
        printf("Data de nascimento - %d/%d/%d.\n", dados[i].diaNas, dados[i].mesNas, dados[i].anoNas);
        printf("Nota - %.1f.\n\n", dados[i].nota);
    }
}

void imprimeAprovados(struct aluno *dados, int numAlunos) {
    printf("DADOS DOS ALUNOS APROVADOS:\n\n");
    for (int i = 0; i < numAlunos; i++) {
        if (dados[i].nota >= 6) {
            printf("Matrícula - %i.\n", dados[i].matricula);
            printf("Nome - %s.\n", dados[i].nome);
            printf("Data de nascimento - %d/%d/%d.\n", dados[i].diaNas, dados[i].mesNas, dados[i].anoNas);
            printf("Nota - %.1f.\n\n", dados[i].nota);
        }
    }
}

int main() {
    int numeroAlunos, numeroAprovados = 0;
    setlocale(LC_ALL, "Portuguese");

    printf("Digite o número de alunos: ");
    scanf(" %d", &numeroAlunos);

    struct aluno *dados;

    dados = alocaVetor(numeroAlunos);
    preencheVetor(dados, numeroAlunos);
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
    printf("DADOS DOS ALUNOS REGISTRADOS:\n\n");
    imprimeVetor(dados, numeroAlunos);

    for (int i = 0; i < numeroAlunos; i++) {
        if (dados[i].nota >= 6) {
            numeroAprovados++;
        }
    }

    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
    imprimeAprovados(dados, numeroAlunos);

    free(dados);
    return 0;
}