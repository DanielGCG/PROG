#include <stdio.h>
#include <stdlib.h>

void bolha(int v[], int tam)
{
    int aux, quantasvezesrodou = 0;
    for (int ult = tam - 1; ult > 0; ult--){
        for (int i = 0; i < ult; i++){
            if (v[i] > v[i + 1]){
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
            }
            quantasvezesrodou = quantasvezesrodou + 1;
        }
    }
    printf("\nQuantas vezes rodou: %d\n", quantasvezesrodou);
}

void bolhanovo(int v[], int tam)
{
    int quantasvezesrodou = 0;
    for (int ult = tam - 1; ult > 0; ult--){
        int cont = 0;
        for (int i = 0; i < ult; i++){
            if (v[i] > v[i + 1]){
                int aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                cont = cont + 1;
            }
            quantasvezesrodou = quantasvezesrodou + 1;
        }
        if (cont == 0){
            printf("\nQuantas vezes rodou: %d\n", quantasvezesrodou);
            return;
        }
        cont = 0;
    }
    printf("\nQuantas vezes rodou: %d\n", quantasvezesrodou);
}



int main()
{
    int vetor1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int vetor2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tam = 10;

    printf ("\n\n-=-=-=-=-=-=-=-=-=-=- VETORES -=-=-=-=-=-=-=-=-=-=-\n\n");

    printf("\nVetor original: ");
    for (int cont = 0; cont < tam; cont++)
        printf("%d ", vetor1[cont]);

    printf("\n\n------Novo metodo------");

    bolhanovo(vetor1, tam);
    for (int cont = 0; cont < tam; cont++)
        printf("%d ", vetor1[cont]);

    printf("\n\n------Metodo antigo------");

    bolha(vetor2, tam);
    for (int cont = 0; cont < tam; cont++)
        printf("%d ", vetor2[cont]);

    // Comentário sobre complexidade
    printf ("\n\n------Comentario------");
    printf ("\nCom essa melhoria, o algoritimo no seu melhor caso se tornou: 'O(n)' para as comparações entre os vetores, ele dessa forma, sera sempre mais eficiente ou igual ao metodo anterior!\n\n\n\n");

    return 0;
}