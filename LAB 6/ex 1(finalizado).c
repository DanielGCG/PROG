#include <stdio.h>
#include <stdlib.h>

int grava(FILE *pFile, int N) // Funciona
{
    int verificador = 0;
    for ( int cont = N ; cont != 0; cont--)
    {
        verificador += fwrite (&cont, sizeof(int), 1, pFile);
    }

    return verificador;
}


int *recupera (FILE *pFile)
{   
    // Criamos uma variável N que lerá do arquivo o maior número da lista, que sempre é o primeiro
    int N;
    rewind (pFile);
    fread (&N, sizeof(int), 1, pFile);

    // Com o tamanho N, voltamos ao inicio do arquivo para
    // lermos os dados e associar a um vetor dinamicamente alocado
    rewind (pFile);
    int *ponteiro = malloc (N * sizeof (int));
    fread (ponteiro, sizeof (int), N, pFile);
    
    return ponteiro;
}


void exibe_vetor(int *vetor, int N)
{
    // Passamos por todo o vetor
    printf ("\n");
    
    for ( int cont = 0 ; cont < N ; cont++)
    {
        printf ("%d ", *(vetor+cont));
    }
}


int modifica (FILE *pFile, int M)
{   
    // Criamos uma variável N que lerá do arquivo o maior número da lista, que sempre é o primeiro
    int N;
    rewind (pFile);
    fread (&N, sizeof(int), 1, pFile);
    rewind (pFile);

    // Se M não respeitar as condições modifica retorna 1
    if (M > N || M < 0)
    {
        return -1;
    }

    // Vamos apontar o leitor do arquivo para a posição que queremos com base em M
    fseek (pFile, -(M * sizeof (int)) , SEEK_END);

    // Leremos o arquivo e escreveremos em um vetor para futura modificação
    int *valortemp =  malloc (M * sizeof (int));
    
    fread (valortemp, sizeof(int), M, pFile);

        for ( int cont = 0 ; cont < M ; cont++ )
        {
            // Condição de alteração
            if (*(valortemp+cont) % 2 == 0)
            {
                *(valortemp+cont) = *(valortemp+cont) * 2;
            }
        }

    // Podemos apontar de volta o arquivo e escrever o vetor já processado
    fseek (pFile, ((-M) * sizeof(int)), SEEK_END);
    fwrite (valortemp, sizeof(int), M, pFile);

    return M;
}


void recupera_exibe (FILE *pFile)
{   
    // Voltamos a primeira posição do arquivo
    rewind (pFile);

    // Precisamos novamente do tamanho N do arquivo, mas curiosamente não nos foi fornecido
    // porquê dificultar a vida? Não sei, mas vamos dar um jeito então!

    // Faremos um contador para contarmos N no arquivo!
    int valor;
    int N = 0;
    while (valor != 1) // Sabemos que o ultimo valor da sequência é "1" e esse valor não será duplicado!
    {
        fread(&valor, sizeof(int), 1, pFile);
        N++;
    }

    // Agora, após essa volta torturante e desnecessária, podemos então ler a sequência finalizada do arquivo!
    rewind (pFile);
    int val = 0;
    for ( int cont = 0 ; cont != N ; cont ++)
    {
        fread (&val, sizeof(int), 1, pFile);
        printf ("%d ", val);
    }
}


int main()
{
    FILE *pFile;
    int N, M, mod, *vetor;
    char nome_arquivo[100];

    
    printf("Informe o nome do arquivo a ser criado: ");
    gets(nome_arquivo);

    
    printf("Informe um numero positivo: ");
    scanf("%d", &N);

    
    pFile = fopen(nome_arquivo, "wb+");

    
    if (!pFile)
    {
        printf("Erro na criacao do arquivo...");
        return -1;
    }

    
    if (grava(pFile, N) != N)
    {
        printf("Erro na gravacao do arquivo...");
        return -1;
    }
 
    vetor = recupera(pFile);

    
    if (vetor == NULL)
    {
        printf("Erro na recuperacao de dados do arquivo...");
        return -1;
    }


    exibe_vetor(vetor, N);

    
    printf("\nInforme um numero positivo M correspondente a quantidade de valores a partir do final do arquivo que deseja alterar: ");
    scanf("%d", &M);

    
    mod = modifica(pFile, M);
    if (mod == -1)
    {
        printf("Valor de M fora do intervalo permitido...");
        return -1;
    }
    if (mod != M)
    {
        printf("Erro de leitura e/ou gravacao no arquivo...");
        return -1;
    }
    
    
    recupera_exibe(pFile);
    
    
    fclose(pFile);

    return 0;
}
