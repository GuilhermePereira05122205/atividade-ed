#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
#define CAPACIDADE 10  // Define o tamanho máximo da fila
 
// Estrutura para representar a Fila Circular
typedef struct {
    int frente;      // Índice do primeiro elemento da fila
    int finalFila;   // Índice do último elemento da fila
    int* fila;       // Ponteiro para o array que armazena os elementos da fila
} FilaCircular;
 
// Função para criar e inicializar uma nova fila com capacidade especificada
FilaCircular* criaFila() {
    FilaCircular* fila = (FilaCircular*)malloc(sizeof(FilaCircular));
    fila->frente = -1;                    // Inicializa o índice da frente como -1 (vazia)
    fila->finalFila = -1;                 // Inicializa o índice do final como -1 (vazia)
    fila->fila = (int*)malloc(CAPACIDADE * sizeof(int));  // Aloca o array para os elementos
    return fila;
}
 
// Função para verificar se a fila está vazia
bool vazia(FilaCircular* fila) {
    return fila->frente == -1;
}
 
// Função para verificar se a fila está cheia
bool cheia(FilaCircular* fila) {
    return (fila->finalFila + 1) % CAPACIDADE == fila->frente;
}
 
// Função para adicionar um elemento no final da fila
void enfileira(FilaCircular* fila, int obj) {
    if (cheia(fila)) {
        printf("Fila está cheia!\n");
        return;
    }
    fila->finalFila = (fila->finalFila + 1) % CAPACIDADE;
    fila->fila[fila->finalFila] = obj;
    if (fila->frente == -1) {
        fila->frente = fila->finalFila;
    }
}
 
// Função para remover e retornar o primeiro elemento da fila
int desenfileira(FilaCircular* fila) {
    if (vazia(fila)) {
        printf("Fila está vazia!\n");
        return -1;
    }
    int item = fila->fila[fila->frente];
    if (fila->frente == fila->finalFila) {
        fila->frente = -1;
        fila->finalFila = -1;
    } else {
        fila->frente = (fila->frente + 1) % CAPACIDADE;
    }
    return item;
}
 
// Função para retornar o primeiro elemento da fila sem removê-lo
int cabeca(FilaCircular* fila) {
    if (vazia(fila)) {
        printf("Fila está vazia!\n");
        return -1;
    }
    return fila->fila[fila->frente];
}
 
// Função para retornar o último elemento da fila sem removê-lo
int cauda(FilaCircular* fila) {
    if (vazia(fila)) {
        printf("Fila está vazia!\n");
        return -1;
    }
    return fila->fila[fila->finalFila];
}
 
// Função para exibir todos os elementos da fila em ordem
void mostrarFila(FilaCircular* fila) {
    if (vazia(fila)) {
        printf("Fila está vazia!\n");
        return;
    }
    int i = fila->frente;
    do {
        printf("%d ", fila->fila[i]);
        i = (i + 1) % CAPACIDADE;
    } while (i != (fila->finalFila + 1) % CAPACIDADE);
    printf("\n");
}
 
// Função para pesquisar se um elemento existe na fila
bool pesquisa(FilaCircular* fila, int obj) {
    if (vazia(fila)) {
        return false;
    }
    int i = fila->frente;
    do {
        if (fila->fila[i] == obj) {
            return true;
        }
        i = (i + 1) % CAPACIDADE;
    } while (i != (fila->finalFila + 1) % CAPACIDADE);
    return false;
}
 
// Função para retornar o número de elementos atualmente na fila
int tamanho(FilaCircular* fila) {
    if (vazia(fila)) {
        return 0;
    }
    if (fila->finalFila >= fila->frente) {
        return fila->finalFila - fila->frente + 1;
    }
    return CAPACIDADE - fila->frente + fila->finalFila + 1;
}
 
// Função para adicionar valores à fila através da entrada do usuário
void adicionarValores(FilaCircular* fila) {
    int valor;
    printf("Digite os valores a serem adicionados à fila (digite -1 para parar):\n");
    while (true) {
        scanf("%d", &valor);
        if (valor == -1) break; // Para o loop se o usuário digitar -1
        enfileira(fila, valor);
    }
}
 
// Função principal para testar a implementação da Fila Circular
int main() {
    FilaCircular* fila = criaFila();
    // Adiciona valores à fila através da entrada do usuário
    adicionarValores(fila);
 
    printf("Elementos na fila: ");
    mostrarFila(fila);
 
    printf("Elemento desenfileirado: %d\n", desenfileira(fila));
    printf("Elementos na fila após desenfileirar: ");
    mostrarFila(fila);
 
    printf("Fila contém 20? %s\n", pesquisa(fila, 20) ? "Sim" : "Não");
    printf("Tamanho atual da fila: %d\n", tamanho(fila));
 
    // Libera memória
    free(fila->fila);
    free(fila);
 
    return 0;
}