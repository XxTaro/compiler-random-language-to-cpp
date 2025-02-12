#include "symbol_table.h"

// Ponteiro global para a tabela de símbolos (lista encadeada)
Symbol *symbolTable = NULL;

// Insere um novo símbolo na tabela
void insertSymbol(char *name, char *type) {
    // Verifica se a variável já foi declarada
    if (lookupSymbol(name) != NULL) {
        printf("Erro Semântico: Variável '%s' já declarada!\n", name);
        exit(1);
    }

    // Cria um novo símbolo
    Symbol *newSymbol = (Symbol *)malloc(sizeof(Symbol));
    newSymbol->name = strdup(name);
    newSymbol->type = strdup(type);
    newSymbol->next = symbolTable;
    symbolTable = newSymbol;

    printf("[DEBUG] Variável '%s' do tipo '%s' adicionada à tabela de símbolos.\n", name, type);
}

// Busca um símbolo na tabela
Symbol *lookupSymbol(char *name) {
    Symbol *current = symbolTable;
    while (current) {
        if (strcmp(current->name, name) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}

void checkVariableType(char *name, const char *expectedType) {
    Symbol *symbol = lookupSymbol(name);
    if (symbol == NULL) {|
        printf("Erro Semântico: Variável '%s' não foi declarada antes do uso.\n", name);
        exit(1);
    }

    if (strcmp(symbol->type, expectedType) != 0) {
        printf("Erro Semântico: Variável '%s' esperava tipo '%s', mas foi usada com tipo '%s'.\n",
               name, expectedType, symbol->type);
        exit(1);
    }
}

// Imprime todos os símbolos armazenados (para depuração)
void printSymbolTable() {
    printf("\n[DEBUG] Tabela de Símbolos:\n");
    printf("----------------------------\n");
    Symbol *current = symbolTable;
    while (current) {
        printf("Nome: '%s', Tipo: %s\n", current->name, current->type);
        current = current->next;
    }
    printf("----------------------------\n");
}
