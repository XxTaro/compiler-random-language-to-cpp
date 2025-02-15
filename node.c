#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int insideSetup = 0;
static int insideLoop = 0;
static int configProcessed = 0;

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

void generateFinalCppCode(Node *node, FILE *file) {
    generateCppCode(node, file, 0);
}

void printIndent(FILE *file, int indentLevel) {
    for (int i = 0; i < indentLevel; i++) {
        fprintf(file, "    "); // 4 espaços por nível de indentação
    }
}

void generateCppCode(Node *node, FILE *file, int indentLevel) {
    if (node == NULL) return;

    static int configProcessed = 0;
    static int declarationsProcessed = 0;

    // PROGRAMA (Estrutura Principal)
    if (strcmp(node->label, "PROGRAMA") == 0) {
        printf("[DEBUG] Entrou no token PROGRAMA\n");

        fprintf(file, "#include <Arduino.h>\n");
        fprintf(file, "#include <WiFi.h>\n\n");

        // Declarações globais antes do setup
        generateCppCode(node->children[0], file, 0);
        fprintf(file, "\n");

        // Setup (Configurações)
        fprintf(file, "void setup() {\n");
        generateCppCode(node->children[1], file, 1);
        fprintf(file, "}\n\n");

        // Loop principal
        fprintf(file, "void loop() {\n");
        generateCppCode(node->children[3], file, 1);
        fprintf(file, "}\n");

        return;
    }

    // DECLARAÇÕES DE VARIÁVEIS
    else if (strcmp(node->label, "DECLARACOES") == 0) {
        if (declarationsProcessed) return;
        declarationsProcessed = 1;

        printf("[DEBUG] Entrou no token DECLARACOES\n");

        for (int i = 0; i < node->numChildren; i++) {
            generateCppCode(node->children[i], file, 0);
        }
        return;
    }

    // INDIVIDUALMENTE DECLARAÇÃO
    else if (strcmp(node->label, "DECLARACAO") == 0) {
        printf("[DEBUG] Entrou no token DECLARACAO\n");

        char *tipo = "";
        if (strcmp(node->children[0]->label, "INTEIRO") == 0) tipo = "int";
        else if (strcmp(node->children[0]->label, "TEXTO") == 0) tipo = "String";
        else if (strcmp(node->children[0]->label, "BOOLEANO") == 0) tipo = "bool";

        Node *idList = node->children[1];
        while (idList != NULL && idList->numChildren > 0) {
            Node *identNode = idList->children[0];
            char *varName = (strcmp(identNode->label, "IDENTIFICADOR") == 0 && identNode->numChildren > 0)
                            ? identNode->children[0]->label
                            : identNode->label;

            if (varName != NULL) {
                printf("[DEBUG] Declarando variável: %s %s;\n", tipo, varName);
                fprintf(file, "%s %s;\n", tipo, varName);
            }

            idList = (idList->numChildren > 1) ? idList->children[1] : NULL;
        }
    }

    // CONFIGURAÇÕES (Dentro do setup)
    else if (strcmp(node->label, "CONFIG") == 0) {
        if (configProcessed) return;
        configProcessed = 1;

        printf("[DEBUG] Entrou no token CONFIG\n");
        generateCppCode(node->children[0], file, indentLevel);
        return;
    }

    // ATRIBUIÇÕES (Dentro do setup ou loop)
    else if (strcmp(node->label, "ATRIBUICAO") == 0) {
        printIndent(file, indentLevel);
        fprintf(file, "%s = %s;\n", node->children[0]->label, node->children[1]->children[0]->label);
        return;
    }

    // CONFIGURAÇÃO DE PINOS
    else if (strcmp(node->label, "CONFIGURAR_IO") == 0) {
        printIndent(file, indentLevel);
        fprintf(file, "pinMode(%s, %s);\n", node->children[0]->label,
                strcmp(node->children[1]->label, "SAIDA") == 0 ? "OUTPUT" : "INPUT");
        return;
    }

    // PWM
    else if (strcmp(node->label, "CONFIGURAR_PWM") == 0) {
        printIndent(file, indentLevel);
        fprintf(file, "ledcSetup(0, %s, %s);\n",
                node->children[1]->children[0]->label, node->children[2]->children[0]->label);
        printIndent(file, indentLevel);
        fprintf(file, "ledcAttachPin(%s, 0);\n", node->children[0]->label);
        return;
    }

    // AJUSTE PWM
    else if (strcmp(node->label, "AJUSTAR_PWM") == 0) {
        printIndent(file, indentLevel);
        fprintf(file, "analogWrite(%s, %s);\n", node->children[0]->label, node->children[1]->children[0]->label);
        return;
    }

    // CONECTAR WIFI
    else if (strcmp(node->label, "CONECTAR_WIFI") == 0) {
        printIndent(file, indentLevel);
        fprintf(file, "WiFi.begin(%s, %s);\n", node->children[0]->label, node->children[1]->label);
        return;
    }

    // LIGAR/DESLIGAR PINOS
    else if (strcmp(node->label, "LIGAR") == 0) {
        printIndent(file, indentLevel);
        fprintf(file, "digitalWrite(%s, HIGH);\n", node->children[0]->label);
        return;
    }
    else if (strcmp(node->label, "DESLIGAR") == 0) {
        printIndent(file, indentLevel);
        fprintf(file, "digitalWrite(%s, LOW);\n", node->children[0]->label);
        return;
    }

    // ATRASO (DELAY)
    else if (strcmp(node->label, "ESPERAR") == 0) {
        printIndent(file, indentLevel);
        fprintf(file, "delay(%s);\n", node->children[0]->label);
        return;
    }

    // ESTRUTURA CONDICIONAL
    else if (strcmp(node->label, "CONDICIONAL") == 0) {
        printIndent(file, indentLevel);
        fprintf(file, "if (%s) {\n", node->children[0]->children[0]->label);
        generateCppCode(node->children[1], file, indentLevel + 1);
        printIndent(file, indentLevel);
        fprintf(file, "}\n");

        if (node->numChildren > 2) {
            printIndent(file, indentLevel);
            fprintf(file, "else {\n");
            generateCppCode(node->children[2], file, indentLevel + 1);
            printIndent(file, indentLevel);
            fprintf(file, "}\n");
        }
        return;
    }

    // LOOP ENQUANTO
    else if (strcmp(node->label, "ENQUANTO") == 0) {
        printIndent(file, indentLevel);
        fprintf(file, "while (true) {\n");
        generateCppCode(node->children[0], file, indentLevel + 1);
        printIndent(file, indentLevel);
        fprintf(file, "}\n");
        return;
    }

    // Percorre os filhos restantes
    for (int i = 0; i < node->numChildren; i++) {
        generateCppCode(node->children[i], file, indentLevel);
    }
}