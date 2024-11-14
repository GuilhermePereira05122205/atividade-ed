/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void imprimirMatrizAdjacencias(int n, int matriz[n][n]) {
    printf("Matriz de Adjacências:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void imprimirListaAdjacencias(int n, int lista[n][n], int grau[n]) {
    printf("Lista de Adjacências:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < grau[i]; j++) {
            printf("%d ", lista[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    
    // Entrada do número de vértices
    printf("Digite o número de vértices: ");
    scanf("%d", &n);

    // Validação da entrada
    if (n <= 0) {
        printf("O número de vértices deve ser maior que zero.\n");
        return 1;
    }

    // Criação da matriz de adjacências
    int matriz[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matriz[i][j] = 0; // Não há laços em um grafo completo
            } else {
                matriz[i][j] = 1; // Há uma aresta entre cada par de vértices
            }
        }
    }

    // Criação da lista de adjacências
    int lista[n][n];
    int grau[n];
    for (int i = 0; i < n; i++) {
        grau[i] = 0; // Inicializa o grau de cada vértice
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                lista[i][grau[i]] = j; // Adiciona j à lista de adjacências de i
                grau[i]++;
            }
        }
    }

    // Impressão da matriz e lista de adjacências
    imprimirMatrizAdjacencias(n, matriz);
    imprimirListaAdjacencias(n, lista, grau);

    return 0;
}
