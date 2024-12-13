#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 80

int main (){
    
    // Biblioteca de dados
    char entradanomedoarq[MAX];
    char saidanomedoarq[MAX];
    char linha[MAX];
    FILE *entradaarq;
    FILE *saidaarq;
    int cont = 0;


    // Recebe o nome do arquivo do usuário
    printf ("\nDigite o nome do arquivo de entrada: ");
    scanf ("%s", entradanomedoarq);

    // Recebe o nome do arquivo do usuário
    printf ("\nDigite o nome do arquivo de saida: ");
    scanf ("%s", saidanomedoarq);

    // Inicialização do arquivo de entrada
    entradaarq = fopen (entradanomedoarq, "r");

    if (entradaarq == NULL){
        printf ("\nErro na leitura do arquivo.");
        return -1;
    }

    // Inicialização do arquivo de saída
    saidaarq = fopen (saidanomedoarq, "w+");

        // Recebe a linha do arq de entrada e se for NULL para
        while (fgets (linha, MAX, entradaarq) != NULL){
        

        // Escreve a linha ao contrario no arq de saída
        for (int cont = strlen (linha) ; cont > 0 ; cont --){
            if (linha[cont-1] != '\n'){
                fputc (linha[cont-1], saidaarq);
            }
        }

        // Pula a linha
        fputc ('\n', saidaarq);
        cont ++;
    } 

    fclose (entradaarq);
    fclose (saidaarq);
    return 0;
}