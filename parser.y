%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
extern char linha_atual[];

void yyerror(const char *s);
int yylex();
extern int yydebug;
%}

%define parse.trace
// Definição do tipo de valores retornados pelos tokens
%union {
    int intval;     // Para números inteiros
    char *strval;   // Para identificadores e strings
}

// Definição dos tokens e seus tipos
%token <strval> IDENTIFICADOR STRING
%token <intval> NUMERO FREQUENCIA RESOLUCAO COM
%token VAR INTEIRO TEXTO BOOLEANO CONFIG REPITA FIM LIGAR DESLIGAR
%token ESPERAR CONFIGURAR COMO CONFIGURARPWM
%token CONECTARWIFI VALOR AJUSTARPWM
%token <strval> SAIDA ENTRADA

%left '='
%left COM VALOR
%left FREQUENCIA RESOLUCAO
%left LIGAR DESLIGAR ESPERAR
%left CONFIGURAR

%type <intval> operacao_pwm operacao_io operacao_wifi operacao_controle
%type <strval> atribuicao

%%
// Estrutura do programa
programa:
    declaracoes config bloco_opt repita bloco_opt fim_opt { printf("Programa reconhecido com sucesso!\n"); }
    ;

bloco_opt:
    | bloco
    ;

// Declaração de variáveis
declaracoes:
    | declaracoes declaracao
    ;

declaracao:
    VAR INTEIRO ':' lista_identificadores ';'
    | VAR TEXTO ':' lista_identificadores ';'
    ;

lista_identificadores:
    IDENTIFICADOR
    | lista_identificadores ',' IDENTIFICADOR
    ;

// Bloco de configuração
config:
    CONFIG bloco FIM { printf("Configuração processada.\n"); }
    ;

// Bloco repetitivo (loop principal)
repita:
    REPITA bloco FIM { printf("Loop principal processado.\n"); }
    ;

// Bloco com múltiplos comandos
bloco:
    comando
    | bloco comando
    ;

// Comandos suportados
comando:
    atribuicao
    | operacao_pwm
    | operacao_io { printf("[DEBUG] Operação IO detectada\n"); }
    | operacao_wifi
    | operacao_controle
    {
        printf("[DEBUG] Próximo token esperado: verificando...\n");
    }
    ;

// Atribuição de valores
atribuicao:
    IDENTIFICADOR '=' NUMERO ';' { printf("Atribuição: %s = %d\n", $1, $3); }
    | IDENTIFICADOR '=' STRING ';' { printf("Atribuição: %s = %s\n", $1, $3); }
    ;

// Configuração de PWM e IO
operacao_pwm:
    AJUSTARPWM IDENTIFICADOR COM VALOR NUMERO ';' { printf("Ajustar PWM %s com valor %d\n", $2, $5); }
    | AJUSTARPWM IDENTIFICADOR COM VALOR IDENTIFICADOR ';' { printf("Ajustar PWM %s com valor %s\n", $2, $5); }
    | CONFIGURARPWM IDENTIFICADOR COM FREQUENCIA NUMERO RESOLUCAO NUMERO ';'
      { printf("Configurar PWM %s com frequência %d Hz e resolução %d bits\n", $2, $5, $7); }
    ;

operacao_io:
    CONFIGURAR IDENTIFICADOR COMO SAIDA ';' { 
        printf("[DEBUG] Configurar %s como saída reconhecido corretamente!\n", $2); 
    }
    | CONFIGURAR IDENTIFICADOR COMO ENTRADA ';' { 
        printf("[DEBUG] Configurar %s como entrada reconhecido corretamente!\n", $2); 
    }
    ;

operacao_wifi:
    CONECTARWIFI IDENTIFICADOR IDENTIFICADOR ';' { printf("Conectar WiFi com SSID %s e Senha %s\n", $2, $3); }
    ;

operacao_controle:
    LIGAR IDENTIFICADOR ';' { printf("Ligar: %s\n", $2); }
    | DESLIGAR IDENTIFICADOR ';' { printf("Desligar: %s\n", $2); }
    | ESPERAR NUMERO ';' { printf("Esperar: %d ms\n", $2); }
    ;

fim_opt:
    | FIM
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