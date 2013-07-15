%{
  /* A lexer for the basic grammar to use for recognizing
     English sentences. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *arq;//depuração
//arq = fopen("depuracao.asm","w");//depuração

//contadores
int contKeys = 0;
int contJumps = 0;
int contParenthensis = 0;
int contPasso = 0;
int contSimbolo=0;

//variaveis para controle das passadas
int PASSO_SIMBOLO = 0;
int PASSO_DEFINE = 1;
int PASSO_MAIN = 2;
int PASSO_LIMPA = 3;
int PASSO_FINAL = 4;



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
%token <string>MAIN
%token <string>DEFINE
%{#include "lex.yy.c"%}

%union {
  char *string;  /* string buffer */
}

%%

commands:
    cmdattribuition | cmdif | cmdrk | cmdlk | cmdfor | cmdwhile | cmddowhile |
    cmdcase | cmdbreak | cmdswitch | cmdlp | cmdrp | cmddeclaration | cmdmain |
    cmddefine | exit

cmddefine:
    DEFINE ID INT {
        if(contPasso == PASSO_DEFINE){
            printf("\n\tConstante reconhecida!\n\n");
            int i;
            char palavra[strlen($2)];
            for(i=0;i<strlen($2);i++) {
                palavra[i]=tolower($2[i]);
            }
            fprintf(arq, "\n%s\t%s", palavra, $3);
        }
    } commands
    
cmdmain:
    INTEGER MAIN LEFT_PARENTHENSIS RIGHT_PARENTHENSIS LEFT_KEY {
        if(contPasso == PASSO_MAIN){
            contKeys++;
            printf("\n\tFuncao main reconhecida!\n\n");
        }
    } commands

cmdrk:
    RIGHT_KEY {
        if(contPasso == PASSO_LIMPA)
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
        if(contPasso == PASSO_LIMPA)
        contParenthensis--;
    } commands
    
value:
    ID | INT | FLOAT


reservated:
    INTEGER | FLOATING

cmddeclaration:
    reservated ID FINAL {
        if(contPasso == PASSO_MAIN) {
            printf("\n\tDeclaração reconhecida!\n\n");
        }

    } commands


cmdattribuition:
    ID ATTRIBUITION value FINAL {
        if(contPasso == PASSO_MAIN){
            printf("\n\tAtribuicao reconhecida!\n\n", yytext);
            fprintf(arq, "\n\t\tBIPUSH %s\n\t\tISTORE %s", $<string>3, $1);
        }
    } commands

    
cmdif:
    IF LEFT_PARENTHENSIS value COMPARE value RIGHT_PARENTHENSIS LEFT_KEY {
        if(contPasso == PASSO_MAIN){
            contKeys++;
            printf("\n\tComando if reconhecido!\n\n");
            contJumps++;
            fprintf(arq, "\n\t\tILOAD %s\n\t\tBIPUSH %s\n\t\tIF_ICMPEQ L%d\nL%d:", $<string>3, $<string>5, contJumps, contJumps);
        }
    
    } commands
    
cmdfor:
        FOR LEFT_PARENTHENSIS value ATTRIBUITION value FINAL value COMPARE value FINAL value OPERATOR OPERATOR RIGHT_PARENTHENSIS LEFT_KEY {
            if(contPasso == PASSO_MAIN){
                contKeys++;
                printf("\n\tComando for reconhecido!\n\n");
            }
    } commands
    
cmdwhile:
    WHILE LEFT_PARENTHENSIS value COMPARE value RIGHT_PARENTHENSIS LEFT_KEY {
        if(contPasso == PASSO_MAIN){
            contKeys++;
            printf("\n\tComando while reconhecido!\n\n");
        }
    } commands
    
cmddowhile:
    DO LEFT_KEY RIGHT_KEY WHILE LEFT_PARENTHENSIS value COMPARE value RIGHT_PARENTHENSIS FINAL {
        if(contPasso == PASSO_MAIN){
            printf("\n\tComando do-while reconhecido!\n\n");
        }
    } commands
    
cmdcase:
    CASE DEMAIS {
        if(contPasso == PASSO_MAIN){
            printf("\n\tComando case  reconhecido!\n\n");
        }
    } commands
    
cmdbreak:
    BREAK FINAL {
        if(contPasso == PASSO_MAIN){
            printf("\n\tComando break reconhecido!\n\n");
        }
    } commands
    
cmdswitch:
    SWITCH LEFT_PARENTHENSIS value RIGHT_PARENTHENSIS LEFT_KEY {
        if(contPasso == PASSO_MAIN){
            contKeys++;
            printf("\n\tComando switch reconhecido!\n\n");
        }
    } commands
    
     
    
exit: END_OF_FILE
{
    switch(contPasso){
        case 0:
            contPasso++;
            yyterminate();
            break;
            
        case 1:
            contPasso++;
            fprintf(arq, "\n.end-constant");
            yyterminate();
            break;
        
        case 2:
            contPasso++;
            yyterminate();
            break;
        
        default:
            fprintf(arq, "\n.end-main");
            printf("\n\n\tNumero de parentesis abertos: %d\n\n", contParenthensis);
            printf("\tNumero de chaves abertas: %d\n\n", contKeys);
            yyterminate();
            break;
        
    }   
    

}
    
%%

main( argc, argv)
int argc;
char **argv;
    {
        ++argv, --argc;
        
        arq = fopen("depuracao.asm", "w");
        
        //primeiro passo: LENDO TABELA DE SIMBOLOS
        if (argc > 0)
            yyin = fopen( argv[0], "r");
        else
            yyin = stdin;

        if(contPasso==0){
            printf("\nPasso %d: LENDO TABELA DE SIMBOLOS\n\n",contPasso+1);
            yyparse();
        }
        
            

        //segundo passo: IDENTIFICANDO CONSTANTES
            if (argc > 0)
                yyin = fopen( argv[0], "r");
            else
                yyin = stdin;
                
        if(contPasso==1){
            printf("\nPasso %d: IDENTIFICANDO CONSTANTES\n\n",contPasso+1);
            fprintf(arq, "\n.constant");
            yyparse();
        }
        
        //terceiro passo: LENDO FUNCAO PRINCIPAL
        if (argc > 0)
            yyin = fopen( argv[0], "r");
        else
            yyin = stdin;
        
        if(contPasso==2){
            printf("\nPasso %d: LENDO FUNCAO PRINCIPAL\n\n",contPasso+1);
            fprintf(arq, "\n\n.main");
            yyparse();
        }
        
        //quarto passo
        if (argc > 0)
        yyin = fopen( argv[0], "r");
        else
        yyin = stdin;
        
        if(contPasso==3){
            printf("\nPasso %d: VERIFICANDO CHAVES\n\n");
            yyparse();
        }
       
         //quinta passo
            if (argc > 0)
                yyin = fopen( argv[0], "r");
            else
                yyin = stdin;
                
            if(contPasso==4)
                yyparse();
            
        fclose(arq);
    }

yyerror(){
    printf("\n\tERROR\n\n");
    return -1;
}