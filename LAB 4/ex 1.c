#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main (){

    FILE *arq;
    int a = 0, e = 0, i = 0, o = 0, u =0;
    char letra;
    char nomedoarq[80];

    // Recebe o nome do arquivo do usuário
    printf ("\nDigite o nome do arquivo: ");
    scanf ("%s", nomedoarq);

    // Abre o arquivo e inicializa o ponteiro de arquivo
    arq = fopen ("textoex1.txt", "r");

    // Verifica se o arquivo foi inicializado com sucesso
    if (arq == NULL){
        printf("\nErro ao abrir o arquivo.");
        return -1;
    }


    // Roda por todos os caracteres do arquivo
    do {
        letra = fgetc(arq);
        if (letra == 'a' || letra == 'A')a++;

        if (letra == 'e' || letra == 'E')e++;

        if (letra == 'i' || letra == 'I')i++;

        if (letra == 'o' || letra == 'O')o++;

        if (letra == 'u' || letra == 'U')u++;
        


    } while (letra != EOF);


    printf ("\na %d\n", a);
    printf ("e %d\n", e);
    printf ("i %d\n", i);
    printf ("o %d\n", o);
    printf ("u %d\n", u);

    fclose (arq);
    return 0;
}