#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _func
{
    char nome[40];
    int ano_nasc;
    float renda;
} Tfunc;


void *inicializa(Tfunc * cadastro, int funcionarios){
    
    // Alocação dinâmica dos cadastros
    cadastro = (Tfunc *)malloc(funcionarios * sizeof (Tfunc)); 

    // Coleta dos dados pelo teclado
    for ( int cont = 0 ; cont < funcionarios ; cont++ ){
        printf ("\nNome: "); getchar();
        fgets (cadastro[cont].nome, 39, stdin);
        printf ("\nData de nascimento: ");
        scanf ("%d", &(cadastro[cont].ano_nasc));
        printf ("\nRenda: ");
        scanf ("%f", &(cadastro[cont].renda));

        printf ("\n-----------------------\n");
    }
    return cadastro;
} 

void *inclui_novos(Tfunc *cadastro, int funcionarios, int adicionais){
    cadastro = realloc (cadastro, ((funcionarios + adicionais) * sizeof(Tfunc)));

    // Coleta dos dados dos funcionarios novos
    for ( int cont = 0 ; cont < adicionais ; cont++ ){
        printf ("\nNome do funcionario extra: "); getchar();
        fgets (cadastro[funcionarios+cont].nome, 39, stdin);
        printf ("\nData de nascimento do funcionario extra: ");
        scanf ("%d", &(cadastro[funcionarios+cont].ano_nasc));
        printf ("\nRenda do funcionario extra: ");
        scanf ("%f", &(cadastro[funcionarios+cont].renda));

        printf ("\n-----------------------\n");
    }
    return cadastro;
}


void imprime(Tfunc *cadastro, int inicial, int total){

    // Imprime a lista completa dos funcionário (inciais + adicionais)
    for ( int cont = inicial ; cont < total ; cont ++ ){
        printf ("\nNome: %s", cadastro[cont].nome);
        printf ("\nData de nascimento: %d", cadastro[cont].ano_nasc);
        printf ("\nRenda: %f", cadastro[cont].renda);

        printf ("\n-----------------------\n");
    }
}


int main(void)
{
    Tfunc *cadastro;

    int funcionarios, adicionais;

    printf("Quantos funcionarios? ");
    scanf("%d", &funcionarios);


    cadastro = inicializa(cadastro, funcionarios);

    if (!cadastro)
        return -1;
    
    printf("Quantos funcionarios a mais deseja adicionar? ");
    scanf("%d", &adicionais);

    
    cadastro = inclui_novos(cadastro, funcionarios, adicionais);

    if (!cadastro)
        return -1;

    
    printf("Lista de funcionarios cadastrados\n");

    imprime(cadastro, 0, funcionarios + adicionais);

    free(cadastro);


    return 0;
}