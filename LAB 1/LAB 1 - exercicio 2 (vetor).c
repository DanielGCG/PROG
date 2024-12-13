/*Esse programa se refere ao exercício 2 do LAB 1*/

#include <stdio.h>
#include <string.h>


int vetorcontarvogais (char palavra[]){
    int quantidadevogais = 0;
    for (int i = 0; palavra[i] != NULL ; i++){
        if (palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u'){
            quantidadevogais++;
        }
    }
    printf ("%d", quantidadevogais);
    return quantidadevogais;
}


int main (){
    //Biblioteca de variáveis:
    char palavra[50]; //Vetor de palavra de até 100 cacteres.

    //Lê a palavra
    printf ("\nEscreva a palavra que voce quer contar as vogais:");
    scanf("%s", palavra);

    vetorcontarvogais (palavra);

    return 0;
}