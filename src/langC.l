/* scanner for a language C */

%{
/* need this for the call to atof() below */
#include <stdio.h>
#include <math.h>
#include "langC.tab.h"
%}

DIGIT    [0-9]
ID       [a-z][a-z0-9]*
KEYWORD  else|for|while|do|switch|case 

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

if          {
            printf("A keyword: %s\n", yytext);
            return IF;
            }

{ID}        {
            printf( "An identifier: %s\n", yytext );
            return ID;
            }

"="         {
            printf("A equals: %s\n", yytext);
            return EQUALS;
            }

"+"|"-"|"*"|"/"   printf( "An operator: %s\n", yytext );

"{"[^}\n]*"}"     /* eat up one-line comments */

[ \t\n]+          /* eat up whitespace */

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