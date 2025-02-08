#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>  // Para lidar com argumentos variáveis

// Estrutura do nó da árvore sintática
typedef struct Node {
    char *label;            // Nome do nó (ex: "ATRIBUICAO")
    struct Node **children; // Ponteiro para filhos
    int numChildren;        // Número de filhos
} Node;

// Funções para manipular a árvore sintática
Node *newNode(char *label, int numChildren, ...);
void printTree(Node *node, int depth);
void freeTree(Node *node);

#endif
