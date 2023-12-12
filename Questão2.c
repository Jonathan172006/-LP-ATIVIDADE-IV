#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char dataNascimento[15];
    float nota1;
    float nota2;
    float media;
} Aluno;

float calcularMedia(Aluno aluno) {
    aluno.media = (aluno.nota1 + aluno.nota2) / 2;
    return aluno.media;
}

void verificarAprovacao(Aluno aluno) {
    if (aluno.media >= 7.0) {
        printf("O aluno %s está aprovado.\n", aluno.nome);
    } else {
        printf("O aluno %s está reprovado.\n", aluno.nome);
    }
}

int main() {
    Aluno alunos[5];

    for (int i = 0; i < 5; i++) {
        printf("Digite o nome do aluno %d: ", i+1);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        strtok(alunos[i].nome, "\n");

        printf("Digite a data de nascimento do aluno %d: ", i+1);
        fgets(alunos[i].dataNascimento, sizeof(alunos[i].dataNascimento), stdin);
        strtok(alunos[i].dataNascimento, "\n");

        printf("Digite a primeira nota do aluno %d: ", i+1);
        scanf("%f", &alunos[i].nota1);

        printf("Digite a segunda nota do aluno %d: ", i+1);
        scanf("%f", &alunos[i].nota2);

        calcularMedia(alunos[i]);
        verificarAprovacao(alunos[i]);
    }

    return 0;
}
