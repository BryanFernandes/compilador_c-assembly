%{
  /* A lexer for the basic grammar to use for recognizing
     English sentences. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *arq;//depuração
//arq = fopen("depuracao.asm","w");//depuração

//contadores
int contKeys = 0;
int contJumps = 0;
int contParenthensis = 0;
int contPasso = 0;
int contSimbolo=0;

//variaveis para controle das passadas
#define PASSO_SIMBOLO 0;
int PASSO_FINAL = 1;



//estrutura da tabela de simbolos
typedef struct _simbolo{
    char * type;
    char * name;
    char * value;
} simbolo;
typedef struct _tabela{
    simbolo * simb;
} tabela;


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
%token <string>OPERATOR
%token <string>BREAK
%token <string>INTEGER
%token <string>FLOATING
%{#include "lex.yy.c"%}

%union {
  char *string;  /* string buffer */
}

%%

commands:
cmdattribuition | cmdif | cmdrk | cmdfor | cmdwhile | cmddowhile | cmdcase | cmdbreak | cmdswitch | cmdlp | cmdrp | cmddeclaration | exit

cmdrk:
    RIGHT_KEY {
        contKeys--;
} commands
    
cmdlk:
    LEFT_KEY {
        contKeys++;
} commands
    
cmdlp:
    LEFT_PARENTHENSIS {
        contParenthensis++;
    } commands
    
cmdrp:
    RIGHT_PARENTHENSIS {
        contParenthensis--;
    } commands
    
value:
    ID | INT | FLOAT


reservated:
    INTEGER | FLOATING

cmddeclaration:
    reservated ID FINAL {
        if(contPasso == PASSO_FINAL) {
            printf("declaração reconhecida>> PASSO SIMBOLO\n\n");
        }

    } commands


cmdattribuition:
    ID ATTRIBUITION value FINAL {
        if(contPasso == PASSO_FINAL){
            printf("\n\tAtribuicao reconhecida!\n\n", yytext);
            fprintf(arq, "\nBIPUSH %s\nISTORE %s", $<string>3, $1);
        }
    } commands

    
cmdif:
    IF LEFT_PARENTHENSIS value COMPARE value RIGHT_PARENTHENSIS cmdlk {
    
        printf("\n\tComando if reconhecido!\n\n");
        contJumps++;
        fprintf(arq, "\nILOAD %s\nBIPUSH %s\nIF_ICMPEQ L%d\nL%d:", $<string>3, $<string>5, contJumps, contJumps);
    
    } commands
    
cmdfor:
    FOR LEFT_PARENTHENSIS value ATTRIBUITION value FINAL value COMPARE value FINAL value OPERATOR OPERATOR RIGHT_PARENTHENSIS LEFT_KEY RIGHT_KEY {
    
        printf("\n\tComando for reconhecido!\n\n");
    } commands
    
cmdwhile:
    WHILE LEFT_PARENTHENSIS value COMPARE value RIGHT_PARENTHENSIS LEFT_KEY RIGHT_KEY {
    
        printf("\n\tComando while reconhecido!\n\n");
    } commands
    
cmddowhile:
    DO LEFT_KEY commands RIGHT_KEY WHILE LEFT_PARENTHENSIS value COMPARE value RIGHT_PARENTHENSIS FINAL {

        printf("\n\tComando do-while reconhecido!\n\n");
    } commands
    
cmdcase:
    CASE DEMAIS {
        printf("\n\tComando case  reconhecido!\n\n");
    } commands
    
cmdbreak:
    BREAK FINAL {
        printf("\n\tComando break reconhecido!\n\n");
    } commands
    
cmdswitch:
    SWITCH LEFT_PARENTHENSIS value RIGHT_PARENTHENSIS cmdlk {

        printf("\n\tComando switch reconhecido!\n\n");
    } commands
    
     
    
exit: END_OF_FILE
{
    switch(contPasso){
        case 1:
            printf("\n\n\tNumero de parentesis abertos: %d\n\n", contParenthensis);
            printf("\tNumero de chaves abertas: %d\n\n", contKeys);
            yyterminate();
            break;
        case 0:
            contPasso++;
            printf("PASSO>> %d\n",contPasso);
           // rewind(arq);
            //yyparse();
            yyterminate();
    }   
    

}
    
%%

main( argc, argv)
int argc;
char **argv;
    {
        ++argv, --argc;
        
        //primeiro passo
            if (argc > 0)
                yyin = fopen( argv[0], "r");
            else
                yyin = stdin;
                
            arq = fopen("depuracao.asm", "w");

            if(contPasso==0)
            yyparse();
            

        //segundo passo
            if (argc > 0)
                yyin = fopen( argv[0], "r");
            else
                yyin = stdin;
                
            if(contPasso==1)
            yyparse();
        
        fclose(arq);
    }

yyerror(){
    printf("\n\tERROR\n\n");
    return -1;
}