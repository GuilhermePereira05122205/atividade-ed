#include <stdio.h>  // Inclusão da biblioteca padrão para entrada e saída (printf, scanf)

#define MAX_VERTICES 100  // Definição do número máximo de vértices para o grafo (máximo de 100)

void matrizAresta(int matriz[MAX_VERTICES][MAX_VERTICES], int n) {
    // Função que imprime as arestas do grafo com seus pesos
    
    printf("Arestas do grafo (val1, val2, peso):\n");  // Cabeçalho da lista de arestas
    // Percorre as linhas da matriz de adjacências
    for (int i = 0; i < n; i++) {
        // Percorre as colunas, mas começa de i+1 para evitar imprimir arestas duplicadas
        for (int j = i + 1; j < n; j++) {
            int peso = matriz[i][j];  // Armazena o peso da aresta entre i e j
            // Verifica se há uma aresta (peso diferente de 0)
            if (peso != 0) {
                // Imprime a aresta com o formato (vértice1, vértice2, peso)
                printf("(%d, %d, %d)\n", i, j, peso);
            }
        }
    }
}

int main() {
    int n;  // Variável para armazenar o número de vértices do grafo
    int matriz[MAX_VERTICES][MAX_VERTICES];  // Matriz de adjacências representando o grafo

    printf("Informe o número de vértices: ");  // Solicita ao usuário o número de vértices
    scanf("%d", &n);  // Lê o número de vértices

    printf("Informe a matriz de adjacências (%d x %d):\n", n, n);  // Solicita ao usuário a matriz de adjacências
    // Preenche a matriz de adjacências com os pesos das arestas
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);  // Lê o peso da aresta entre os vértices i e j
        }
    }

    matrizAresta(matriz, n);  // Chama a função para imprimir as arestas do grafo

    return 0;  // Finaliza o programa
}
