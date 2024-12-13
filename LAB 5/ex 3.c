#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tempo{
    int hora, min, seg;
} tempo;

int main (){

    // Biblioteca de dados
    tempo atleta;
    int C = 0, A = 0, menor = 0, atual = 0, *vetor, somaatual = 0;
    char nomearq[100];

    // Recebimento de nome de arquivo
    printf ("Escreva o nome do arquivo:");
    scanf ("%s", nomearq);

    // Abertura arquivo
    FILE *arq = fopen (nomearq, "r");
    
    if (arq == NULL){
        printf ("erro de alocacao de memoria!");
        return -1;
    }

    // Recebimento de A e C
    fscanf (arq,"%d %d", &A, &C);

    printf ("%d atletas e %d tempo(s) cada:", A, C);
    // Alocação dinamica de vetor
    vetor = malloc (A * sizeof(int));


    for ( int numatleta = 0; numatleta < A ; numatleta++ ){

        for ( int cont = 0; cont < C ; cont++ ){

            fgetc (arq);

            fscanf (arq, "%d %d %d", &atleta.hora, &atleta.min, &atleta.seg);

            atual = (atleta.hora*3600 + atleta.min*60 + atleta.seg);

            somaatual += atual;
        }
        vetor[numatleta] = somaatual;
        printf ("\nVetor[%d] = %d", numatleta, vetor[numatleta]);
        somaatual = 0;
    }

    atual = vetor[0];

    for ( int numatleta = 0 ; numatleta < A-1 ; numatleta++ ){
        if (vetor [(numatleta+1)] < atual){
            atual = vetor[(numatleta+1)];
            menor = (numatleta+1);
        }
        printf ("\nEntre (vetor[%d] = %d e vetor[%d] = %d) o menor eh %d", numatleta, vetor[numatleta], (numatleta+1), vetor[(numatleta+1)], menor);
    }
    printf ("\n-----------RESULTADO-----------\n");
    printf ("\nO atleta de menor tempo eh: %d", menor+1);

    free (vetor);
    fclose (arq);
    return 0;
}