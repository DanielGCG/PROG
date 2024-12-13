#include <stdio.h>
#include <stdlib.h>

int grava(FILE *pFile, int N) // Funciona
{
    int verificador = 0;
    for (int cont = N; cont != 0; cont--)
    {
        verificador += fwrite(&cont, sizeof(int), 1, pFile);
    }

    return verificador;
}

int *recupera(FILE *pFile)
{
    // Criamos uma variável N que lerá do arquivo o maior número da lista, que sempre é o primeiro
    int N;
    rewind(pFile);
    fread(&N, sizeof(int), 1, pFile);

    // Com o tamanho N, voltamos ao inicio do arquivo para
    // lermos os dados e associar a um vetor dinamicamente alocado
    rewind(pFile);
    int *ponteiro = malloc(N * sizeof(int));
    fread(ponteiro, sizeof(int), N, pFile);

    return ponteiro;
}

void exibe_vetor(int *vetor, int N)
{
    // Passamos por todo o vetor
    printf("\n");

    for (int cont = 0; cont < N; cont++)
    {
        printf("%d ", *(vetor + cont));
    }
}

int modifica(FILE *pFile, int M)
{
    // Criamos uma variável N que lerá do arquivo o maior número da lista, que sempre é o primeiro
    int N;
    rewind(pFile);
    fread(&N, sizeof(int), 1, pFile);
    rewind(pFile);

    // Se M não respeitar as condições modifica retorna 1
    if (M > N || M == 0)
    {
        return -1;
    }

    // Vamos apontar o leitor do arquivo para a posição que queremos com base em M
    fseek(pFile, -(M * sizeof(int)), SEEK_END);
    printf("\nEstou na posicao %ld", ftell(pFile));

    // Lê o arquivo
    int valortemp;
    printf("\nO modifica quer escrever os valores: ");
    for (int cont = 0; cont < M; cont++)
    {
        fread(&valortemp, sizeof(int), 1, pFile);

        // Escreve o arquivo alterado
        if (valortemp % 2 == 0)
        {
            valortemp = valortemp * 2;
        }
        printf(" (%d) ", valortemp);

        fwrite(&valortemp, sizeof(int), 1, pFile);
        fseek(pFile, -sizeof(int), SEEK_CUR);
    }

    return M;
}

void recupera_exibe(FILE *pFile)
{
    // Voltamos a primeira posição do arquivo
    rewind(pFile);

    int val = 0;
    for (int cont = 0; cont != 20; cont++)
    {
        fread(&val, sizeof(int), 1, pFile);
        printf("%d ", val);
    }
}

int main()
{
    FILE *pFile;
    int N, M, mod, *vetor;
    char nome_arquivo[100];

    // Recebe o nome do arquivo
    printf("Informe o nome do arquivo a ser criado: ");
    gets(nome_arquivo);

    // Recebe o numero positivo
    printf("Informe um numero positivo: ");
    scanf("%d", &N);

    // Abre o arquivo
    pFile = fopen(nome_arquivo, "wb+");

    // Alerta: Erro na criação do arquivo
    if (!pFile)
    {
        printf("Erro na criacao do arquivo...");
        return -1;
    }

    // Alerta: Erro na gravação
    if (grava(pFile, N) != N)
    {
        printf("Erro na gravacao do arquivo...");
        return -1;
    }

    // Vetor recebe end memória de "pFile"
    vetor = recupera(pFile);

    // Alerta: Erro de recuperação, end de memória inválido
    if (vetor == NULL)
    {
        printf("Erro na recuperacao de dados do arquivo...");
        return -1;
    }

    // Exibe os N valores de vetor
    exibe_vetor(vetor, N);

    // Recebe M
    printf("\nInforme um numero positivo M correspondente a quantidade de valores a partir do final do arquivo que deseja alterar: ");
    scanf("%d", &M);

    // Modifica os M ultimos pares pelo dobro
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

    // Exibe o recupera de pFile
    recupera_exibe(pFile);

    // Fecha o pFile
    fclose(pFile);

    return 0;
}