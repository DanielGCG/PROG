#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;
typedef struct
{
    TIPOCHAVE chave;
    // outros campos...
} REGISTRO;
typedef struct aux
{
    REGISTRO reg;
    struct aux *prox;
} ELEMENTO;
typedef ELEMENTO *PONT;
typedef struct
{
    PONT inicio;
} LISTA;
void inicializarLista(LISTA *l)
{
    l->inicio = NULL;
}
int tamanho(LISTA *l)
{
    PONT end = l->inicio;
    int tam = 0;
    while (end != NULL)
    {
        tam++;
        end = end->prox;
    }
    return tam;
}

void exibirLista(LISTA *l)
{
    PONT end = l->inicio;
    printf("Lista: \" ");
    while (end != NULL)
    {
        printf("%i ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}
bool insere(LISTA *l, REGISTRO reg, int pos)
{
    if (pos < 0 || pos > tamanho(l))
        return false;
    ELEMENTO *novo = (ELEMENTO *)malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    int i;
    ELEMENTO *p;
    if (pos == 0)
    {
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    else
    {
        p = l->inicio;
        for (i = 0; i < pos - 1; i++)
            p = p->prox;
        novo->prox = p->prox;
        p->prox = novo;
    }
    return true;
}
bool exclui(LISTA *l, int pos)
{
    if (pos < 0 || pos > tamanho(l) - 1)
        return false;
    int i;
    ELEMENTO *p;
    ELEMENTO *apagar;
    if (pos == 0)
    {
        apagar = l->inicio;
        l->inicio = apagar->prox;
    }
    else
    {
        p = l->inicio;
        for (i = 0; i < pos - 1; i++)
            p = p->prox;
        apagar = p->prox;
        p->prox = apagar->prox;
    }
    free(apagar);
    return true;
}
void reinicializarFila(LISTA *l)
{
    PONT end = l->inicio;
    while (end != NULL)
    {
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    l->inicio = NULL;
}

void concatenaListas(LISTA *l1, LISTA *l2)
{
    PONT end = l1->inicio;
    if (l1->inicio == NULL)
    {
        l1->inicio = l2->inicio;
    }
    else
    {
        while (end->prox != NULL)
        {
            end = end->prox;
        }
        end->prox = l2->inicio;
    }
    l2->inicio = NULL; // Para limpar a lista 2
}

bool iguaisListas(LISTA *l1, LISTA *l2)
{
    PONT end1 = l1->inicio;
    PONT end2 = l2->inicio;

    if (l1->inicio == NULL && l2->inicio == NULL)
    { // Se ambas estão vazias, logo são iguais
        return true;
    }

    if (tamanho(l1) != tamanho(l2))
    { // Se o tamanho for diferente, já são desiguais
        return false;
    }

    while (end1 != NULL && end2 != NULL)
    {
        if (end1->reg.chave != end2->reg.chave)
        {
            return false;
        }
        end1 = end1->prox;
        end2 = end2->prox;
    }
    return true;
}

bool modificaElm(LISTA *l, REGISTRO reg, int pos)
{
    if (pos < 0 || pos >= tamanho(l))
    { // A posição é válida?
        return false;
    }

    PONT end = l->inicio;

    for (int cont = 0; cont < pos; cont++)
    { // Percorremos até a posição "pos"
        end = end->prox;
    }

    end->reg = reg;

    return true;
}

int main() {
    LISTA f1, f2;
    inicializarLista(&f1);
    inicializarLista(&f2);

    int choice, pos;
    TIPOCHAVE chave;
    REGISTRO reg;

    char lixo[100]; // para o caso de opção inválida do menu

    printf ("-=-=-=-=-=-=- PROGRAMA DE LISTA LIGADA -=-=-=-=-=-=-");
    /*Aproveitei pra aprender a fazer um menu, espero que não tenha nenhum bug*/
    while (1) {

        printf ("\n---------------------------------------------------\n");
        printf ("Atual situacao da l1:\n");
        exibirLista(&f1);

        printf ("Atual situacao da l2:\n");
        exibirLista(&f2);

        printf("\nMenu:\n");
        printf("1. Inserir elemento em l1\n");
        printf("2. Inserir elemento em l2\n");
        printf("3. Concatenar l2 em l1\n");
        printf("4. Verificar se l1 e l2 sao iguais\n");
        printf("5. Modificar elemento em l1\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite a chave para inserir em l1: ");
                scanf("%d", &chave);
                printf("Digite a posicao para inserir: ");
                scanf("%d", &pos);
                reg.chave = chave;
                if (insere(&f1, reg, pos)) {
                    printf("Elemento inserido com sucesso.\n");
                } else {
                    printf("Falha ao inserir o elemento.\n");
                }
                break;
            case 2:
                printf("Digite a chave para inserir em l2: ");
                scanf("%d", &chave);
                printf("Digite a posicao para inserir: ");
                scanf("%d", &pos);
                reg.chave = chave;
                if (insere(&f2, reg, pos)) {
                    printf("\nElemento inserido com sucesso.\n");
                } else {
                    printf("\nFalha ao inserir o elemento.\n");
                }
                break;
            case 3:
                concatenaListas(&f1, &f2);
                printf("\nListas concatenadas. Nova lista l1:\n");
                exibirLista(&f1);
                break;
            case 4:
                if (iguaisListas(&f1, &f2)) {
                    printf("\nAs listas l1 e l2 sao iguais.\n");
                } else {
                    printf("\nAs listas l1 e l2 sao diferentes.\n");
                }
                break;
            case 5:
                printf("Digite a nova chave: ");
                scanf("%d", &chave);
                printf("Digite a posicao a ser modificada em l1: ");
                scanf("%d", &pos);
                reg.chave = chave;
                if (modificaElm(&f1, reg, pos)) {
                    printf("\nElemento modificado com sucesso.\n");
                } else {
                    printf("\nFalha ao modificar o elemento.\n");
                }
                break;
            case 6:
                return 0;
            default:
                fgets(lixo,100,stdin);
                printf("\nOpcao invalida.\n");
        }
    }
    return 0;
}