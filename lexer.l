%{
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>

#define MAX_LINHA 1024
char linha_atual[MAX_LINHA]; // Armazena a linha atual para exibir no erro
int posicao_linha = 0;  // Índice para armazenar caracteres
%}

VAR           [Vv]ar
INTEIRO       [Ii]nteiro
TEXTO         [Tt]exto
BOOLEANO      [Bb]ooleano
CONFIG        [Cc]onfig
REPITA        [Rr]epita
FIM           [Ff]im
LIGAR         [Ll]igar
DESLIGAR      [Dd]esligar
ESPERAR       [Ee]sperar
CONFIGURAR    [Cc]onfigurar
CONFIGURARPWM [Cc]onfigurarPWM
COMO          [Cc]omo
SAIDA         [Ss]aida
ENTRADA       [Ee]ntrada
FREQUENCIA    [Ff]requencia
RESOLUCAO     [Rr]esolucao
CONECTARWIFI  [Cc]onectarWifi
COM           [Cc]om
VALOR         [Vv]alor
AJUSTARPWM    [Aa]justarPWM

IDENTIFICADOR [a-zA-Z_][a-zA-Z0-9_]*
NUMERO        [0-9]+
STRING        \"(\\.|[^\\"])*\"
ESPACO        [ \t\r]+
NOVA_LINHA    \n
COMENTARIO    "//".*

%%

{ESPACO}        { /* ignora */ }
{COMENTARIO}    { /* ignora */ }
{NOVA_LINHA}    { yylineno++; }

{VAR}           return VAR;
{INTEIRO}       return INTEIRO;
{TEXTO}         return TEXTO;
{BOOLEANO}      return BOOLEANO;
{CONFIG}        return CONFIG;
{REPITA}        return REPITA;
{FIM}           return FIM;
{LIGAR}         return LIGAR;
{DESLIGAR}      return DESLIGAR;
{ESPERAR}       return ESPERAR;
{CONFIGURAR}    return CONFIGURAR;
{CONFIGURARPWM} return CONFIGURARPWM;
{COMO}          return COMO;
{ENTRADA}       return ENTRADA;
{FREQUENCIA}    return FREQUENCIA;
{RESOLUCAO}     return RESOLUCAO;
{CONECTARWIFI}  return CONECTARWIFI;
{COM}           return COM;
{VALOR}         return VALOR;
{AJUSTARPWM}    return AJUSTARPWM;

{NUMERO}       { yylval.intval = atoi(yytext); return NUMERO; }
{STRING}       { yylval.strval = strdup(yytext); return STRING; }
{SAIDA}      { printf("[DEBUG] Token SAIDA reconhecido\n"); return SAIDA; }
{IDENTIFICADOR} { yylval.strval = strdup(yytext); return IDENTIFICADOR; }

"="          return '=';
";"          return ';';
":"          return ':';
","          return ',';

. {
    if (yytext[0] == '\n') {
        linha_atual[posicao_linha] = '\0';  // Finaliza a string antes de mudar de linha
        posicao_linha = 0;  // Reseta para a próxima linha
    } else {
        if (posicao_linha < MAX_LINHA - 1) {
            linha_atual[posicao_linha++] = yytext[0];  // Adiciona caractere ao buffer
        }
    }
}

%%

int yywrap() { return 1; }