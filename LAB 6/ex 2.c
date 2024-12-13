#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    double nota[3];
    double media;
} Taluno;

int main() {
    FILE *arq;
    Taluno aluno;

    arq = fopen("alunos.dat", "wb");

    if (arq == NULL) {
        printf("\nErro de criação do arquivo!");
        return 1;
    }

    // Loop para inserção de múltiplos alunos
    while (1) {
        printf("\nEscreva o nome do aluno que deseja inserir (ou '<enter>' para terminar): ");
        fgets(aluno.nome, sizeof(aluno.nome), stdin);
        
        // Verifica se o usuário apenas pressionou 'enter' para finalizar
        if (aluno.nome[0] == '\n') {
            break;
        }

        // Remove o '\n' do final da string lida
        int len = strlen(aluno.nome);
        if (len > 0 && aluno.nome[len - 1] == '\n') {
            aluno.nome[len - 1] = '\0';
        }

        printf("Escreva as notas (P1 P2 P3): ");
        scanf("%lf %lf %lf", &aluno.nota[0], &aluno.nota[1], &aluno.nota[2]);
        getchar(); // Limpa o buffer de entrada

        // Calcula a média das notas
        aluno.media = (aluno.nota[0] + aluno.nota[1] + aluno.nota[2]) / 3.0;

        // Escreve os dados do aluno no arquivo
        fwrite(aluno.nome, sizeof(char), sizeof(aluno.nome), arq);
        fwrite(&aluno.media, sizeof(double), 1, arq);
    }

    fclose(arq);
    return 0;
}
