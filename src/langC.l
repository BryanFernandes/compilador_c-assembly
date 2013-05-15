/* scanner for a language C */

%{
/* need this for the call to atof() below */
#include <stdio.h>
#include <math.h>
#include "langC.tab.h"
%}

DIGIT    [0-9]

ID       [a-zA-Z][a-zA-Z0-9]*

KEYWORD  if|else|for|while|do|switch|case 

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

{KEYWORD}       {
            printf( "A keyword: %s\n", yytext );
            }

{ID}        {
             printf( "An identifier: %s\n", yytext );
            return ID;
            }

"+"|"-"|"*"|"/"   printf( "An arithmethic operator: %s\n", yytext );

"{"[^}\n]*"}"     /* eat up one-line comments */

[ \t\n]+          /* eat up whitespace */


";"         { printf("An line endpoint: %s\n", yytext);
              return   ENDLINE;

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
//como implementar tambem letras maiusculas
//como implementar atribuição que provem de uma operação matematica
//como fazer atribuição para tipos de valores diferentes, EX: string int float etc
// o que exatamente deve entrar na lista de tokens? so as reservadas?
// como fazer ele mostrar a linha que esta com erro? Implementar um contador?