#include <stdio.h>
#include <stdlib.h>


void bolha_recursiva(int v[], int tam)
{
    if (tam <= 0)
    {
        return;
    }
    for (int i = 0, ult = tam - 1; i < ult; i++)
    {
        if (v[i] > v[i + 1])
        {
            int aux = v[i];
            v[i] = v[i + 1];
            v[i + 1] = aux;
        }
    }
    bolha_recursiva(v, tam - 1);
}


void insercao_recursiva(int v[], int tam)
{
    if (tam <= 1)
    {
        return;
    }

    insercao_recursiva(v, tam - 1);

    int aux = v[tam - 1];
    int j = tam - 2;

    while (j >= 0 && v[j] > aux)
    {
        v[j + 1] = v[j];
        j--;
    }
    v[j + 1] = aux;
}


void selecao_recursiva (int v[], int tam) {
    if (tam <= 1) {
        return;
    }
    
    int aux, posMenor = 0;

    // Encontrar a posição do menor elemento no subarray v[0...tam-1]
    for (int p = 1; p < tam; p++) {
        if (v[p] < v[posMenor]) {
            posMenor = p;
        }
    }

    // Trocar os elementos
    if (posMenor != 0) {
        aux = v[0];
        v[0] = v[posMenor];
        v[posMenor] = aux;
    }

    // Exclui o primeiro elemento ordenado
    selecao_recursiva (v + 1, tam - 1);
}


int main() {
    int vetor1[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int vetor2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int vetor3[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int tam = 10;

    printf ("\nVetor original: ");

    for (int cont = 0; cont < tam; cont++)
            printf("%d ", vetor1[cont]);
    

    bolha_recursiva(vetor1, tam);

    printf ("\n\n\nVetor depois da bolha_recursiva: ");

    for (int cont = 0; cont < tam; cont++)
        printf("%d ", vetor1[cont]);



    insercao_recursiva(vetor2, tam);

    printf ("\n\nVetor depois da insercao_recursiva: ");

    for (int cont = 0; cont < tam; cont++)
        printf("%d ", vetor2[cont]);



    selecao_recursiva (vetor3, tam);

    printf ("\n\nVetor depois da selecao_recursiva: ");

    for (int cont = 0; cont < tam; cont++)
        printf("%d ", vetor3[cont]);

    return 0;
}