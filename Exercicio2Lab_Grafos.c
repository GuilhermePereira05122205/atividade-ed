/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Exercicio 2 labGrafos

#include <stdio.h>
#include <stdlib.h>
 
void printMatrizAdjacencia(int n) {
    int **matriz = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }
 
    // Preenche a matriz de adjacência
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                matriz[i][j] = 1; // Existe uma aresta
            } else {
                matriz[i][j] = 0; // Não há laço
            }
        }
    }
 
    // Imprime a matriz de adjacência
    printf("Matriz de Adjacência do grafo completo K%d:\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
 
    // Libera a memória
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
}
 
void printListaAdjacencia(int n) {
    // Aloca espaço para a lista de adjacência
    int **lista = (int **)malloc(n * sizeof(int *));
    
    // Para cada vértice (n vértices), alocamos n-1 espaços
    for (int i = 0; i < n; i++) {
        lista[i] = (int *)malloc((n - 1) * sizeof(int));
        int index = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                lista[i][index] = j; // Adiciona a adjacência
                index++;
            }
        }
    }
 
    // Imprime a lista de adjacência
    printf("Lista de Adjacência do grafo completo K%d:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Vértice %d: ", i);
        for (int j = 0; j < n - 1; j++) {
            printf("%d ", lista[i][j]);
        }
        printf("\n");
    }
 
    // Libera a memória
    for (int i = 0; i < n; i++) {
        free(lista[i]);
    }
    free(lista);
}
 
int main() {
    int n;
 
    printf("Digite o número de vértices (n): ");
    scanf("%d", &n);
 
    if (n <= 0) {
        printf("O número de vértices deve ser maior que zero.\n");
        return 1;
    }
 
    printMatrizAdjacencia(n);
    printListaAdjacencia(n);
 
    return 0;
}


