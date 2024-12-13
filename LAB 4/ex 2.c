#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main () {
    
    // Biblioteca de dados
    char nomearqentrada [50];
    char nomearqsaida [50];
    char letra;

    // Recebimento nome arq entrada
    printf ("\n Escreva o nome do arquivo de entrada: ");
    scanf ("%s", nomearqentrada);

    // Recebimento nome arq saída
    printf ("\n Escreva o nome do arquivo de saida: ");
    scanf ("%s", nomearqsaida);

    FILE *arqentrada = fopen (nomearqentrada, "r");

    if (arqentrada == NULL){
        return -1;
    }

    FILE *arqsaida = fopen (nomearqsaida, "w+");

    if (arqsaida == NULL){
        return -1;
    }


    // Leitura das linhas
    while (!feof(arqentrada)){
        letra = fgetc (arqentrada);
        
        if (letra != ' ' && letra != '\n' && letra >= 97 && letra != EOF)
            fputc ((letra-32), arqsaida);
        
        else fputc (letra, arqsaida);
    }

    return 0;
}