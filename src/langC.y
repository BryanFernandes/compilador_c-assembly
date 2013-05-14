%token IF
%token WHILE
%token DO
%token ELSE
%token SWITCH
%token CASE
%token FOR
%token ID
%token INT
%token FLOAT
%token DEMAIS
%token EQUALS
%{#include "lex.yy.c"%}
%%

comandos:
atribuicao | cmdif |
    
atribuicao:
ID EQUALS INT DEMAIS { printf("\n\tAtribuicao reconhecida!\n\n", yytext)
                       } comandos
    
cmdif:
IF DEMAIS ID EQUALS EQUALS INT DEMAIS { printf("\n\tComando if reconhecido!\n\n", yytext)
    } comandos
    
%%
main(){
    
	yyparse();
}

yyerror(){
    return -1;
}