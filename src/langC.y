%{
  /* A lexer for the basic grammar to use for recognizing
     English sentences. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *arq;//depuração
//arq = fopen("depuracao.asm","w");//depuração

int contKeys = 0;

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
%token <string>END_OF_FILE
%{#include "lex.yy.c"%}

%union {
  char *string;  /* string buffer */
}

%%

commands:
cmdattribuition | cmdif | cmdrk | exit

cmdrk:
RIGHT_KEY { contKeys--; printf("\n\n\tNumero de chaves abertas: %d\n\n", contKeys) } commands
    
cmdlk:
LEFT_KEY { contKeys++; printf("\n\n\tNumero de chaves abertas: %d\n\n", contKeys) }

value:
    ID | INT | FLOAT
    
    
cmdattribuition:
ID ATTRIBUITION value FINAL {
    
    printf("\n\tAtribuicao reconhecida!\n\n", yytext);
    fprintf(arq, "\nBIPUSH %s\nISTORE %s", $<string>3, $1);
    
} commands
    
cmdif:
IF LEFT_PARENTHENSIS value COMPARE value RIGHT_PARENTHENSIS cmdlk {
    
    printf("\n\tComando if reconhecido!\n\n");
    fprintf(arq, "\nILOAD %s\nBIPUSH %s\nIF_ICMPEQ L1\nL1:", $<string>3, $<string>5);
    
} commands
    
exit: END_OF_FILE
{
    yyterminate();
}
    
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
            
        arq = fopen("depuracao.asm", "w");

        yyparse();
        
        fclose(arq);
    }

yyerror(){
    return -1;
}