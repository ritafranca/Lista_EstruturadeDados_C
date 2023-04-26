#include <stdio.h>
#define MAX 100 //definindo o tam max de caixas

typedef struct pilha { //criando a struct pilha
    int topo;
    int caixas[MAX];
} Pilha;

void inicializaPilha(Pilha *p) { //funçao para inicializar a pilha com o topo sendo -1
    p->topo = -1;
}

int pilhaVazia(Pilha *p) { //feito para verificar se a pilha ta vazia 
    return (p->topo == -1);
}

int pilhaCheia(Pilha *p) { //aqui ela verifica se a pilha esta cheia comparando o topo com -1
    return (p->topo == MAX-1);
}

void empilha(Pilha *p, int caixa) { //adiciona a caixa a pilha se n tiver cheia
    if (pilhaCheia(p)) { //aqui é caso a pilha esteja cheia 
        printf("pilha cheia!\n");
        return;
    }
    p->topo++;
    p->caixas[p->topo] = caixa;
}

int desempilha(Pilha *p) { //aqui ela remove a caixa do topo da pilha se ela n tiver vazia colocando esse valor em uma variuavel 
    if (pilhaVazia(p)) { //caso a pilha esteja vazia
        printf("pilha vazia!\n");
        return -1;
    }
    int caixa = p->caixas[p->topo]; 
    p->topo--;
    return caixa;
}

void moveCaixas(Pilha *origem, Pilha *destino) { //essa funcao é pra mover as caixas da pilha A para as pilhas B e C ate q a A possa receber elas
    while (!pilhaVazia(origem)) {
        int caixa = desempilha(origem);
        empilha(destino, caixa);
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

    return 0;
}
