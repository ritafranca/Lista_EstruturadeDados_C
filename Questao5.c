#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct { //implementando uma fila para armazenar a sequência de caracteres digitada pelo usuário
    int inicio, fim, tamanho;
    char* caracteres;
} Fila;

typedef struct { //implementando uma fila para armazenar a mesma sequência de caracteres mas em ordem inversa
    int topo, tamanho;
    char* caracteres;
} Pilha;

void inicializarFila(Fila* f) { //recebe como parâmetro um ponteiro para uma pilha e inicializa seu topo com -1 pra indicar que a pilha está vazia
    f->inicio = f->fim = -1;
    f->tamanho = 0;
    f->caracteres = NULL;
}

int filaVazia(Fila* f) { //recebe um ponteiro para uma pilha e verifica se ela está vazia quie é quando o topo da pilha é igual a -1
    return (f->inicio == -1);
}

void enfileirar(Fila* f, char caractere) {
    if (filaVazia(f)) {
        f->caracteres = (char*)malloc(sizeof(char));
        f->caracteres[0] = caractere;
        f->inicio = f->fim = 0;
        f->tamanho = 1;
    } else {
        if (f->fim == f->tamanho - 1) {
            f->caracteres = (char*)realloc(f->caracteres, 2 * f->tamanho * sizeof(char));
            f->tamanho *= 2;
        }
        f->fim++;
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
            free(f->caracteres);
            inicializarFila(f);
        } else {
            f->inicio++;
        }
        return caractere;
    }
}

void inicializarPilha(Pilha* p) { //mesma logica da pilha
    p->topo = -1;
    p->tamanho = 0;
    p->caracteres = NULL;
}

int pilhaVazia(Pilha* p) {
    return (p->topo == -1);
}

void empilhar(Pilha* p, char caractere) {
    if (pilhaVazia(p)) {
        p->caracteres = (char*)malloc(sizeof(char));
        p->caracteres[0] = caractere;
        p->topo = 0;
        p->tamanho = 1;
    } else {
        if (p->topo == p->tamanho - 1) {
            p->caracteres = (char*)realloc(p->caracteres, 2 * p->tamanho * sizeof(char));
            p->tamanho *= 2;
        }
        p->topo++;
        p->caracteres[p->topo] = caractere;
}
}

char desempilhar(Pilha* p) {
if (pilhaVazia(p)) {
printf("Pilha vazia\n");
exit(1);
} else {
char caractere = p->caracteres[p->topo];
p->topo--;
return caractere;
}
}

int main() {
Fila fila;
Pilha pilha;
char caractere;
inicializarFila(&fila);
inicializarPilha(&pilha);

printf("Digite uma sequencia de caracteres: ");
do {
    scanf("%c", &caractere);
    if (isalpha(caractere)) { //verifica se o caractere é uma letra
        enfileirar(&fila, caractere); //adiciona o caractere na fila
        empilhar(&pilha, caractere); //adiciona o caractere na pilha
    }
} while (caractere != '\n'); //le até o usuário pressionar enter

printf("Caracteres na ordem digitada: ");
while (!filaVazia(&fila)) {
    printf("%c", desenfileirar(&fila)); //desenfileira e imprime cada caractere da fila
}
printf("\n");

printf("Caracteres na ordem inversa: ");
while (!pilhaVazia(&pilha)) {
    printf("%c", desempilhar(&pilha)); //desempilha e imprime cada caractere da pilha
}
printf("\n");

return 0;
}

