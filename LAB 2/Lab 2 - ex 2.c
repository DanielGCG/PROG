#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct thora{
    int hora;
    int minuto;
} thora;


void relogio (int valor, thora *ponteiro){

    int horas = valor / 60;
    int minutos = valor % 60;

    (*ponteiro).hora = horas;
    (*ponteiro).minuto = minutos;
}

int main (){

    int valor;
    thora horario;
    thora *ponteiro;
    ponteiro = &horario;
    

    printf ("\nEscreva quantos minutos:");
    scanf ("%d", &valor);

    relogio (valor, ponteiro);
    printf ("\n%d hora(s) e %d minuto(s)", horario.hora, horario.minuto);

    return 0;
}