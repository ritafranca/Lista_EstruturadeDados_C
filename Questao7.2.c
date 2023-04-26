//Pilha de Filas
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 

typedef struct {  //definindo a estrutura fila
    int inicio, fim;
    int valor[MAX_SIZE];
} Fila;

typedef struct { //definindo a estrutura pilha de filas
    int topo;
    Fila* filas[MAX_SIZE];
} PilhaDeFilas;

void inicializarFila(Fila* f) { //recebe um ponteiro para uma fila 
//inicializa os campos inicio e fim com o valor -1 indicando que a fila está vazia
    f->inicio = f->fim = -1;
}

int filaVazia(Fila* f) { //recebe um ponteiro para uma fila e retorna 1 se a fila estiver vazia
    return (f->inicio == -1);
}

int filaCheia(Fila* f) { //recebe um ponteiro para uma fila e retorna 1 se a fila estiver cheia 
    return ((f->fim + 1) % MAX_SIZE == f->inicio);
}

void enfileirar(Fila* f, int valor) {

    if (filaCheia(f)) {
        printf("Fila cheia\n");
        exit(1);
    } else 
    {
        if (filaVazia(f)) {
            f->inicio = f->fim = 0;
        } else {
            f->fim = (f->fim + 1) % MAX_SIZE;
        }
        f->valor[f->fim] = valor;
    }
}
int desenfileirar(Fila* f) { // recebe um ponteiro para uma fila e remove o primeiro valor da fila
    if (filaVazia(f)) {
        printf("Fila vazia\n");
        exit(1);
    } else {
        int valor = f->valor[f->inicio];
        if (f->inicio == f->fim) {
            inicializarFila(f);
        } else {
            f->inicio = (f->inicio + 1) % MAX_SIZE;
        }
        return valor;
    }
}

void inicializarPilhaDeFilas(PilhaDeFilas* p) { //recebe um ponteiro para uma pilha de filas e inicializa o campo topo com o valor -1 = a pilha está vazia
    p->topo = -1;
}

int pilhaDeFilasVazia(PilhaDeFilas* p) {
    return (p->topo == -1);
}

int pilhaDeFilasCheia(PilhaDeFilas* p) {
    return (p->topo == MAX_SIZE - 1);
}

void add(PilhaDeFilas* p, int valor) {
    if (pilhaDeFilasCheia(p)) {
        printf("Pilha cheia\n");
        exit(1);
    } else {
        if (pilhaDeFilasVazia(p) || filaCheia(p->filas[p->topo])) {
            p->filas[++(p->topo)] = (Fila*) malloc(sizeof(Fila));
            inicializarFila(p->filas[p->topo]);
        }
        enfileirar(p->filas[p->topo], valor);
    }
}

int remover(PilhaDeFilas* p) {
    if (pilhaDeFilasVazia(p)) {
        printf("Pilha vazia\n");
        exit(1);
    } else {
        int valor = desenfileirar(p->filas[p->topo]);
        if (filaVazia(p->filas[p->topo])) {
            free(p->filas[p->topo]);
            p->topo--;
        }
        return valor;
    }
}

void printPilhaDeFilas(PilhaDeFilas* p) {
    int i, j;
    for (i = p->topo; i >= 0; i--) {
        printf("Fila %d: ", i+1);
        for (j = p->filas[i]->inicio; j <= p->filas[i]->fim; j++) {
            printf("%d ", p->filas[i]->valor[j]);
        }
        printf("\n");
    }
}


int main() {
    PilhaDeFilas p;
    inicializarPilhaDeFilas(&p);

    add(&p, 1);
    add(&p, 2);
    add(&p, 3);
    add(&p, 4);
    add(&p, 5);
    add(&p, 6);
    add(&p, 7);
    add(&p, 8);

    printPilhaDeFilas(&p);

    return 0;
}
