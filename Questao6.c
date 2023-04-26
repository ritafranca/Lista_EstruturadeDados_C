#include <stdio.h>
#include <stdlib.h>

typedef struct no { //criando um no com um int chave para a remoçao na pilhja
int chave;
struct no *proximo;
} No;

typedef struct pilha { //cria a pilha
No *topo;
} Pilha;

void add(Pilha *p, int chave) { //adicionar um novo nó contendo a chave especificada no topo da pilha
// vamos alocar memória para um novo nó definir a chave e fazer o novo nó apontar para o antigo topo e definir o topo da pilha como o novo nó
No *novo_no = (No *) malloc(sizeof(No));
novo_no->chave = chave;
novo_no->proximo = p->topo;
p->topo = novo_no;
}

int remover(Pilha *p) { //remover o nó no topo da pilha e retornar sua chave
if (p->topo == NULL) {
printf("Erro: Pilha vazia.\n");
return -1;
}
int chave = p->topo->chave;
No *temp = p->topo;
p->topo = p->topo->proximo;
free(temp);
return chave;
}

void remover_item(Pilha *p, int c) { //remover o primeiro nó na pilha que contém uma chave específica. 
Pilha pilha_temporaria; //cria uma nova pilha temporária vazia
pilha_temporaria.topo = NULL;
int chave_removida;
//se a chave não for igual ela adiciona o nó em questão à pilha temporária
//se a chave for igual, ela para de percorrer a pilha original e começa a reconstruir a pilha original add todos os nós da pilha temporária de volta a pilha original
while (p->topo != NULL) { 
chave_removida = remover(p);
if (chave_removida != c) {
add(&pilha_temporaria, chave_removida);
} else {
break;
}
}
while (pilha_temporaria.topo != NULL) { 
add(p, remover(&pilha_temporaria));
}
}

int main() {
Pilha p;
p.topo = NULL;
int n, chave, c;
printf("Digite o numero de itens na pilha: ");
scanf("%d", &n);
printf("Digite os itens:\n");
for (int i = 0; i < n; i++) {
scanf("%d", &chave);
add(&p, chave);
}
printf("Digite a chave do item a ser removido: "); //pede para o adicionario escolher a chave do item
scanf("%d", &c);
remover_item(&p, c); //recebe a chave e remove ela da pilha
printf("A pilha modificada:\n"); 
while (p.topo != NULL) {
printf("%d\n", remover(&p));
}
return 0;
}