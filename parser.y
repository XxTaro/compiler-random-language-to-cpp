%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

extern int yylineno;
extern char linha_atual[];

void yyerror(const char *s);
int yylex();
extern int yydebug;
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
%token CONECTARWIFI VALOR AJUSTARPWM

%left '='
%left COM VALOR
%left FREQUENCIA RESOLUCAO
%left LIGAR DESLIGAR ESPERAR
%left CONFIGURAR

%type <node> programa declaracoes declaracao bloco_opt bloco config repita fim_opt
%type <node> lista_identificadores atribuicao comando operacao_io operacao_pwm operacao_wifi operacao_controle

%%
// Estrutura do programa
programa:
    declaracoes config bloco_opt repita bloco_opt fim_opt { 
        printf("Programa reconhecido com sucesso!\n"); 
        $$ = newNode("PROGRAMA", 6, $1, $2, $3, $4, $5, $6);
        if (!$$) {
            fprintf(stderr, "Erro: árvore sintática está NULL antes de printTree!\n");
            exit(EXIT_FAILURE);
        }
        printf("[DEBUG] Árvore sintática gerada, iniciando impressão...\n");
        printTree($$, 0); // Para exibir a árvore sintática
    }
    ;

bloco_opt:
    { $$ = newNode("BLOCO_VAZIO", 0); }
    | bloco { $$ = $1; }
    ;

// Declaração de variáveis
declaracoes:
    { $$ = newNode("DECLARACOES", 0); } /* Garante um nó inicial */
    | declaracoes declaracao { addChild($1, $2); $$ = $1; }
    ;

declaracao:
    VAR INTEIRO ':' lista_identificadores ';' { 
        if (!$4) {
            printf("[ERRO] lista_identificadores retornou NULL!\n");
            $$ = newNode("DECLARACAO", 1, newNode(strdup("INTEIRO"), 0)); // Nó mínimo
        } else {
            $$ = newNode("DECLARACAO", 2, newNode(strdup("INTEIRO"), 0), $4);
        }
    }
    | VAR TEXTO ':' lista_identificadores ';' { 
        if (!$4) {
            printf("[ERRO] lista_identificadores retornou NULL!\n");
            $$ = newNode("DECLARACAO", 1, newNode(strdup("TEXTO"), 0)); // Nó mínimo
        } else {
            $$ = newNode("DECLARACAO", 2, newNode(strdup("TEXTO"), 0), $4);
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
        $$ = newNode("CONFIG", 2, $2, newNode("FIM", 0));  // Criando o nó corretamente
    }
    ;

// Bloco repetitivo (loop principal)
repita:
    REPITA bloco FIM { 
        printf("Loop principal processado.\n");
        printf("[DEBUG] Criando nó para LOOP PRINCIPAL\n");
        $$ = newNode("REPITA", 2, $2, newNode("FIM", 0));  // Criando o nó corretamente
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
    ;

// Atribuição de valores
atribuicao:
    IDENTIFICADOR '=' NUMERO ';' { 
        printf("Atribuição: %s = %d\n", $1, $3);
        char buffer[20];
        sprintf(buffer, "%d", $3); // Converte inteiro para string
        $$ = newNode("ATRIBUICAO", 2, newNode($1, 0), newNode("NUMERO", 1, newNode(strdup(buffer), 0))); 
    }
    | IDENTIFICADOR '=' STRING ';' { 
        printf("Atribuição: %s = %s\n", $1, $3);
        $$ = newNode("ATRIBUICAO", 2, newNode($1, 0), newNode("STRING", 1, newNode($3, 0))); 
    }
    ;

// Configuração de PWM e IO
operacao_pwm:
    AJUSTARPWM IDENTIFICADOR COM VALOR NUMERO ';' {
        char valorStr[16];
        sprintf(valorStr, "%d", $5);  // Converte o número para string

        $$ = newNode("AJUSTAR_PWM", 3,  
            newNode($2, 0), 
            newNode("VALOR", 1, newNode(strdup(valorStr), 0))  
        );
    }
    | AJUSTARPWM IDENTIFICADOR COM VALOR IDENTIFICADOR ';' { 
        $$ = newNode("AJUSTAR_PWM", 3, newNode($2, 0), newNode("VALOR", 1, newNode($5, 0))); 
    }
    | CONFIGURARPWM IDENTIFICADOR COM FREQUENCIA NUMERO RESOLUCAO NUMERO ';' {
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
        printf("[DEBUG] Configurar %s como saída reconhecido corretamente!\n", $2);
        $$ = newNode("CONFIGURAR_IO", 2, newNode($2, 0), newNode("SAIDA", 0)); 
    }
    | CONFIGURAR IDENTIFICADOR COMO ENTRADA ';' { 
        printf("[DEBUG] Configurar %s como entrada reconhecido corretamente!\n", $2);
        $$ = newNode("CONFIGURAR_IO", 2, newNode($2, 0), newNode("ENTRADA", 0)); 
    }
    ;

// Conexão WiFi
operacao_wifi:
    CONECTARWIFI IDENTIFICADOR IDENTIFICADOR ';' { 
        printf("Conectar WiFi com SSID %s e Senha %s\n", $2, $3);
        printf("[DEBUG] Criando nó para operação WiFi\n");
        $$ = newNode("CONECTAR_WIFI", 2, newNode($2, 0), newNode($3, 0)); 
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
    return yyparse();
}