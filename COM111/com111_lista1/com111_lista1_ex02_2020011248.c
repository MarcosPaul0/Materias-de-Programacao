#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct aluno {
    unsigned int matricula;
    char nome[50];
    unsigned int diaNas;
    unsigned int mesNas;
    unsigned int anoNas;
    float nota;
};

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

void preencheRegistro(struct aluno *dados, struct aluno *registro, int numAlunos, int numAprovados) {
    int i, j = 0;

    for (i = 0; i < numAlunos; i++) {
        while (j < numAprovados) {
            if (dados[j].nota >= 6) {
                registro[j].matricula = dados[i].matricula;
                strncpy(registro[j].nome, dados[i].nome, 50);
                registro[j].diaNas = dados[i].diaNas;
                registro[j].mesNas = dados[i].mesNas;
                registro[j].anoNas = dados[i].anoNas;
                registro[j].nota = dados[i].nota;
            }
            break;
        }
        j++;
    }
}


void imprimeVetor(struct aluno *dados, int numAlunos) {
    printf("DADOS DOS ALUNOS APROVADOS:\n\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("Matrícula - %i.\n", dados[i].matricula);
        printf("Nome - %s.\n", dados[i].nome);
        printf("Data de nascimento - %d/%d/%d.\n", dados[i].diaNas, dados[i].mesNas, dados[i].anoNas);
        printf("Nota - %.1f.\n\n", dados[i].nota);
    }
}


int main() {
    int numeroAlunos, numeroAprovados = 0;
    setlocale(LC_ALL, "Portuguese");

    printf("Digite o número de alunos: ");
    scanf(" %d", &numeroAlunos);

    struct aluno *dados = (struct aluno*) malloc(sizeof(struct aluno) * numeroAlunos); //Aloca Memória para Todos os Alunos
    if (dados == NULL) {
        printf("Memória insuficiente!");
    }

    preencheVetor(dados, numeroAlunos);
    imprimeVetor(dados, numeroAlunos);

    for (int i = 0; i < numeroAlunos; i++) {
        if (dados[i].nota >= 6) {
            numeroAprovados++;
        }
    }
    
    struct aluno *registro = (struct aluno*) malloc(sizeof(struct aluno) * numeroAprovados); //Aloca Memória para os Alunos Aprovados
    if (registro == NULL) {
        printf("Memória insuficiente!");
    }

    preencheRegistro(dados, registro, numeroAlunos, numeroAprovados);
    imprimeVetor(registro, numeroAprovados);
    
    free(dados);
    free(registro);

    system("pause");
}