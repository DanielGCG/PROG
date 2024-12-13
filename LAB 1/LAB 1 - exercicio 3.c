/*Esse programa se refere ao exercício 3 do LAB 1*/

#include <stdio.h>
#include <string.h>
#define VALOR 3

void max (int *v, int *np){
    for (int i = 0; i < VALOR; i++){ // se v[i] < vi[i+1], *np recebe o maior valor
        if (*v+i < *(v+(i+1))){
            *np = *(v+(i+1));
        }
        if (*v+i > *(v+(i+1))){
            *np = *(v+i);
        }
    }
}

int main (){
    
    int n, v[VALOR];
    int *np = &n; // ponteiro np aponta para n
    
    printf ("\nDigite o valor de n:");
    scanf ("%d", &n); // n recebe valor

    for (int i = 0; i < VALOR; i++){ // escaneia valores do vetor
        printf ("\n v[%i] = ", i);
        scanf ("%d", &v[i]);
    }
    
    max (v, np); //Função Max
    
    printf ("\nO novo valor de n eh: %d", n);

    return 0;
}