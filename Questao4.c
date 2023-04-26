#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct no { //criando o no para ser uitrilizado na pilha
    double valor;
    struct no *prox;
} No;

typedef struct pilha {  //criando a pilha
    No *topo;
} Pilha;

Pilha* cria_pilha() { //aloca a memória para a pilha e inicializa o ponteiro para o topo como nulo
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

int pilha_vazia(Pilha *p) { //checa se o topo da fila esta vazio 
    return p->topo == NULL;
}

void empilha(Pilha *p, double valor) { //insere um valor na pilha criando um novo nó e apontando o seu ponteiro para o próximo nó para o topo da pilha anterior
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

double desempilha(Pilha *p) { //remove e retorna o valor do topo da pilha
    if (pilha_vazia(p)) {
        printf("pilha vazia :o!\n");
        exit(1);
    }
    double valor = p->topo->valor;
    No *aux = p->topo;
    p->topo = p->topo->prox;
    free(aux);
    return valor;
}

double topo_pilha(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("pilha vazia :o\n");
        exit(1);
    }
    return p->topo->valor;
}

double calcula(char *expressao) { //funcao para realizar os calculos dados pelo usuario 
    Pilha *p = cria_pilha();
    double operando1, operando2;
    while (*expressao) { //vai percorrer cada caractere da expressão 
        if (isdigit(*expressao)) {
            empilha(p, atof(expressao));
            while (isdigit(*expressao)) expressao++;
        } else if (*expressao == '+' || *expressao == '-' || *expressao == '*' || *expressao == '/') { // empilha os operandos e desempilha realizando as operações quando encontra um operador
            operando2 = desempilha(p);
            operando1 = desempilha(p);
            switch (*expressao) {
                case '+': empilha(p, operando1 + operando2); break;
                case '-': empilha(p, operando1 - operando2); break;
                case '*': empilha(p, operando1 * operando2); break;
                case '/': empilha(p, operando1 / operando2); break;
            }
            expressao++;
        } else {
            expressao++;
        }
    }
    double resultado = desempilha(p); //aqui retorna o resultado
    if (!pilha_vazia(p)) {
        printf("expressao invalida, tente novamente!\n");
        exit(1);
    }
    return resultado; //retornando o resultado da operacao 
}

int main() {
    Pilha *resultados = cria_pilha();
    char expressao[100];
    double resultado;
    do {
        printf("Digite a expressao posfixada (ou aperte ENTER para FINALIZAR :)): ");
        fgets(expressao, 100, stdin);
        if (*expressao != '\n') {
            resultado = calcula(expressao);
            empilha(resultados, resultado);
        }
    } while (*expressao != '\n');
    printf("Resultados: ");
    while (!pilha_vazia(resultados)) {
        printf("%.2f ", desempilha(resultados));
    }
    printf("\n");
    return 0;
}
