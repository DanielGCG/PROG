#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

// Estruturação de tipos de dados
typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux *prox;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct {
    PONT topo;
} PILHA;

// Implementação das funções
void inicializarPilha(PILHA *p) {
    p->topo = NULL;
}

int tamanho(PILHA *p) {
    PONT end = p->topo;
    int tam = 0;
    while (end != NULL) {
        tam++;
        end = end->prox;
    }
    return tam;
}

bool estaVazia(PILHA *p) {
    if (p->topo == NULL)
        return true;
    return false;
}

void exibirPilha(PILHA *p) {
    PONT end = p->topo;
    printf("Pilha: \" ");
    while (end != NULL) {
        printf("%d ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}

bool push(PILHA *p, REGISTRO reg) {
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    if (novo == NULL)
        return false;
    novo->reg = reg;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

bool pop(PILHA *p, REGISTRO *reg) {
    if (p->topo == NULL)
        return false;
    *reg = p->topo->reg;
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);
    return true;
}

void reinicializarPilha(PILHA *p) {
    PONT apagar;
    PONT posicao = p->topo;
    while (posicao != NULL) {
        apagar = posicao;
        posicao = posicao->prox;
        free(apagar);
    }
    p->topo = NULL;
}

int main() {
    char nomearq[50];
    char caractere;
    PILHA calculo, *pil;
    pil = &calculo;

    // Recebimento do nome do arquivo
    printf("\nEscreva o nome do arquivo que deseja ler: ");
    scanf("%s", nomearq);

    // Abertura do arquivo texto
    FILE *arq = fopen(nomearq, "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.");
        return -1;
    }

    inicializarPilha(pil);
    REGISTRO esq, dir;
    while (fscanf(arq, " %c", &caractere) != EOF) {
        
        if (caractere == ' ') {
            continue;
        }
        
        if (caractere == '+') {
            pop(pil, &dir);
            pop(pil, &esq);
            push(pil, (REGISTRO){esq.chave + dir.chave, esq.chave + dir.chave});
            printf("\n%d + %d = %d", esq.chave, dir.chave, esq.chave + dir.chave);
            continue;
        }

        if (caractere == '-') {
            pop(pil, &dir);
            pop(pil, &esq);
            push(pil, (REGISTRO){esq.chave - dir.chave, esq.chave - dir.chave});
            printf("\n%d - %d = %d", esq.chave, dir.chave, esq.chave - dir.chave);
            continue;
        }

        if (caractere == '*') {
            pop(pil, &dir);
            pop(pil, &esq);
            push(pil, (REGISTRO){esq.chave * dir.chave, esq.chave * dir.chave});
            printf("\n%d * %d = %d", esq.chave, dir.chave, esq.chave * dir.chave);
            continue;
        }

        else
            push(pil, (REGISTRO){caractere - '0', 0});
    }

    printf("\nResultado: ");

    exibirPilha(pil);

    fclose(arq);

    return 0;
}
