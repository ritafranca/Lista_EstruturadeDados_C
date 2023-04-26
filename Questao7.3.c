#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

//criando a fila
struct fila {
    int elementos[MAX_QUEUE_SIZE];
    int inicio;
    int fim;
};

//funcao que cria uma nova fila
struct fila* criarFila() {
    struct fila* f = malloc(sizeof(struct fila));
    f->inicio = -1;
    f->fim = -1;
    return f;
}

//funcao que verifica se a fila está vazia
int estaVazia(struct fila* f) {
    if (f->fim == -1) {
        return 1;
    } else {
        return 0;
    }
}

//funcao que insere um elemento na fila
void enfileirar(struct fila* f, int valor) {
    if (f->fim == MAX_QUEUE_SIZE - 1) {
        printf("A fila está cheia.\n");
    } else {
        if (f->inicio == -1) {
            f->inicio = 0;
        }
        f->fim++;
        f->elementos[f->fim] = valor;
    }
}

//funcao que remove um elemento da fila
int desenfileirar(struct fila* f) {
    int elemento;
    if (estaVazia(f)) {
        printf("A fila está vazia.\n");
        elemento = -1;
    } else {
        elemento = f->elementos[f->inicio];
        f->inicio++;
        if (f->inicio > f->fim) {
            f->inicio = f->fim = -1;
        }
    }
    return elemento;
}

int main() {
    //criando a fila de filas
    struct fila* filaDeFilas = criarFila();

    //criando as filas internas
    struct fila* fila1 = criarFila();
    struct fila* fila2 = criarFila();

    //inserindo elementos nas filas internas
    enfileirar(fila1, 1);
    enfileirar(fila1, 2);
    enfileirar(fila1, 3);

    enfileirar(fila2, 4);
    enfileirar(fila2, 5);
    enfileirar(fila2, 6);


//imprimindo a lista de listas antes de liberar a memória
enfileirar(filaDeFilas, (int) fila1);
enfileirar(filaDeFilas, (int) fila2);

printf("Lista de listas: ");
while (!estaVazia(filaDeFilas)) {
    struct fila* filaAtual = (struct fila*)filaDeFilas->elementos[filaDeFilas->inicio];
    printf("[");
    while (!estaVazia(filaAtual)) {
        printf("%d", desenfileirar(filaAtual));
        if (!estaVazia(filaAtual)) {
            printf(", ");
        }
    }
    printf("]");
    if (!estaVazia(filaDeFilas)) {
        printf(", ");
        desenfileirar(filaDeFilas);
    }
}
printf("\n");

free(fila1);
free(fila2);
free(filaDeFilas);

return 0;

}