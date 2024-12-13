#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main (){

    char nomearquivo[50], palavra[50];

    int quantidade = 0, tamanhopalavra = 0;

    FILE *arq;

    // Recebe o nome do arquivo
    printf ("\nEscreva o nome do arquivo que desaja buscar: ");
    scanf ("%s", nomearquivo);

    arq = fopen (nomearquivo, "r");

    // Recebe a palavra de interesse
    printf ("\nEscreva a palavra que desaja buscar: ");
    scanf ("%s", palavra);
    tamanhopalavra = strlen (palavra);



    while (!feof (arq)){

        if (tolower (fgetc (arq)) == tolower (palavra[0])){
            for ( int cont = 1 ; cont < tamanhopalavra ; cont++){
                if (tolower (fgetc (arq)) != tolower (palavra[cont])){
                    quantidade --;
                    break;
                }
            }
            quantidade++;
        }
    }

    printf ("\nExistem (%d) da palavra nesse texto!", quantidade);

    return 0;
}