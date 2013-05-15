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
%token COMP
%token RIGHT_PARENTHESIS
%token LEFT_PARENTHESIS

%{#include "lex.yy.c"%}
%%

comandos:
atribuicao | if |


valor:
ID | INT | FLOAT 
    
atribuicao:
ID ATTRIB valor ENDLINE { printf("\nComando reconhecido!\n", yytext)
                       } comandos
    
if:
    IF LEFT_PARENTHESIS valor COMP valor RIGHT_PARENTHESIS { printf("\nComando if reconhecido! %s\n", yytext)
    } comandos


%%
main(){
    
	yyparse();
}

int yyerror(char *s) {
	printf("%s\n",s);
}
