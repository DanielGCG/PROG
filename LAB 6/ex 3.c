#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100

typedef struct {
    char nome[MAX_NOME];
    double nota[3];
    double media;
} Taluno;

int main() {
    FILE *arq;
    Taluno aluno;

    arq = fopen("alunos.dat", "rb+");

    if (arq == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int mudouquantos = 0, total = 0;
    double medianova;
    long posicao;

    // Primeira leitura e atualização das médias
    while (fread(aluno.nome, sizeof(char), MAX_NOME, arq) > 0) {
        if (fread(aluno.nota, sizeof(double), 3, arq) == 3 && fread(&aluno.media, sizeof(double), 1, arq) == 1) {
            printf("Nome: %s\n", aluno.nome);
            printf("Notas originais: %.2lf %.2lf %.2lf\n", aluno.nota[0], aluno.nota[1], aluno.nota[2]);
            printf("Media antiga: %lf\n", aluno.media);

            // Pede para o usuário entrar com as notas novamente para recalcular a média
            printf("Digite as notas (P1 P2 P3) para calcular a nova média: ");
            scanf("%lf %lf %lf", &aluno.nota[0], &aluno.nota[1], &aluno.nota[2]);
            getchar(); // Limpa o buffer de entrada

            // Calcula a nova média ponderada
            medianova = (25 * aluno.nota[0] + 35 * aluno.nota[1] + 40 * aluno.nota[2]) / 100.0;

            if (aluno.media != medianova) {
                mudouquantos++;
            }

            aluno.media = medianova;

            // Move o ponteiro do arquivo para a posição correta para escrever as novas notas e média
            posicao = ftell(arq);
            fseek(arq, posicao - sizeof(double) - 3 * sizeof(double), SEEK_SET);
            fwrite(aluno.nota, sizeof(double), 3, arq);
            fwrite(&aluno.media, sizeof(double), 1, arq);
            fseek(arq, posicao, SEEK_SET);

            total++;
        } else {
            fprintf(stderr, "Erro ao ler as notas ou a média.\n");
            break;
        }
    }

    int porcentomudou = (total == 0) ? 0 : (mudouquantos * 100) / total;
    printf("\n%d porcento dos alunos tiveram a média alterada!\n", porcentomudou);

    // Rewind do arquivo para a leitura completa dos dados atualizados
    rewind(arq);

    printf("\nDados atualizados dos alunos:\n");
    while (fread(aluno.nome, sizeof(char), MAX_NOME, arq) > 0) {
        if (fread(aluno.nota, sizeof(double), 3, arq) == 3 && fread(&aluno.media, sizeof(double), 1, arq) == 1) {
            printf("\nNome: %s\n", aluno.nome);
            printf("Notas: %.2lf %.2lf %.2lf\n", aluno.nota[0], aluno.nota[1], aluno.nota[2]);
            printf("Media atualizada: %lf\n", aluno.media);
        }
    }

    fclose(arq);
    return 0;
}
