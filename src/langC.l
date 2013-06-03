/* scanner for a language C */

%{
/* need this for the call to atof() below */
#include <stdio.h>
#include <math.h>
#include "langC.tab.h"
#include <string.h>
extern YYSTYPE yylval;
int cont = 0;
%}

DIGIT    [0-9]
ID       [a-zA-Z][a-zA-Z0-9]*
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
            return FLOAT;
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

"="         {
                printf("A equals: %s\n", yytext);
                return ATTRIBUITION;
            }

"=="|"<="|">="|"!="|"<"|">" {
                        printf("A compare: %s\n", yytext);
                        return COMPARE;
                    }

"("         {
                printf("A Left Parenthesis: %s\n", yytext);
                return LEFT_PARENTHENSIS;
            }

")" {
    printf("A Right Parenthesis: %s\n", yytext);
    return RIGHT_PARENTHENSIS;
}

"{" {
    printf("A left key: %s\n", yytext);
    return LEFT_KEY;
}

"}" {
    printf("A right key: %s\n", yytext);
    return RIGHT_KEY;
}

";" {
    printf("A final: %s\n", yytext);
    return FINAL;
}


"\"" {
    printf("A ASP: %s\n", yytext);
    yylval.string = strdup(yytext);
    return ASP;
}

"+"|"-"|"*"|"/"   printf( "An operator: %s\n", yytext );

[ \t]+          /* eat up whitespace */

[\n]        {cont++;
    printf( "A Line: %d\n", cont );
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