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
%token LEFT_PARENTHENSIS
%token RIGHT_PARENTHENSIS
%token FINAL
%token ATTRIBUITION
%token COMPARE
%token LEFT_KEY
%token RIGHT_KEY
%{#include "lex.yy.c"%}
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