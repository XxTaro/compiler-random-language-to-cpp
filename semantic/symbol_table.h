#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um símbolo na tabela de símbolos
typedef struct Symbol {
    char *name;    // Nome da variável
    char *type;    // Tipo da variável (inteiro, texto, etc.)
    struct Symbol *next; // Ponteiro para o próximo símbolo (lista encadeada)
} Symbol;

// Cabeçalho das funções
void insertSymbol(char *name, char *type);
Symbol *lookupSymbol(char *name);
void checkVariablesDeclared(int count, ...);
void checkVariableType(char *name, const char *expectedType);
void printSymbolTable();

#endif
