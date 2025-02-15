%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "semantic/symbol_table.h"

extern int yylineno;
extern char linha_atual[];

void yyerror(const char *s);
int yylex();
extern int yydebug;
Node *syntaxTree = NULL; 
%}

%define parse.trace

%code requires {
    #include "node.h"
}

// Definição do tipo de valores retornados pelos tokens
%union {
    int intval;     // Para números inteiros
    char *strval;   // Para identificadores e strings
    Node *node;
}

// Definição dos tokens e seus tipos
%token <strval> INTEIRO TEXTO IDENTIFICADOR STRING SAIDA ENTRADA
%token <intval> NUMERO FREQUENCIA RESOLUCAO COM
%token VAR BOOLEANO CONFIG REPITA FIM LIGAR DESLIGAR
%token ESPERAR CONFIGURAR COMO CONFIGURARPWM
%token CONECTARWIFI ENVIARHTTP VALOR AJUSTARPWM
%token CONFIGURARSERIAL ESCREVERSERIAL LERSERIAL SE ENTAO SENAO ENQUANTO
%token VERDADEIRO FALSO IGUAL DIFERENTE MENOR_QUE MAIOR_QUE MAIOR_IGUAL MENOR_IGUAL
%token SOMA SUBTRACAO MULTIPLICACAO DIVISAO

%left '='
%left COM VALOR
%left FREQUENCIA RESOLUCAO
%left LIGAR DESLIGAR ESPERAR
%left CONFIGURAR

%type <node> programa declaracoes declaracao bloco_opt bloco config repita fim_opt
%type <node> lista_identificadores atribuicao comando operacao_io operacao_pwm operacao_wifi operacao_controle operacao_serial operacao_condicional senao_opt expressao_logica
%type <node> operacoes_aritmeticas operacao_soma operacao_subtracao operacao_multiplicacao operacao_divisao

%%
// Estrutura do programa
programa:
    declaracoes config bloco_opt repita bloco_opt fim_opt { 
        printf("Programa reconhecido com sucesso!\n"); 
        syntaxTree = newNode("PROGRAMA", 6, $1, $2, $3, $4, $5, $6);
        if (!syntaxTree) {
            fprintf(stderr, "Erro: árvore sintática está NULL antes de printTree!\n");
            exit(EXIT_FAILURE);
        }
        printf("[DEBUG] Árvore sintática gerada, iniciando impressão...\n");
        printTree(syntaxTree, 0); // Para exibir a árvore sintática
    }
    ;

bloco_opt:
    { $$ = newNode("BLOCO_VAZIO", 0); }
    | bloco { $$ = $1; }
    ;

// Declaração de variáveis
declaracoes:
    { $$ = newNode("DECLARACOES", 0); }
    | declaracoes declaracao { addChild($1, $2); $$ = $1; }
    ;

