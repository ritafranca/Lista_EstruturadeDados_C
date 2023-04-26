#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 //defininindo quantidade de filas 

typedef struct { //definindo a estrutura de pilha
    int topo;
    int valor[MAX_SIZE]; //armazena os valores da pilha
} Pilha;

typedef struct { //criando uma estrutura  de fila de pilhas
    int tam; //tamanho da fila de pilhas
    Pilha* pilhas[MAX_SIZE]; //armazena as pilhas
} FilaDePilhas;

void inicializarPilha(Pilha* p) { //inicializa a pilha com o topo sendo  -1 
    p->topo = -1;
}

int pilhaVazia(Pilha* p) { //checa se a pilha esta vazia
    return (p->topo == -1);
}

int pilhaCheia(Pilha* p) { 
    return (p->topo == MAX_SIZE - 1);
}

void add(Pilha* p, int valor) { //adiciona um valor na pilha se ela não estiver cheia e atualiza o topo
    if (pilhaCheia(p)) {  //para caso a pilha estiver cheia
        printf("Pilha cheia\n");
        exit(1);
    } else {
        p->valor[++(p->topo)] = valor;
    }
}

int remover(Pilha* p) { //remove e retorna o valor do topo da pilha se ela não estiver vazia e atualiza o topo
    if (pilhaVazia(p)) {
        printf("Pilha vazia\n");
        exit(1);
    } else {
        return p->valor[(p->topo)--];
    }
}

void inicializarFilaDePilhas(FilaDePilhas* f) {
    f->tam = 0;
}

int filaDePilhasVazia(FilaDePilhas* f) {
    return (f->tam == 0);
}

void addNaFilaDePilhas(FilaDePilhas* f, int valor) { //adiciona um valor na fila de pilhas. 
//se a fila de pilhas estiver vazia ou a última pilha estiver cheia cria uma nova pilha e adiciona o valor nela e incrementa o tamanho da fila de pilhas
//se n, adiciona o valor na última pilha da fila de pilhas
    if (f->tam == 0 || pilhaCheia(f->pilhas[f->tam-1])) {
        f->pilhas[f->tam] = (Pilha*) malloc(sizeof(Pilha));
        inicializarPilha(f->pilhas[f->tam]);
        add(f->pilhas[f->tam], valor);
        f->tam++;
    } else {
        add(f->pilhas[f->tam-1], valor);
    }
}

int removerDaFilaDePilhas(FilaDePilhas* f) { //remove e retorna o primeiro valor da fila de pilhas
//se a primeira pilha da fila de pilhas estiver vazia após a remoção remove a pilha e desloca as outras pilhas uma posição 
    if (filaDePilhasVazia(f)) {
        printf("Fila vazia\n");
        exit(1);
    }
    int valor = remover(f->pilhas[0]);
    if (pilhaVazia(f->pilhas[0])) {
        free(f->pilhas[0]);
        for (int i = 0; i < f->tam-1; i++) {
            f->pilhas[i] = f->pilhas[i+1];
        }
        f->tam--;
    }
    return valor;
}

int main() {
    FilaDePilhas f;
    inicializarFilaDePilhas(&f);

    // adiciona elementos na primeira pilha
    addNaFilaDePilhas(&f, 1);
    addNaFilaDePilhas(&f, 2);
    addNaFilaDePilhas(&f, 3);
    addNaFilaDePilhas(&f, 4);
    addNaFilaDePilhas(&f, 5);
    addNaFilaDePilhas(&f, 6);

    // adiciona elementos em outra nova pilha
    addNaFilaDePilhas(&f, 7);
    addNaFilaDePilhas(&f, 8);
    addNaFilaDePilhas(&f, 9);

    // adiciona elementos em uma nova pilha
    addNaFilaDePilhas(&f, 10);
    addNaFilaDePilhas(&f, 11);
    addNaFilaDePilhas(&f, 12);
    addNaFilaDePilhas(&f, 13);

    //imprimir a fila de pilhas
    printf("Fila de Pilhas:\n");
    for (int i = 0; i < f.tam; i++) {
        printf("Pilha %d: ", i+1);
        for (int j = 0; j <= f.pilhas[i]->topo; j++) {
            printf("%d ", f.pilhas[i]->valor[j]);
        }
        printf("\n");
    }

    return 0;
}
