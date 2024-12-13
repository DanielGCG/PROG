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
        printf("%c ", end->reg.chave);
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

int forma_par(char f, char d) {
    switch (f) {
        case ')':
            return (d == '(');
        case ']':
            return (d == '[');
        case '}':
            return (d == '{');
    }
    return 0; // Se não corresponder a nenhum caso, retorna falso
}

bool verificar(char expressao[50]) {
    int contador = 0;
    PILHA calculo;
    PILHA *pil;
    pil = &calculo;
    inicializarPilha(pil);

    // Ler a string até o fim
    while (expressao[contador] != '\0') {
        // Se encontrarmos abertura de { ( [, adicionamos a pilha
        if (expressao[contador] == '[' || expressao[contador] == '(' || expressao[contador] == '{') {
            push(pil, (REGISTRO) {expressao[contador]});
        // Se encontrarmos fechameento de } ) ], removemos da pilha 
        } else if (expressao[contador] == ']' || expressao[contador] == ')' || expressao[contador] == '}') {
            REGISTRO removido;
            if (!pop(pil, &removido) || !forma_par(expressao[contador], removido.chave)) {
                printf("\nNao deu certo! :(");
                return false;
            }
        }
        contador++;
    }

    if (!estaVazia(pil)) {
        printf("\nNao deu certo! :(");
        return false;
    } else {
        printf("\nDeu certo! :)");
        return true;
    }
}

int main() {
    char expressao[50];

    printf("\nEscreva a expressao a ser armazenada numa pilha: ");
    scanf("%s", expressao);

    verificar(expressao);

    return 0;
}