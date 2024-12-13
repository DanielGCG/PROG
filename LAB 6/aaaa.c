#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME 100

typedef struct {
    char nome[MAX_NOME];
    double nota[3];
    double media;
} Taluno;

int main() {
    FILE *arq;
    Taluno aluno;

    arq = fopen("alunos.dat", "rb");

    if (arq == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    printf("Conteúdo do arquivo 'alunos.dat':\n");
    while (fread(aluno.nome, sizeof(char), MAX_NOME, arq) > 0) {
        if (fread(aluno.nota, sizeof(double), 3, arq) == 3 && fread(&aluno.media, sizeof(double), 1, arq) == 1) {
            printf("\nNome: %s\n", aluno.nome);
            printf("Notas: %.2lf %.2lf %.2lf\n", aluno.nota[0], aluno.nota[1], aluno.nota[2]);
            printf("Média: %.2lf\n", aluno.media);
        } else {
            fprintf(stderr, "Erro ao ler as notas ou a média.\n");
            break;
        }
    }

    fclose(arq);
    return 0;
}
