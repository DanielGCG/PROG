/*Esse programa se refere ao exercício 3 do LAB 1*/

#include <stdio.h>
#include <string.h>


void aumento (float *Patual, float percentual){
    //transformação do percentual para uso na formula
    percentual = percentual / 100;

    //implementação do aumento
    *Patual = *Patual + (*Patual * percentual);

}

int main (){
    float atual, percentual;
    float *Patual = &atual;

    //Recebimento dos valores de salario ATUAL e PERCENTUAL.
    printf ("\nEscreva o valor do salario:");
    scanf ("%f", &atual);
    printf ("\nEscreva o percentual (XXX,XX):");
    scanf ("%f", &percentual);

    //Uso da função de aumento
    aumento (Patual, percentual);

    printf ("\nNovo salario atual eh: %f", atual);

    return 0;
}