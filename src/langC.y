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
%{#include "lex.yy.c"%}
%%

comando:
ID "=" INT ";" { printf("\nComando reconhecido!\n", yytext) }

%%
main(){
    
	yyparse();
}

yyerror(){
    return -1;
}