#include <stdlib.h>
#include <stdio.h>

int buscaBin(int arr[], int tam, int el)
{
    int fim = tam - 1;
    int ini = 0;
    int contador = 0;
    
    while (ini <= fim)
    {
        contador++;
        int meio = (fim + ini) / 2;
        if (arr[meio] < el){
            printf ("\n%da. iteracao: %d", contador, (meio - ini + 1));
            ini = meio + 1;
        }
        else if (arr[meio] > el){
            printf ("\n%da. iteracao: %d", contador, (fim - meio + 1));
            fim = meio - 1;
        }
        else {
            printf ("\n%da. iteracao: %d", contador, (fim - meio));
            return meio;
        }
    }
    return -1;
}

int main () {

    int quantelm, *vetor, procurado;

    printf ("\nQuantos elementos do vetor: ");
    scanf ("%d", &quantelm);

    vetor = malloc (quantelm * sizeof(int));

    printf ("\nEscreva o seu vetor ordenado: ");
    for (int cont = 0; cont < quantelm; cont++){
        scanf ("%d", &vetor[cont]);
    }

    printf ("\nDigite o elemento procurado: ");
    scanf ("%d", &procurado);

    int resultado = buscaBin(vetor, quantelm, procurado);

    if (resultado != -1)
        printf ("\nElemento na posicao: %d\n", resultado);
    else
        printf ("\nElemento nao encontrado\n");

    free(vetor);
    return 0;
}