#include <stdio.h>
#include <stdlib.h>


int main ()
{
  int L, C, M, N;
    
    //Obtendo os valores 
    scanf ("%d %d %d %d", &L, &C, &M, &N);
    
    if (L < 1 || C < 1 || M < 1 || M > L || 1 > N || N > C){
        printf ("Erro de entrada");
        return -1;
    }
    
    
    //Alocando dinamanicamente a Matriz L*C
    int * matrizLC = (int *) malloc (L * C * sizeof(int));
    
    for (int i = 0; i < L ; i++){ 
        for (int j = 0; j < C ; j++){
            scanf ("%d", (matrizLC + (i*C+j)));
        }
    }

    for (int i = 0; i < L ; i++){ 
        for (int j = 0; j < C ; j++){
            printf ("%d", *(matrizLC + (i*C+j)));
        }
    }

    
    int maiorsoma = 0, somaatual = 0;
    
    
    for (int contador = 0, i = 0, j = 0 ; contador < ((L*C)/(M*N)) ; contador++) { //a quantidade de lotes a serem verificados
        printf ("\nLote: %d", contador);

        for (int contlin = i ; contlin < (M + i) ; contlin++){ // Linhas
        

            for (int contcol = j; contcol < (N + j) ; contcol++){ // Colunas
                somaatual = somaatual + *(matrizLC + (contlin*C+contcol));
                
                printf ("\n(Vetor [%d] [%d] = (%d))", contlin, contcol, *(matrizLC + (contlin*C+contcol)));
            }
        }

        printf ("\na soma atual esta em: %d", somaatual);

        
        if ((contador + 1) % C == 0){
                i = i + 1;
        }

        j = j + N;

        if (somaatual > maiorsoma){
            maiorsoma = somaatual;
        }
        somaatual = 0;

        printf ("\n--------------------------------------\n");
    }
    printf ("\nMaior soma: %d \n", maiorsoma);


  return 0;
}