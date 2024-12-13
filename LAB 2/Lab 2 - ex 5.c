#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int posicao(char *substr, char *str){
    for (int i = 0; i < 6; i++){
        if (substr[0] == str[i]){
            for (int j = 1; j < 3; j++){
                if (substr[j] == str[i+j]){
                    return i;
                }
            }
        }
    }
    return -1;
}

int main (){
    //Biblioteca de dados
    char *substr, *str;

    //Inserção do conteúdo dos strings
    substr = (char *) malloc (3*sizeof(char));
    strcpy (substr, "abc");

    str = (char *) malloc (6*sizeof(char));
    strcpy (str, "zzabcz");


    //Teste da função posição
    printf ("\nA posicao em que ao menos duas letras seguidas da substring aparecem pela primeira vez na string: %d\n", posicao (substr, str));

    return 0;
}