declaracao:
    VAR INTEIRO ':' lista_identificadores ';' { 
        if (!$4) {
            printf("[ERRO] lista_identificadores retornou NULL!\n");
            $$ = newNode("DECLARACAO", 1, newNode(strdup("INTEIRO"), 0));
        } else {
            $$ = newNode("DECLARACAO", 2, newNode(strdup("INTEIRO"), 0), $4);
        }

        Node *idList = $4;
        while (idList != NULL) {
            if (idList->numChildren > 0 && idList->children[0] != NULL) {
                Node *identNode = idList->children[0];  
                
                char *varName = (strcmp(identNode->label, "IDENTIFICADOR") == 0 && identNode->numChildren > 0) 
                                ? identNode->children[0]->label
                                : identNode->label;
                
                if (lookupSymbol(varName) != NULL) {
                    printf("Erro Semântico: Variável '%s' já declarada!\n", varName);
                    exit(1);
                }
                insertSymbol(varName, "INTEIRO");
            }
            idList = (idList->numChildren > 1) ? idList->children[1] : NULL;
            printSymbolTable();
        }
    }
    | VAR TEXTO ':' lista_identificadores ';' { 
        if (!$4) {
            printf("[ERRO] lista_identificadores retornou NULL!\n");
            $$ = newNode("DECLARACAO", 1, newNode(strdup("TEXTO"), 0)); // Nó mínimo
        } else {
            $$ = newNode("DECLARACAO", 2, newNode(strdup("TEXTO"), 0), $4);
        }

        Node *idList = $4;
        while (idList != NULL) {
            if (idList->numChildren > 0 && idList->children[0] != NULL) {
                Node *identNode = idList->children[0];  
                
                char *varName = (strcmp(identNode->label, "IDENTIFICADOR") == 0 && identNode->numChildren > 0) 
                                ? identNode->children[0]->label  // Pegando o filho correto
                                : identNode->label;  // Já é o nome correto

                if (lookupSymbol(varName) != NULL) {
                    printf("Erro Semântico: Variável '%s' já declarada!\n", varName);
                    exit(1);
                }
                insertSymbol(varName, "TEXTO");
            }
            idList = (idList->numChildren > 1) ? idList->children[1] : NULL;
            printSymbolTable();
        }
    }
    | VAR BOOLEANO ':' lista_identificadores ';' { 
        if (!$4) {
            printf("[ERRO] lista_identificadores retornou NULL!\n");
            $$ = newNode("DECLARACAO", 1, newNode(strdup("BOOLEANO"), 0)); // Nó mínimo
        } else {
            $$ = newNode("DECLARACAO", 2, newNode(strdup("BOOLEANO"), 0), $4);
        }

        Node *idList = $4;
        while (idList != NULL) {
            if (idList->numChildren > 0 && idList->children[0] != NULL) {
                Node *identNode = idList->children[0];  
                
                char *varName = (strcmp(identNode->label, "IDENTIFICADOR") == 0 && identNode->numChildren > 0) 
                                ? identNode->children[0]->label  // Pegando o filho correto
                                : identNode->label;  // Já é o nome correto

                if (lookupSymbol(varName) != NULL) {
                    printf("Erro Semântico: Variável '%s' já declarada!\n", varName);
                    exit(1);
                }
                insertSymbol(varName, "BOOLEANO");
            }
            idList = (idList->numChildren > 1) ? idList->children[1] : NULL;
            printSymbolTable();
        }
    }
    ;

lista_identificadores:
    IDENTIFICADOR { $$ = newNode("LISTA_IDENTIFICADORES", 1, newNode("IDENTIFICADOR", 1, newNode($1, 0))); }
    | lista_identificadores ',' IDENTIFICADOR {
      addChild($1, newNode("IDENTIFICADOR", 1, newNode($3, 0)));
      $$ = $1;}
    ;

// Bloco de configuração
config:
    CONFIG bloco FIM { 
        printf("Configuração processada.\n");
        printf("[DEBUG] Criando nó CONFIG, bloco=%p\n", (void*)$2);
        $$ = newNode("CONFIG", 2, $2, newNode("FIM", 0)); 
    }
    ;

// Bloco repetitivo (loop principal)
repita:
    REPITA bloco FIM { 
        printf("Loop principal processado.\n");
        printf("[DEBUG] Criando nó para LOOP PRINCIPAL\n");
        $$ = newNode("REPITA", 2, $2, newNode("FIM", 0));
    }
    ;

// Bloco com múltiplos comandos
bloco:
    comando { $$ = newNode("BLOCO", 1, $1); }
    | bloco comando { 
        addChild($1, $2);
        $$ = $1;
    }
    ;

// Comandos suportados
comando:
    atribuicao { $$ = $1; }
    | operacao_pwm { $$ = $1; }
    | operacao_io { $$ = $1; }
    | operacao_wifi { $$ = $1; }
    | operacao_controle { $$ = $1; }
    | operacao_serial { $$ = $1; }
    | operacao_condicional { $$ = $1; }
    | operacoes_aritmeticas { $$ = $1; }
    ;

