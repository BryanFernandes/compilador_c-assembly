/* scanner for a language C */

%{
/* need this for the call to atof() below */
#include <stdio.h>
#include <math.h>
#include "langC.tab.h"
int cont = 0;
%}

DIGIT    [0-9]

ID       [a-zA-Z][a-zA-Z0-9]*

KEYWORD  //if|else|for|while|do|switch|case 

IF       if 
ELSE     else
FOR      for
WHILE    WHILE
DO       do
SWITCH   switch
CASE     case

%%

{DIGIT}+    {
            printf( "An integer: %s (%d)\n", yytext,
                    atoi( yytext ) );
            return INT;
            }

{DIGIT}+"."{DIGIT}*        {
            printf( "A float: %s (%g)\n", yytext,
                    atof( yytext ) );
            }

{IF}        {
            printf( "A keyword: %s\n", yytext );
            return IF;
            }
{ELSE}        {
            printf( "A keyword: %s\n", yytext );
            return ELSE;
            }

{FOR}        {
            printf( "A keyword: %s\n", yytext );
            return FOR;
            }

{WHILE}     {
            printf( "A keyword: %s\n", yytext );
            return WHILE;
            }
{DO}        {
            printf( "A keyword: %s\n", yytext );
            return DO;
            }
{SWITCH}        {
            printf( "A keyword: %s\n", yytext );
            return SWITCH;
            }

{CASE}        {
            printf( "A keyword: %s\n", yytext );
            return CASE;
            }


{ID}        {
             printf( "An identifier: %s\n", yytext );
            return ID;
            }

"+"|"-"|"*"|"/"   printf( "An arithmethic operator: %s\n", yytext );



[\n]        {cont++;
            printf( "An Line: %d\n", cont );
            }

[ \t]+          /* eat up whitespace */


";"         { printf("An line endpoint: %s\n", yytext);
              return   ENDLINE;

            }
            

"(" return(LEFT_PARENTHESIS);
")" return(RIGHT_PARENTHESIS);



"=="|"<"|">"|"!="|"<="|">=" { printf("an comparation oparator: %s\n", yytext);
                                return COMP;
                            }

"="         {
             printf("An attribution operator: %s\n", yytext);
             return ATTRIB;
            }


.           {
            printf( "Unrecognized character: %s\n", yytext );
            return DEMAIS;
            }

%%

/*main( argc, argv )
int argc;
char **argv;
    {
    ++argv, --argc;   skip over program name
    if ( argc > 0 )
            yyin = fopen( argv[0], "r" );
    else
            yyin = stdin;

    yylex();
}*/

int yywrap(void)
{ 
return 0; 
}

//o que define uma palavra reservada de outros tokens???
//como implementar atribuição que provem de uma operação matematica
//como fazer atribuição para tipos de valores diferentes, EX: string int float etc
// o que exatamente deve entrar na lista de tokens? so as reservadas?
// perguntar como tratar FIM DE LINHA e PONTO E VIRGULA
// como fazer ele mostrar a linha que esta com erro? Implementar um contador?
