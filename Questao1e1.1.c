//Questão 01:
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* proximo;
} No;

No* topo = NULL;
int tamanho = 0;

void adicionar(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = topo;
    topo = novo;
    tamanho++;
}

int remover() {
    if (topo == NULL) {
        printf("Pilha vazia!\n");
        return -1;
    }
    int valor = topo->valor;
    No* aux = topo;
    topo = topo->proximo;
    free(aux);
    tamanho--;
    return valor;
}

void imprimir() {
    if (topo == NULL) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Elementos:\n");
    No* aux = topo;
    while (aux != NULL) {
        printf("%d\n", aux->valor);
        aux = aux->proximo;
    }
    printf("Tamanho da pilha: %d\n", tamanho);
}

int main() {
    adicionar(1);
    adicionar(2);
    adicionar(3);
    adicionar(4);
    adicionar(4);
    imprimir();
    remover(2);
    imprimir();
    return 0;
}

//* Questão 2: Foi utilizada a estrutura de lista encadeada para implementar a pilha, foi utilizada pois as operações de adicionar e remover elementos são mais eficientes do que em um array, alem disso a lista encadeada permite o uso de memória dinâmica, ou seja, alocar e desalocar memória durante a execução do programa, o que é muito útil quando o tamanho da pilha é desconhecido ou variável.