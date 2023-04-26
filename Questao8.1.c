#include <stdio.h>
#include <stdlib.h>

//criando nó da lista
struct no {
    int valor;
    struct no *prox;
};

//criando um novo nó
struct no* novoNo(int valor) {
    struct no* aux = (struct no*)malloc(sizeof(struct no));
    aux->valor = valor;
    aux->prox = NULL;
    return aux;
}

// funcao para adicionar um elemento na fila
void inserir(struct no** inicio, int valor) {
    struct no* aux = novoNo(valor);

    // se a fila tiver vazia ou o novo elemento tem prioridade maior que o primeiro
    if (*inicio == NULL || valor > (*inicio)->valor) {
        aux->prox = *inicio;
        *inicio = aux;
    }
    else {
        // percorre a fila para encontrar a posição correta de inserção
        struct no* topo = *inicio;
        while (topo->prox != NULL && topo->prox->valor >= valor) {
            topo = topo->prox;
        }
        aux->prox = topo->prox;
        topo->prox = aux;
    }
}

// função para remover o elemento de maior prioridade da fila
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

    // teste dos métodos da fila de prioridade utilizando lista ordenada
    inserir(&inicio, 10);
    inserir(&inicio, 20);
    inserir(&inicio, 5);
    inserir(&inicio, 15);
    inserir(&inicio, 30);
    imprimirFila(inicio);
    remover(&inicio);
    imprimirFila(inicio);
    remover(&inicio);
    imprimirFila(inicio);

    return 0;
}