// Atribuição de valores
atribuicao:
    IDENTIFICADOR '=' NUMERO ';' { 
        checkVariableType($1, "INTEIRO");
        printf("Atribuição: %s = %d\n", $1, $3);
        char buffer[20];
        sprintf(buffer, "%d", $3); // Converte inteiro para string
        $$ = newNode("ATRIBUICAO", 2, newNode($1, 0), newNode("NUMERO", 1, newNode(strdup(buffer), 0))); 
    }
    | IDENTIFICADOR '=' STRING ';' { 
        checkVariableType($1, "TEXTO");
        printf("Atribuição: %s = %s\n", $1, $3);
        $$ = newNode("ATRIBUICAO", 2, newNode($1, 0), newNode("STRING", 1, newNode($3, 0))); 
    }
    | IDENTIFICADOR '=' VERDADEIRO ';' { 
        checkVariableType($1, "BOOLEANO");
        printf("Atribuição: %s = VERDADEIRO\n", $1);
        $$ = newNode("ATRIBUICAO", 2, newNode($1, 0), newNode("BOOLEANO", 1, newNode("VERDADEIRO", 0))); 
    }
    | IDENTIFICADOR '=' FALSO ';' { 
        checkVariableType($1, "BOOLEANO");
        printf("Atribuição: %s = FALSO\n", $1);
        $$ = newNode("ATRIBUICAO", 2, newNode($1, 0), newNode("BOOLEANO", 1, newNode("FALSO", 0))); 
    }
    | IDENTIFICADOR '=' expressao_logica ';' { 
        checkVariableType($1, "BOOLEANO");
        $$ = newNode("ATRIBUICAO", 2, newNode($1, 0), $3); 
    }
    ;

// Configuração de PWM e IO
operacao_pwm:
    AJUSTARPWM IDENTIFICADOR COM VALOR NUMERO ';' {
        checkVariableType($2, "INTEIRO");
        char valorStr[16];
        sprintf(valorStr, "%d", $5);  // Converte o número para string

        $$ = newNode("AJUSTAR_PWM", 3,  
            newNode($2, 0), 
            newNode("VALOR", 1, newNode(strdup(valorStr), 0))  
        );
    }
    | AJUSTARPWM IDENTIFICADOR COM VALOR IDENTIFICADOR ';' { 
        checkVariableType($2, "INTEIRO");
        checkVariableType($5, "INTEIRO");
        $$ = newNode("AJUSTAR_PWM", 3, newNode($2, 0), newNode("VALOR", 1, newNode($5, 0))); 
    }
    | CONFIGURARPWM IDENTIFICADOR COM FREQUENCIA NUMERO RESOLUCAO NUMERO ';' {
        checkVariableType($2, "INTEIRO");
        char freqStr[16], resStr[16];
        sprintf(freqStr, "%d", $5);  // Converte o número para string
        sprintf(resStr, "%d", $7);   // Converte o número para string
    
        $$ = newNode("CONFIGURAR_PWM", 3,  
            newNode($2, 0), 
            newNode("FREQUENCIA", 1, newNode(strdup(freqStr), 0)),  
            newNode("RESOLUCAO", 1, newNode(strdup(resStr), 0))  
        );
    }

// Operação de entrada e saída
operacao_io:
    CONFIGURAR IDENTIFICADOR COMO SAIDA ';' { 
        checkVariableType($2, "INTEIRO");
        printf("[DEBUG] Configurar %s como saída reconhecido corretamente!\n", $2);
        $$ = newNode("CONFIGURAR_IO", 2, newNode($2, 0), newNode("SAIDA", 0)); 
    }
    | CONFIGURAR IDENTIFICADOR COMO ENTRADA ';' { 
        checkVariableType($2, "INTEIRO");
        printf("[DEBUG] Configurar %s como entrada reconhecido corretamente!\n", $2);
        $$ = newNode("CONFIGURAR_IO", 2, newNode($2, 0), newNode("ENTRADA", 0)); 
    }
    | LIGAR IDENTIFICADOR ';' { 
        checkVariableType($2, "INTEIRO");
        $$ = newNode("LIGAR", 1, newNode($2, 0)); 
    }
    | DESLIGAR IDENTIFICADOR ';' { 
        checkVariableType($2, "INTEIRO");
        $$ = newNode("DESLIGAR", 1, newNode($2, 0)); 
    }
    ;

