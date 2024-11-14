#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Estrutura para o nó da lista duplamente encadeada
typedef struct Node {
    char nome[100];
    struct Node* prev;
    struct Node* next;
} Node;

// Estrutura para a lista duplamente encadeada
typedef struct DoublyLinkedList {
    Node* head;
} DoublyLinkedList;

// Estrutura principal que gerencia o vetor de listas
typedef struct NomeManager {
    DoublyLinkedList index_array[ALPHABET_SIZE];
} NomeManager;

// Funções para a lista duplamente encadeada
DoublyLinkedList* create_list() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    return list;
}

void add_nome(DoublyLinkedList* list, const char* nome) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->nome, nome);
    new_node->prev = NULL;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        return;
    }

    Node* current = list->head;
    while (current && strcmp(current->nome, nome) < 0) {
        current = current->next;
    }

    if (current == list->head) { // inserir no começo
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    } else if (current == NULL) { // inserir no fim
        Node* tail = list->head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = new_node;
        new_node->prev = tail;
    } else { // inserir no meio
        new_node->prev = current->prev;
        new_node->next = current;
        if (current->prev) {
            current->prev->next = new_node;
        }
        current->prev = new_node;
    }
}

int search_nome(DoublyLinkedList* list, const char* nome) {
    Node* current = list->head;
    while (current) {
        if (strcmp(current->nome, nome) == 0) {
            return 1; // Nome encontrado
        }
        current = current->next;
    }
    return 0; // Nome não encontrado
}

int remove_nome(DoublyLinkedList* list, const char* nome) {
    Node* current = list->head;
    while (current) {
        if (strcmp(current->nome, nome) == 0) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                list->head = current->next; // Atualiza o head se necessário
            }
            if (current->next) {
                current->next->prev = current->prev;
            }
            free(current);
            return 1; // Remoção bem-sucedida
        }
        current = current->next;
    }
    return 0; // Nome não encontrado
}

void rename_nome(DoublyLinkedList* list, const char* old_nome, const char* new_nome) {
    if (remove_nome(list, old_nome)) {
        add_nome(list, new_nome);
    }
}

int is_empty(DoublyLinkedList* list) {
    return list->head == NULL;
}

int count(DoublyLinkedList* list) {
    int count = 0;
    Node* current = list->head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

// Funções para o NomeManager
NomeManager* create_nome_manager() {
    NomeManager* manager = (NomeManager*)malloc(sizeof(NomeManager));
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        manager->index_array[i] = *create_list();
    }
    return manager;
}

int indice(const char* nome) {
    return tolower(nome[0]) - 'a';
}

void add_nome_manager(NomeManager* manager, const char* nome) {
    int index = indice(nome);
    add_nome(&manager->index_array[index], nome);
}

int search_nome_manager(NomeManager* manager, const char* nome) {
    int index = indice(nome);
    return search_nome(&manager->index_array[index], nome);
}

int remove_nome_manager(NomeManager* manager, const char* nome) {
    int index = indice(nome);
    return remove_nome(&manager->index_array[index], nome);
}

void rename_nome_manager(NomeManager* manager, const char* old_nome, const char* new_nome) {
    int index_old = indice(old_nome);
    int index_new = indice(new_nome);
    if (index_old != index_new) {
        if (search_nome_manager(manager, old_nome)) {
            add_nome_manager(manager, new_nome);
            remove_nome_manager(manager, old_nome);
        }
    } else {
        rename_nome(&manager->index_array[index_old], old_nome, new_nome);
    }
}

int is_empty_manager(NomeManager* manager) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (!is_empty(&manager->index_array[i])) {
            return 0; // Não está vazia
        }
    }
    return 1; // Está vazia
}

int count_manager(NomeManager* manager) {
    int total_count = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        total_count += count(&manager->index_array[i]);
    }
    return total_count;
}

// Exemplo de uso
int main() {
    NomeManager* manager = create_nome_manager();

    add_nome_manager(manager, "Ana");
    add_nome_manager(manager, "Bruno");
    add_nome_manager(manager, "Carlos");

    printf("Ana existe? %d\n", search_nome_manager(manager, "Ana")); // 1
    printf("Total de nomes: %d\n", count_manager(manager)); // 3

    rename_nome_manager(manager, "Ana", "Ana Maria");
    printf("Ana Maria existe? %d\n", search_nome_manager(manager, "Ana Maria")); // 1

    remove_nome_manager(manager, "Bruno");
    printf("Total de nomes após remoção: %d\n", count_manager(manager)); // 2
    printf("Estrutura está vazia? %d\n", is_empty_manager(manager)); // 0

    // Liberação de memória
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        while (!is_empty(&manager->index_array[i])) {
            remove_nome(&manager->index_array[i], manager->index_array[i].head->nome);
        }
    }
    free(manager);

    return 0;
}