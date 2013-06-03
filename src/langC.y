%{
  /* A lexer for the basic grammar to use for recognizing
     English sentences. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *arq;//depuração
//arq = fopen("depuração.html","w");//depuração  

%}


%token <string>IF
%token <string>WHILE
%token <string>DO
%token <string>ELSE
%token <string>SWITCH
%token <string>CASE
%token <string>FOR
%token <string>ID
%token <string>INT
%token <string>FLOAT
%token <string>DEMAIS
%token <string>EQUALS
%token <string>LEFT_PARENTHENSIS
%token <string>RIGHT_PARENTHENSIS
%token <string>FINAL
%token <string>ATTRIBUITION
%token <string>COMPARE
%token <string>LEFT_KEY
%token <string>RIGHT_KEY
%token <string>ASP
%{#include "lex.yy.c"%}

%union {
  char *string;  /* string buffer */
}

%%

commands:
cmdattribuition | cmdif |
    
//command:
//cmdattribuition | cmdif
    
cmdkey:
LEFT_KEY commands RIGHT_KEY
    
value:
ID | INT | FLOAT
    
cmdattribuition:
ID ATTRIBUITION value FINAL { printf("\n\tAtribuicao reconhecida!\n\n", yytext)
                       } commands
    
cmdif:
IF LEFT_PARENTHENSIS value COMPARE value RIGHT_PARENTHENSIS cmdkey { printf("\n\tComando if reconhecido!\n\n", yytext)
    } commands
    
%%
main( argc, argv)
int argc;
char **argv;
    {
        ++argv, --argc;
        if (argc > 0)
            yyin = fopen( argv[0], "r");
        else
            yyin = stdin;
        yyparse();
    }

yyerror(){
    return -1;
}