// Conexão WiFi
operacao_wifi:
    CONECTARWIFI IDENTIFICADOR IDENTIFICADOR ';' { 
        checkVariableType($2, "TEXTO");
        checkVariableType($3, "TEXTO");
        printf("Conectar WiFi com SSID %s e Senha %s\n", $2, $3);
        printf("[DEBUG] Criando nó para operação WiFi\n");
        $$ = newNode("CONECTAR_WIFI", 2, newNode($2, 0), newNode($3, 0)); 
    }
    | ENVIARHTTP STRING STRING ';' {
         $$ = newNode("ENVIAR_HTTP", 2, newNode($2, 0), newNode($3, 0));
    }
    ;

operacao_serial:
    CONFIGURARSERIAL NUMERO ';' {
        if ($2 < 300 || $2 > 115200) {
            printf("Erro Semântico: Taxa de transmissão inválida '%d'. Deve estar entre 300 e 115200.\n", $2);
            exit(1);
        }
        char buffer[10];
        sprintf(buffer, "%d", $2);
        $$ = newNode("CONFIGURAR_SERIAL", 1, newNode(strdup(buffer), 0)); 
    }
    | ESCREVERSERIAL STRING ';' {
        $$ = newNode("ESCREVER_SERIAL", 1, newNode($2, 0));
    }
    | IDENTIFICADOR '=' LERSERIAL ';' {
        checkVariableType($1, "TEXTO");
        $$ = newNode("LER_SERIAL", 1, newNode($1, 0));
    }
    ;

// Operações de controle
operacao_controle:
    ESPERAR NUMERO ';' { 
        printf("Esperar: %d ms\n", $2);
        char buffer[20];
        sprintf(buffer, "%d", $2);
        $$ = newNode("ESPERAR", 1, newNode(strdup(buffer), 0)); 
    }
    ;

fim_opt:
    { $$ = newNode("FIM_VAZIO", 0); }
    | FIM { $$ = newNode("FIM", 0); }
    ;

operacao_condicional:
    SE expressao_logica ENTAO bloco senao_opt FIM {
        printf("Estrutura Condicional (se ... então ... fim)\n");
        $$ = newNode("CONDICIONAL", 3, $2, $4, $5, 0);
    }
    | ENQUANTO bloco FIM {
        printf("Estrutura de Repetição (enquanto ... fim)\n");
        $$ = newNode("ENQUANTO", 1, $2, 0);
    }
    ;

senao_opt:
    { $$ = newNode("SENAO_VAZIO", 0); }
    | SENAO bloco { $$ = newNode("SENAO", 1, $2, 0); }
    ;

expressao_logica:
    IDENTIFICADOR {
        checkVariableType($1, "BOOLEANO");

        $$ = newNode("EXPRESSAO_LOGICA", 1, newNode($1, 0));
    }
    | IDENTIFICADOR IGUAL NUMERO {
        printf("Comparação: %s == %d\n", $1, $3);

        checkVariableType($1, "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", $3);
        $$ = newNode("EXPRESSAO_LOGICA", 3, newNode($1, 0), newNode("==", 0), newNode(valorStr, 0));
    }
    | IDENTIFICADOR DIFERENTE NUMERO {
        printf("Comparação: %s == %d\n", $1, $3);

        checkVariableType($1, "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", $3);
        $$ = newNode("EXPRESSAO_LOGICA", 3, newNode($1, 0), newNode("!=", 0), newNode(valorStr, 0));
    }
    | IDENTIFICADOR MENOR_QUE NUMERO {
        printf("Comparação: %s == %d\n", $1, $3);

        checkVariableType($1, "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", $3);
        $$ = newNode("EXPRESSAO_LOGICA", 3, newNode($1, 0), newNode("<", 0), newNode(valorStr, 0));
    }
    | IDENTIFICADOR MAIOR_QUE NUMERO {
        printf("Comparação: %s == %d\n", $1, $3);

        checkVariableType($1, "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", $3);
        $$ = newNode("EXPRESSAO_LOGICA", 3, newNode($1, 0), newNode(">", 0), newNode(valorStr, 0));
    }
    | IDENTIFICADOR MAIOR_IGUAL NUMERO {
        printf("Comparação: %s == %d\n", $1, $3);

        checkVariableType($1, "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", $3);
        $$ = newNode("EXPRESSAO_LOGICA", 3, newNode($1, 0), newNode(">=", 0), newNode(valorStr, 0));
    }
    | IDENTIFICADOR MENOR_IGUAL NUMERO {
        printf("Comparação: %s == %d\n", $1, $3);

        checkVariableType($1, "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", $3);
        $$ = newNode("EXPRESSAO_LOGICA", 3, newNode($1, 0), newNode("<=", 0), newNode(valorStr, 0));
    }
    | IDENTIFICADOR IGUAL STRING {
        printf("Comparação: %s == %s\n", $1, $3);

        checkVariableType($1, "TEXTO");

        $$ = newNode("EXPRESSAO_LOGICA", 3, newNode($1, 0), newNode("==", 0), newNode($3, 0));
    }
    ;

