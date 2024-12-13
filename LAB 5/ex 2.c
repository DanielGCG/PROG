#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){

    // Biblioteca de dados
    float P1, P2, T, media;
    int numalu;
    char nomearqabetura[50];
    char nomearqescrita[50];


    // Alocação dinamica do nome de aluno
    char *nomealu = malloc (50*sizeof(char));
    if (nomealu == NULL){
        return -1;
    }

    // Recebe o nome do arquivo a ser aberto
    printf ("Escreva o nome do arquivo a ser aberto: ");
    scanf ("%s", nomearqabetura);

    // Recebe o nome do arquivo a ser escrito
    printf ("Escreva o nome do arquivo a ser escrito: ");
    scanf ("%s", nomearqescrita);


    // Abertura do arquivo de leitura
    FILE *arqleitura = fopen (nomearqabetura, "r");

    // Abertura do arquivo de escrita
    FILE *arqescrita = fopen (nomearqescrita, "w");

    // Leitura de quantos alunos tem
    fscanf (arqleitura, "%d", &numalu);
    printf ("Quantidade de alunos lida foi: %d\n", numalu);

    for ( int cont = 0 ; cont < numalu ; cont++){
        // Leitura do nome do aluno e notas
        fscanf (arqleitura, "%s", nomealu);
        printf ("\nLi um nome: %s", nomealu);
        fscanf (arqleitura, "%f %f %f", &P1, &P2, &T);

        media = (((P1 + P2) / 2) * 0.8)+(T * 0.2);

        // Escrita dos dados tratados
        fprintf (arqescrita, "%s", nomealu);
        fprintf (arqescrita, "%f", media);
    }
    
    fclose (arqescrita);
    fclose (arqleitura);
    free (nomealu);

    return 0;
}