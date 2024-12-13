#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main (){

    // Biblioteca de dados
    int numalu;
    float P1, P2, T;
    char nomearq[50];


    // Alocação dinamica de nomealuno
    char *nomealu = malloc (50*sizeof(char));
    if (nomealu == NULL){
        printf ("Erro na alocacao dinamica de nomealu");
        return -1;
    }


    // Recebimento do nome do arquivo que será escrito
    printf ("Escreva o nome do arquivo desejado abrir: ");
    scanf ("%s", nomearq);

    // Abertura do arquivo para escrita
    FILE *arq = fopen(nomearq, "w");

    if (arq == NULL){
        printf ("Erro de abertura de arquivo");
        return -1;
    }

    // Recebimento da quantidade de alunos
    printf ("\nQuantos alunos deseja cadastrar: ");
    scanf ("%d", &numalu);

    fprintf (arq, "%d\n", numalu);

    // Recebimento dos dados e escrita
    for ( int cont = 0 ; cont < numalu ; cont++){
        // Recebe o nome do aluno
        printf ("\nEscreva o nome do aluno(%d): ", cont);
        getchar ();
        fgets (nomealu, 50, stdin);
        nomealu[(strlen (nomealu) - 1)] = ' ';

        // Recebe as notas do aluno
        printf ("\n Agora escreva os valores <P1> <P2> <T> do aluno(%d): ", cont);
        scanf ("%f %f %f", &P1, &P2, &T);

        // Escreve esses dados no arq
        fprintf (arq, "%s", nomealu);
        fprintf (arq, "%s", "- ");
        fprintf (arq, "%.2f %.2f %.2f \n", P1, P2, T);
    }   

    fclose (arq);

    return 0;
}