operacoes_aritmeticas:
    operacao_soma { $$ = $1;}
    | operacao_subtracao { $$ = $1;}
    | operacao_multiplicacao { $$ = $1;}
    | operacao_divisao { $$ = $1;}

operacao_soma:
    IDENTIFICADOR SOMA IDENTIFICADOR {
        checkVariableType($1, "INTEIRO");
        checkVariableType($3, "INTEIRO");

        $$ = newNode("OPERACAO_SOMA", 3, newNode($1, 0), newNode("+", 0), newNode($3, 0));
    }
    | IDENTIFICADOR SOMA NUMERO {
        checkVariableType($1, "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", $3);

        $$ = newNode("OPERACAO_SOMA", 3, newNode($1, 0), newNode("+", 0), newNode(valorStr, 0));
    }
    | NUMERO SOMA IDENTIFICADOR {
        checkVariableType($3, "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", $1);

        $$ = newNode("OPERACAO_SOMA", 3, newNode(valorStr, 0), newNode("+", 0), newNode($3, 0));
    }
    | NUMERO SOMA NUMERO {
        char valorStr1[16];
        char valorStr2[16];
        sprintf(valorStr1, "%d", $1);
        sprintf(valorStr1, "%d", $3);

        $$ = newNode("OPERACAO_SOMA", 3, newNode(valorStr1, 0), newNode("+", 0), newNode(valorStr2, 0));
    }
    ;

operacao_subtracao:
    IDENTIFICADOR SUBTRACAO IDENTIFICADOR {
        checkVariableType($1, "INTEIRO");
        checkVariableType($3, "INTEIRO");

        $$ = newNode("OPERACAO_SUBTRACAO", 3, newNode($1, 0), newNode("-", 0), newNode($3, 0));
    }
    | IDENTIFICADOR SUBTRACAO NUMERO {
        checkVariableType($1, "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", $3);

        $$ = newNode("OPERACAO_SUBTRACAO", 3, newNode($1, 0), newNode("-", 0), newNode(valorStr, 0));
    }
    | NUMERO SUBTRACAO IDENTIFICADOR {
        checkVariableType($3, "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", $1);

        $$ = newNode("OPERACAO_SUBTRACAO", 3, newNode(valorStr, 0), newNode("-", 0), newNode($3, 0));
    }
    | NUMERO SUBTRACAO NUMERO {
        char valorStr1[16];
        char valorStr2[16];
        sprintf(valorStr1, "%d", $1);
        sprintf(valorStr1, "%d", $3);

        $$ = newNode("OPERACAO_SUBTRACAO", 3, newNode(valorStr1, 0), newNode("-", 0), newNode(valorStr2, 0));
    }
    ;

