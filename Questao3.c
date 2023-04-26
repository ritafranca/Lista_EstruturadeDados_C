#include <stdio.h>
#include <stdlib.h>

typedef struct caixa { // criando a struct caixa
    int peso;
    struct caixa* prox;
} Caixa;

typedef struct pilha { // criando a struct pilha
    Caixa* topo;
} Pilha;

void inicializaPilha(Pilha* p) { //funçao para inicializar a pilha com o topo sendo NULL
    p->topo = NULL;
}

int pilhaVazia(Pilha* p) { // feito para verificar se a pilha ta vazia
    return (p->topo == NULL);
}

void empilha(Pilha* p, int caixaPeso) { //adiciona a caixa a pilha
    Caixa* novaCaixa = (Caixa*) malloc(sizeof(Caixa));
    novaCaixa->peso = caixaPeso;
    novaCaixa->prox = p->topo;
    p->topo = novaCaixa;
}

int desempilha(Pilha* p) { //aqui ela remove a caixa do topo da pilha se ela n tiver vazia colocando esse valor em uma variavel 
    if (pilhaVazia(p)) { //caso a pilha esteja vazia
        printf("pilha vazia!\n");
        return -1;
    }
    int caixaPeso = p->topo->peso;
    Caixa* caixaRemovida = p->topo;
    p->topo = p->topo->prox;
    free(caixaRemovida);
    return caixaPeso;
}

void moveCaixas(Pilha* origem, Pilha* destino) { //essa funcao é pra mover as caixas da pilha A para as pilhas B e C ate q a A possa receber elas
    while (!pilhaVazia(origem)) {
        int caixaPeso = desempilha(origem);
        empilha(destino, caixaPeso);
    }
}

int main() {
    Pilha A, B, C;
    inicializaPilha(&A);
    inicializaPilha(&B);
    inicializaPilha(&C);

int caixa;
printf("Digite o peso da caixa (3, 5 ou 7) ou 0 para sair:\n");
scanf("%d", &caixa);
while (caixa != 0) {
    if (caixa != 3 && caixa != 5 && caixa != 7) {
        printf("Caixa de peso invalido, tente 3, 5 ou 7!\n");
    } else if (pilhaVazia(&A) || caixa <= A.caixas[A.topo]) {
        empilha(&A, caixa);
    } else if (caixa == 7 && A.caixas[A.topo] == 5) {
        moveCaixas(&A, &B);
        empilha(&A, caixa);
        moveCaixas(&B, &A);
    } else if (caixa == 7 && A.caixas[A.topo] == 3) {
        moveCaixas(&A, &C);
        empilha(&A, caixa);
        moveCaixas(&C, &A);
    }else if (caixa != 3 && caixa == 5 && caixa !=7) {
        empilha(&A, caixa);
    } else {
        printf("Erro: caixa de peso invalido na pilha A\n");
    }

    printf("Pilha A:");
    for (int i = A.topo; i >= 0; i--) {
        printf(" %d", A.caixas[i]);
    }
    printf("\n");

    printf("Digite o peso da caixa (3, 5 ou 7) ou 0 para sair:\n");
    scanf("%d", &caixa);
}

free(A.caixas);
free(B.caixas);
free(C.caixas);
return 0;
