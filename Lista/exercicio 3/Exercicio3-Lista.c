/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Definindo o tamanho máximo da pilha

typedef struct {
    int *vetor;   // Vetor que armazena os elementos das duas pilhas
    int topoA;   // Índice do topo da pilha A
    int topoB;   // Índice do topo da pilha B
} Pilhas;

// Função para criar as pilhas
Pilhas* criaPilha() {
    Pilhas *p = (Pilhas*) malloc(sizeof(Pilhas));
    p->vetor = (int*) malloc(MAX * sizeof(int)); // alocando memória para o vetor
    p->topoA = -1; // Inicializa o topo A
    p->topoB = MAX; // Inicializa o topo B (MAX é o índice do último elemento do vetor)
    return p;
}

// Função para empilhar na pilha A
void empilhaA(Pilhas *p, int obj) {
    if (p->topoA + 1 < p->topoB) {
        p->vetor[++(p->topoA)] = obj;
    } else {
        printf("Pilha A cheia!\n");
    }
}

// Função para empilhar na pilha B
void empilhaB(Pilhas *p, int obj) {
    if (p->topoB - 1 > p->topoA) {
        p->vetor[--(p->topoB)] = obj;
    } else {
        printf("Pilha B cheia!\n");
    }
}

// Verifica se a pilha A está vazia
int vaziaA(Pilhas *p) {
    return p->topoA == -1;
}

// Verifica se a pilha B está vazia
int vaziaB(Pilhas *p) {
    return p->topoB == MAX;
}

// Desempilha da pilha A
int desempilhaA(Pilhas *p) {
    if (!vaziaA(p)) {
        return p->vetor[(p->topoA)--];
    } else {
        printf("Pilha A vazia!\n");
        return -1; // Retorna um valor inválido (ou poderia usar outro mecanismo de erro)
    }
}

// Desempilha da pilha B
int desempilhaB(Pilhas *p) {
    if (!vaziaB(p)) {
        return p->vetor[(p->topoB)++];
    } else {
        printf("Pilha B vazia!\n");
        return -1; // Retorna um valor inválido
    }
}

// Verifica se a pilha A está cheia
int cheiaA(Pilhas *p) {
    return p->topoA + 1 >= p->topoB;
}

// Verifica se a pilha B está cheia
int cheiaB(Pilhas *p) {
    return p->topoB - 1 <= p->topoA;
}

// Retorna o topo da pilha A
int topoA(Pilhas *p) {
    if (!vaziaA(p)) {
        return p->vetor[p->topoA];
    } else {
        printf("Pilha A vazia!\n");
        return -1; // Retorna um valor inválido
    }
}

// Retorna o topo da pilha B
int topoB(Pilhas *p) {
    if (!vaziaB(p)) {
        return p->vetor[p->topoB];
    } else {
        printf("Pilha B vazia!\n");
        return -1; // Retorna um valor inválido
    }
}

// Mostra os elementos da pilha A
void mostrarPilhaA(Pilhas *p) {
    if (vaziaA(p)) {
        printf("Pilha A vazia!\n");
        return;
    }
    printf("\n Elementos da Pilha A: \n");
    for (int i = 0; i <= p->topoA; i++) {
        printf("%d ", p->vetor[i]);
    }
    printf("\n");
}

// Mostra os elementos da pilha B
void mostrarPilhaB(Pilhas *p) {
    if (vaziaB(p)) {
        printf("Pilha B vazia!\n");
        return;
    }
    printf("Elementos da Pilha B: ");
    for (int i = MAX - 1; i >= p->topoB; i--) {
        printf("%d ", p->vetor[i]);
    }
    printf("\n");
}

// Retorna o tamanho da pilha A
int tamanhoA(Pilhas *p) {
    return p->topoA + 1;
}

// Retorna o tamanho da pilha B
int tamanhoB(Pilhas *p) {
    return MAX - p->topoB;
}

// Função principal para teste
int main() {
    Pilhas *pilhas = criaPilha();

    empilhaA(pilhas, 1);
    empilhaA(pilhas, 2);
    empilhaB(pilhas, 3);
    empilhaB(pilhas, 4);

    mostrarPilhaA(pilhas);
    mostrarPilhaB(pilhas);

    printf(" \n Desempilhando de A: %d \n", desempilhaA(pilhas));
    printf("\n Desempilhando de B: %d \n", desempilhaB(pilhas));

    mostrarPilhaA(pilhas);
    mostrarPilhaB(pilhas);

    printf("\n Tamanho A: %d \n", tamanhoA(pilhas));
    printf("\n Tamanho B: %d \n", tamanhoB(pilhas));

    free(pilhas->vetor); // Libera a memória do vetor
    free(pilhas); // Libera a memória das pilhas

    return 0;
}

