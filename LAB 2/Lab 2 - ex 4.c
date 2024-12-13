#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
    int *i, j;
    float *notas;
    char *nome;
// (concluído) coloque na variC!vel *i o valor 10 de duas formas distintas ...
    
    i = (int *) malloc(1*sizeof(int));  //cria uma alocação de memória de tamanho um inteiro
    i[0] = 10;                          //i recebe 10
    printf ("\nLetra a1: %d", i[0]);    //testa


    *i = 0;     //reseta


    i = &j;     // Apontando *i para j
    *i = 10;    // *i recebe 10 que aponta para j
    printf ("\nLetra a1: %d", j);  //testa


// (concluído) carregue na variável "notas" 5 valores distintos de notas...
    int quantasnotas = 0;
    
    //Verificação de quantas notas o usuário quer
    printf ("\n\nQuantas notas deverao ser lidas?:\n");
    scanf ("%d", &quantasnotas);
    
    //Alocação dinamica para quantidade de notas desejadas
    notas = (float *) malloc(quantasnotas*sizeof(float));
    
    //Recebe os valores das notas e dispõe ao usuário
    for (int i = 0; i < quantasnotas; i++){
    printf ("\n"); //pula linha
    scanf ("%f", &*(notas+i));  //scaneia o valor para nota
    printf ("v[%d] = %.1f\n", i, *(notas+i)); //printa o ventor apontado por *notas
    }
    
    
// (concluído) carregue na variável "nome" o seu primeiro e ultimo nome usando somente letras minusculas...

    nome = (char *) malloc(200*sizeof(char));
    
    strcpy (nome, "daniel goulart");
    
    printf ("\nnome antes: %s", nome);
    

// (concluído) altere as letras
    nome[0] = 'D';
    nome[7] = 'G';
    
    printf ("\nnome depois: %s", nome);


    return 0;
}