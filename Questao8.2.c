#include <stdio.h>
#include <stdlib.h>

// cruando nó da lista
struct no {
    int valor;
    struct no *prox;
};

// funçao para criar um novo nó
struct no* novoNo(int valor) {
    struct no* aux = (struct no*)malloc(sizeof(struct no));
    aux->valor = valor;
    aux->prox = NULL;
    return aux;
}

// funcao para adicionar um elemento na fila de prioridade
void inserir(struct no** inicio, int valor) {
    struct no* aux = novoNo(valor);
    struct no* anterior = NULL;
    struct no* topo = *inicio;

    // percorre a lista até encontrar a posição correta de inserção
    while (topo != NULL && valor < topo->valor) {
        anterior = topo;
        topo = topo->prox;
    }

    // insere o novo elemento na lista
    aux->prox = topo;
    if (anterior == NULL) {
        *inicio = aux;
    }
    else {
        anterior->prox = aux;
    }
}

// funcao para remover o elemento de maior prioridade da fila
void remover(struct no** inicio) {
    if (*inicio == NULL) {
        printf("Fila vazia.\n");
        return;
    }
    struct no* aux = *inicio;
    *inicio = (*inicio)->prox;
    free(aux);
}

// funcao para imprimir os elementos da fila
void imprimirFila(struct no* inicio) {
    printf("Fila: ");
    struct no* topo = inicio;
    while (topo != NULL) {
        printf("%d ", topo->valor);
        topo = topo->prox;
    }
    printf("\n");
}

int main() {
    struct no* inicio = NULL;

    // teste dos metodos da fila de prioridade utilizando lista nao ordenada
    inserir(&inicio, 10);
    inserir(&inicio, 20);
    inserir(&inicio, 5);
    inserir(&inicio, 30);
    imprimirFila(inicio);
    remover(&inicio);
    imprimirFila(inicio);
    inserir(&inicio, 15);
    imprimirFila(inicio);

    return 0;
}
