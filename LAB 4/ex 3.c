#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main (){

    // Biblioteca de dados

    char nomearqleitura[50], linha [80];
    char *trecho = malloc (80 * sizeof (char));
    int contlinha = 0;

    // Recebimento do nome do arq
    printf ("Escreva o nome do arquivo de interesse: ");
    scanf ("%s", nomearqleitura);

    // Abertura do arq de leitura
    FILE *arq = fopen (nomearqleitura, "r");

    if (arq == NULL){
        return -1;
    }

    // Recebimento da substring que desejamos encontrar
    getchar ();
    printf ("\nEscreva que palavra deseja buscar: ");
    gets (trecho);

    while (!feof(arq)){

        // Leitura string de texto
        fgets (linha, 80, arq);

        if (strstr (linha, trecho) != NULL){
            printf ("\n%d  %s", contlinha+1, linha);
        }

        contlinha ++;

    }

    

    return 0;
}