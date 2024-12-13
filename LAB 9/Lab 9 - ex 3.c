#include <stdlib.h>
#include <stdio.h>

void buscaMenorMaiorBin(int arr[], int tam, int el, int *menor, int *maior) {
    int fim = tam - 1;
    int ini = 0;
    int contador = 0;
    *menor = 0;
    *maior = 0;

    while (ini <= fim) {
        contador++;
        int meio = (fim + ini) / 2;
        if (arr[meio] < el) {
            ini = meio + 1;
            *menor = meio + 1; 
        } else if (arr[meio] > el) {
            fim = meio - 1;
            *maior = tam - meio; 
        } else {
            *menor = meio; 
            *maior = tam - meio - 1; 
            return;
        }
    }

    *maior = tam - ini;
}

int main() {
    int quantelm, *vetor, el, maior, menor;

    printf("\nQuantos elementos do vetor: ");
    scanf("%d", &quantelm);

    vetor = malloc(quantelm * sizeof(int));

    printf("\nEscreva o seu vetor ordenado: ");
    for (int cont = 0; cont < quantelm; cont++) {
        scanf("%d", &vetor[cont]);
    }

    printf("\nDigite o elemento a ser comparado: ");
    scanf("%d", &el);

    buscaMenorMaiorBin(vetor, quantelm, el, &menor, &maior);

    printf("\nMenor: %d, Maior: %d\n", menor, maior);

    free(vetor);
    return 0;
}