operacao_multiplicacao:
    IDENTIFICADOR MULTIPLICACAO IDENTIFICADOR {
        checkVariableType($1, "INTEIRO");
        checkVariableType($3, "INTEIRO");

        $$ = newNode("OPERACAO_MULTIPLICACAO", 3, newNode($1, 0), newNode("*", 0), newNode($3, 0));
    }
    | IDENTIFICADOR MULTIPLICACAO NUMERO {
        checkVariableType($1, "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", $3);

        $$ = newNode("OPERACAO_MULTIPLICACAO", 3, newNode($1, 0), newNode("*", 0), newNode(valorStr, 0));
    }
    | NUMERO MULTIPLICACAO IDENTIFICADOR {
        checkVariableType($3, "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", $1);

        $$ = newNode("OPERACAO_MULTIPLICACAO", 3, newNode(valorStr, 0), newNode("*", 0), newNode($3, 0));
    }
    | NUMERO MULTIPLICACAO NUMERO {
        char valorStr1[16];
        char valorStr2[16];
        sprintf(valorStr1, "%d", $1);
        sprintf(valorStr1, "%d", $3);

        $$ = newNode("OPERACAO_MULTIPLICACAO", 3, newNode(valorStr1, 0), newNode("*", 0), newNode(valorStr2, 0));
    }
    ;

operacao_divisao:
    IDENTIFICADOR DIVISAO IDENTIFICADOR {
        checkVariableType($1, "INTEIRO");
        checkVariableType($3, "INTEIRO");

        $$ = newNode("OPERACAO_DIVISAO", 3, newNode($1, 0), newNode("/", 0), newNode($3, 0));
    }
    | IDENTIFICADOR DIVISAO NUMERO {
        checkVariableType($1, "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", $3);

        $$ = newNode("OPERACAO_DIVISAO", 3, newNode($1, 0), newNode("/", 0), newNode(valorStr, 0));
    }
    | NUMERO DIVISAO IDENTIFICADOR {
        checkVariableType($3, "INTEIRO");

        char valorStr[16];
        sprintf(valorStr, "%d", $1);

        $$ = newNode("OPERACAO_DIVISAO", 3, newNode(valorStr, 0), newNode("/", 0), newNode($3, 0));
    }
    | NUMERO DIVISAO NUMERO {
        char valorStr1[16];
        char valorStr2[16];
        sprintf(valorStr1, "%d", $1);
        sprintf(valorStr2, "%d", $3);

        $$ = newNode("OPERACAO_DIVISAO", 3, newNode(valorStr1, 0), newNode("/", 0), newNode(valorStr2, 0));
    }
    ;

%%
void yyerror(const char *s) {
    fprintf(stderr, "Erro sintático na linha %d: %s\n", yylineno - 1, s);

    // Abrir o arquivo de entrada novamente para ler a linha do erro
    FILE *arquivo = fopen("entrada.txt", "r"); // Certifique-se de que está correto
    if (arquivo) {
        char linha[1024];
        int linha_atual = 1;

        while (fgets(linha, sizeof(linha), arquivo)) {
            if (linha_atual == yylineno - 1) {  // A linha do erro
                fprintf(stderr, ">> %s", linha);
                break;
            }
            linha_atual++;
        }
        fclose(arquivo);
    } else {
        fprintf(stderr, ">> [Erro ao abrir arquivo]\n");
    }
}

int main() {
    yydebug = 0;

    if (yyparse() != 0) {
        fprintf(stderr, "[ERRO] Falha na análise sintática.\n");
        return EXIT_FAILURE;
    }

    if (syntaxTree == NULL) {
        fprintf(stderr, "[ERRO] Árvore sintática não foi gerada corretamente!\n");
        return EXIT_FAILURE;
    }

    printf("[DEBUG] Gerando código C++...\n");

    // Abrir o arquivo de saída para C++
    FILE *cppFile = fopen("output/saida.cpp", "w");
    if (!cppFile) {
        perror("[ERRO] Não foi possível criar o arquivo de saída");
        return EXIT_FAILURE;
    }

    generateFinalCppCode(syntaxTree, cppFile);
    fclose(cppFile);

    printf("[SUCESSO] Código C++ gerado em 'saida.cpp'.\n");

    return 0;
}