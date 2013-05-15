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
%token ENDLINE
%token ATTRIB
%{#include "lex.yy.c"%}
%%

comandos:
atribuicao | /*if |*/
    
atribuicao:
ID ATTRIB INT ENDLINE { printf("\nComando reconhecido!\n", yytext)
                       } comandos
    
/*if:
    IF DEMAIS ID DEMAIS DEMAIS INT DEMAIS { printf("\nComando if reconhecido!\n", yytext)
    } comandos*/
    
%%
main(){
    
	yyparse();
}

int yyerror(char *s) {
	printf("%s\n",s);
}
