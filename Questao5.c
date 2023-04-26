#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct { //implementando uma fila para armazenar a sequência de caracteres digitada pelo usuário
    int inicio, fim;
    char caracteres[MAX_SIZE];
} Fila;

typedef struct { //implementando uma fila para armazenar a mesma sequência de caracteres mas em ordem inversa
    int topo;
    char caracteres[MAX_SIZE];
} Pilha;

void inicializarFila(Fila* f) { //recebe como parâmetro um ponteiro para uma pilha e inicializa seu topo com -1 pra indicar que a pilha está vazia
    f->inicio = f->fim = -1;
}

int filaVazia(Fila* f) { //recebe um ponteiro para uma pilha e verifica se ela está vazia quie é quando o topo da pilha é igual a -1
    return (f->inicio == -1);
}

int filaCheia(Fila* f) { //recebe um ponteiro para uma pilha e verifica se ela está cheia q é quando o topo da pilha é igual a MAX_SIZE - 1
    return ((f->fim + 1) % MAX_SIZE == f->inicio);
}

void enfileirar(Fila* f, char caractere) {
    if (filaCheia(f)) {
        printf("Fila cheia\n");
        exit(1);
    } else {
        if (filaVazia(f)) {
            f->inicio = f->fim = 0;
        } else {
            f->fim = (f->fim + 1) % MAX_SIZE;
        }
        f->caracteres[f->fim] = caractere;
    }
}

char desenfileirar(Fila* f) {
    if (filaVazia(f)) {
        printf("Fila vazia\n");
        exit(1);
    } else {
        char caractere = f->caracteres[f->inicio];
        if (f->inicio == f->fim) {
            inicializarFila(f);
        } else {
            f->inicio = (f->inicio + 1) % MAX_SIZE;
        }
        return caractere;
    }
}

void inicializarPilha(Pilha* p) { //mesma logica da pilha
    p->topo = -1;
}

int pilhaVazia(Pilha* p) {
    return (p->topo == -1);
}

int pilhaCheia(Pilha* p) {
    return (p->topo == MAX_SIZE - 1);
}

void empilhar(Pilha* p, char caractere) {
    if (pilhaCheia(p)) {
        printf("Pilha cheia\n");
        exit(1);
    } else {
        p->caracteres[++(p->topo)] = caractere;
    }
}

char desempilhar(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia\n");
        exit(1);
    } else {
        return p->caracteres[(p->topo)--];
    }
}

int main() { //aqui na main um caractere é removido da fila usando a função desenfileirar e em seguida é removido o caractere correspondente do topo da pilha usando o desempilhar

    Fila f;
    Pilha p;
    char caractere;

    inicializarFila(&f);
    inicializarPilha(&p);

printf("Digite uma sequencia de caracteres: ");
while ((caractere = getchar()) != '\n') {
    enfileirar(&f, caractere);
    empilhar(&p, caractere);
}
//o caractere removido da pilha é então impresso, e a sequência de caracteres resultante é a sequência digitada pelo usuario mas com a ordem dos caracteres invertida
while (!filaVazia(&f)) {
    caractere = desenfileirar(&f);
    caractere = desempilhar(&p);
    printf("%c", caractere);
}

}