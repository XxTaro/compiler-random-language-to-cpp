- Analisador léxico: lexer.l
- Analisador sintático: parser.y

### Bibliotecas usadas no Linux (distro Ubuntu)
 - sudo apt install build-essential -> GCC
 - sudo apt install flex -> Flex
 - sudo apt install bison -> Bison

### Ordem de execução dos comandos:
1. Executar o comando ´flex lexer.l´ no terminal para gerar o analisador léxico definido no arquivo lexer.l
2. Executado o comando ´bison -d parser.y´ para ser gerado os arquivos parser.tab.h (com as denifições de tokens para o Flex) e parser.tab.c (com a implementação do analisador sintático)
gcc -I. parser.tab.c lex.yy.c node.c semantic/symbol_table.c -o tradutor -lfl -g