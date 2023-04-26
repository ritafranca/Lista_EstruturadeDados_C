#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} NO;

NO *inicio = NULL; 
NO *fim = NULL; 
int tam = 0; 

void adicionar(int valor) {
    NO *novo = malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;

    if (inicio == NULL) { // fila está vazia
        inicio = novo;
    } else {
        fim->prox = novo;
    }
    fim = novo;
    tam++;
}


int remover() {
    if (inicio == NULL) { 
        printf("Fila vazia!\n");
        return -1;
    }

    NO *temp = inicio;
    int valor = inicio->valor;
    inicio = inicio->prox;
    free(temp);
    tam--;
    
    if (inicio == NULL) { 
        fim = NULL;
    }

    return valor;
}


void imprimir() {
    NO *temp = inicio;
    while (temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->prox;
    }
    printf("\nTamanho da fila: %d\n", tam);
}


int tamanho() {
    return tam;
}

int main() {
    adicionar(10);
    adicionar(20);
    adicionar(30);
    adicionar(40);
    adicionar(50);
    imprimir();
    remover();
    imprimir();
    return 0;
}

//Questão 4: Foi utilizado novamente estrutura de lista encadeada, porque é uma estrutura de dados que permite a inserção e remoção de elementos em tempo constante, independentemente do tamanho da fila. Outra vantagem é que não há limitação de tamanho pré-definido, diferente de estruturas como o array. Além disso, ela pode facilmente ser implementada de forma a permitir a inserção de elementos iguais como foi pedido na questão, basta apenas criar um novo nó para cada elemento adicionado à fila.