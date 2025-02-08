## Analisador léxico: lexer.l
## Analisador sintático: parser.y

### Ordem de execução dos comandos:
1. Criado o arquivo lexer.l contendo todas as palavras chaves, números, identificadores e operadores da linguagem personalizada.
2. Executado o comando ´flex lexer.l´ no terminal
3. Criado o arquivo parser.tab.h vazio
4. Criado o arquivo parser.y, que define os token corretamentes
5. Executado o comando ´bison -d parser.y´ para ser gerado os arquivos parser.tab.h (com as denifições de tokens para o Flex) e parser.tab.c (com a implementação do analisador sintático)
6. 