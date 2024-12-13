#include <stdio.h>
#include <stdlib.h>


int main ()
{
  int L, C, M, N, maior = 0;
    
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
            printf ("%d ", *(matrizLC + (i*C+j)));
        }
    }


    // LOTES

    for (int lin = 0, col = 0, lote = 0 ; lote < (L * C)/(M * N) ; lote++){
    
        // Como está a soma total do lote (resetada para cada lote)
        int somaatual = 0;

        // Resolução de acordo com o tipo de lote
        for (int elm = M * N ; elm != 0; elm-- ){
            somaatual += *(matrizLC + (lin*C+col));


            // elm do lote diferente de 1
            if (elm != 1){

                // Quando bate no limite da coluna do lote
                if ((col + 1) % N == 0 ){
                    col = (col - (N - 1));
                    lin ++; 
                    continue;
                }
            }

                // Se ainda não bateu no limete da coluna do lote
                if ((col + 1) % N != 0 ){
                    col++;
                }


            // Teste de maior ou menor
            if (somaatual > maior){
                maior = somaatual;
            }
        }

        // Arrumação para a proxima iteração

            // Quando a coluna bate no limite da matriz
            if (col + 1 == C){
                col = 0;        // reseta-se a coluna
                lin ++;         // descemos para linha de baixo
                continue;
            }

            // Quando a coluna ainda não bateu no limite da matriz
            if (col + 1 != C){
                col ++;         // pula-se para a próxima col
                lin = lin - (M -1); 
            }


    }

    printf ("\nO maior lote eh: %d\n", maior);

  return 0;
}