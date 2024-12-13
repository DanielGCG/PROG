#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
typedef int bool;

typedef struct {
    char nome[100];
    int chegada;
    int quantprodutos;
} tCliente;

typedef struct aux
{
    tCliente cliente;
    struct aux *prox;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct
{
    PONT inicio;
    PONT fim;
} FILA;

void inicializarFila(FILA *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

int tamanho(FILA *f)
{
    PONT end = f->inicio;
    int tam = 0;
    while (end != NULL)
    {
        tam++;
        end = end->prox;
    }
    return tam;
}

void exibirFila(FILA *f)
{
    PONT end = f->inicio;
    printf("Fila: \" ");
    while (end != NULL)
    {
        printf("%s ", end->cliente.nome);
        end = end->prox;
    }
    printf("\"\n");
}

bool inserirNaFila(FILA *f, tCliente cliente)
{
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    if (novo == NULL) return false;
    novo->cliente = cliente;
    novo->prox = NULL;
    if (f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;
    f->fim = novo;
    return true;
}

bool excluirDaFila(FILA *f, tCliente *cliente)
{
    if (f->inicio == NULL)
        return false;
    *cliente = f->inicio->cliente;
    PONT apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);
    if (f->inicio == NULL)
        f->fim = NULL;
    return true;
}

void reinicializarFila(FILA *f)
{
    PONT end = f->inicio;
    while (end != NULL)
    {
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    f->inicio = NULL;
    f->fim = NULL;
}

int main()
{
    int k, c;
    scanf("%d", &k);
    scanf("%d", &c);

    tCliente cliente;
    FILA fila;
    inicializarFila(&fila);

    for (int i = 0; i < c; i++) {
        scanf("%s %d %d", cliente.nome, &cliente.chegada, &cliente.quantprodutos);
        inserirNaFila(&fila, cliente);
    }

    int tempoAtual = 0;

    while (tamanho(&fila) > 0) {
        if (excluirDaFila(&fila, &cliente)) {
            int tempoAtendimento = 10 + cliente.quantprodutos * k;

            if (tempoAtual < cliente.chegada) {
                tempoAtual = cliente.chegada;
            }

            int tempoEntrada = cliente.chegada;
            tempoAtual += tempoAtendimento;

            printf("%s %d %d\n", cliente.nome, tempoEntrada, tempoAtual);
        }
    }

    reinicializarFila(&fila);
    return 0;
}