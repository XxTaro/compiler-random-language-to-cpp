#include "node.h"

// Cria um novo nó da árvore sintática
Node *newNode(char *label, int numChildren, ...) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->label = strdup(label);
    node->numChildren = numChildren;
    node->children = (Node **)malloc(numChildren * sizeof(Node *));

    va_list args;
    va_start(args, numChildren);
    for (int i = 0; i < numChildren; i++) {
        node->children[i] = va_arg(args, Node *);
    }
    va_end(args);

    return node;
}

// Função para imprimir a árvore sintática recursivamente
void printTree(Node *node, int depth) {
    if (node == NULL) return;

    for (int i = 0; i < depth; i++) printf("  "); // Indentação
    printf("%s\n", node->label);

    for (int i = 0; i < node->numChildren; i++) {
        printTree(node->children[i], depth + 1);
    }
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
