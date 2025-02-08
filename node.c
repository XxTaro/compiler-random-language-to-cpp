#include "node.h"

// Cria um novo nó da árvore sintática
Node *newNode(char *label, int numChildren, ...) {
    Node *node = malloc(sizeof(Node));
    if (!node) {
        printf("[ERRO] Falha ao alocar nó\n");
        return NULL;
    }

    node->label = strdup(label);  // Duplica a string para evitar problemas de ponteiro

    node->numChildren = numChildren;
    node->children = (numChildren > 0) ? calloc(numChildren, sizeof(Node *)) : NULL;

    va_list args;
    va_start(args, numChildren);
    for (int i = 0; i < numChildren; i++) {
        node->children[i] = va_arg(args, Node *);
        if (!node->children[i]) {
            printf("[ERRO] Filho %d de %s é NULL!\n", i, label);
        }
    }
    va_end(args);

    return node;
}

// Função para imprimir a árvore sintática recursivamente
void printTree(Node *node, int depth) {
    if (node == NULL) {
        printf("[ERRO] Tentativa de imprimir um nó NULL!\n");
        return;
    }
    if (node->label == NULL || strcmp(node->label, "") == 0) {
        //printf("[ERRO] Nó em addr: %p tem label NULL ou vazio!\n", (void *)node);
        return;
    }
    printf("%*s└── %s\n", depth * 4, "", node->label);
    //printf("%*s%s (addr: %p)\n", depth * 2, "", node->label, (void *)node);

    if (node->numChildren > 0 && node->children == NULL) {
        printf("[ERRO] Nó %s tem %d filhos, mas `children` é NULL!\n", node->label, node->numChildren);
        return;
    }

    for (int i = 0; i < node->numChildren; i++) {
        if (node->children[i] == NULL) {
            printf("[ERRO] Filho %d de %s é NULL! (pai addr: %p)\n", i, node->label, (void *)node);
        } else {
            //printf("[DEBUG] Chamando printTree para filho %d de %s (addr: %p)\n", i, node->label, (void *)node->children[i]);
            printTree(node->children[i], depth + 1);
        }
    }
}

void addChild(Node *parent, Node *child) {
    if (parent == NULL || child == NULL) return;
    
    parent->numChildren++;
    parent->children = realloc(parent->children, parent->numChildren * sizeof(Node *));
    parent->children[parent->numChildren - 1] = child;
}

// Libera a memória da árvore sintática
void freeTree(Node *node) {
    if (node == NULL) return;

    for (int i = 0; i < node->numChildren; i++) {
        freeTree(node->children[i]);
    }

    free(node->children);
    free(node->label);
    free(node);
}