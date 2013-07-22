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
int checkDo = 0;

//variaveis para controle das passadas
int PASSO_SIMBOLO = 0,PASSO_SIMBOLO_SET=0;
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
simbolo * table;
// setar 0 para nao abortar ao encontrar erros , 1 para abortar ao encontrar erros
int abortar = 1;


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
%token <string>ADD
%token <string>SUB
%token <string>BREAK
%token <string>INTEGER
%token <string>FLOATING
%token <string>MAIN
%token <string>DEFINE
%token <string>RETURN
%{#include "lex.yy.c"%}

%union {
  char *string;  /* string buffer */
}

%%

commands:
    cmdaddsub|
    cmdattribuition | 
    cmdif | cmdrk | cmdlk | 
    cmdfor | 
    cmdwhile | cmddowhile | cmdwhilefinal |
    cmdcase | cmdbreak | cmdswitch | 
    cmdlp | cmdrp | 
    cmddeclaration | cmddeclarationinst |
    cmdmain | 
    cmddefine | 
    return | exit

cmddefine:
    DEFINE ID INT {
        if(contPasso == PASSO_SIMBOLO){
            
            printf("\n\t SIMBOLO reconhecido, nome: %s valor: %s tipo: %s tamanho tabela: %d\n", $2,$<string>3,$<string>1,contSimbolo);
            contSimbolo++;
            if(PASSO_SIMBOLO_SET==1){
                int aux =verify_table(table , $2);
                
                if(aux!=-1) {
                    printf("\n\tERROR : Simbolo %s ja foi definido\n",$2);
                    contSimbolo--; 
                if(abortar!=0){printf("\n ABORTANDO COMPILAÇÃO!!!!! LINHA: %d\n\n\n",cont);contPasso+=10; yyterminate();}

                }else{

                table[contSimbolo-1].name = $2; 
                table[contSimbolo-1].value = $<string>3;
                table[contSimbolo-1].type = $<string>1;
                printf("\n\t testando função %d",aux!=-1);
                 printf("\n\t TESTANDO TABELA DE SIMBOLOS>> %s valor: %s tipo: %s indice: %d\n", table[contSimbolo-1].name, 
                                                                                               table[contSimbolo-1].value,
                                                                                               table[contSimbolo-1].type,
                                                                                               contSimbolo-1);

                }
            }
        }
        if(contPasso == PASSO_DEFINE){

            printf("\n\tConstante reconhecida!\n\n");
            int i;
            char palavra[strlen($2)];
            for(i=0;i<strlen($2);i++) {
                palavra[i]=tolower($2[i]);
            }
            fprintf(arq, "\n%s\t%s",palavra, $3);
        }
    } commands
    
cmdmain:
    INTEGER MAIN LEFT_PARENTHENSIS RIGHT_PARENTHENSIS LEFT_KEY {
        if(contPasso == PASSO_MAIN){
            contKeys++;
            printf("\n\tFuncao main reconhecida!\n\n");
        }
    } commands
    
return:
    RETURN INT FINAL {
        if(contPasso == PASSO_MAIN){
            printf("\n\tRetorno da funcao main reconhecida!\n\n");
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
    ID  {if(contPasso == PASSO_SIMBOLO){
            //printf("\n\t AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
            if(PASSO_SIMBOLO_SET==1){
                   
                    int aux =verify_table(table , $1);
                    if(aux==-1) {// o simbolo TEM que existir
                    printf("\n\tERROR : Simbolo %s NUNCA foi definido\n",$1);

                    if(abortar!=0){printf("\n ABORTANDO COMPILAÇÃO!!!!! LINHA: %d\n\n\n",cont);contPasso+=10; yyterminate();}

                    }else{

                    table[aux].name = $1; 
                    //table[aux].value = $<string>3;
                    //printf("\n\t testando função %d",aux);
                    //printf("\n\t TESTANDO TABELA DE SIMBOLOS>> %s valor: %s Tipo: %s indice: %d\n", table[aux].name,$<string>3,table[aux].type,aux);

                    }
            }
        }
    }| INT | FLOAT


reservated:
    INTEGER | FLOATING

operatoras:
    ADD | SUB 

cmdaddsub:
    ID ATTRIBUITION value operatoras value FINAL{
        if(contPasso == PASSO_SIMBOLO){
            printf("\n\tSOMA reconhecido" );
            if(PASSO_SIMBOLO_SET==1){
                   
                    int aux =verify_table(table , $1);
                    if(aux==-1) {// o simbolo TEM que existir
                        printf("\n\tERROR : Simbolo %s NUNCA foi definido\n",$1);
                    //yyterminate();

                    }
            }
        }
        if(contPasso == PASSO_MAIN){
            printf("\n\tSoma reconhecida!\n\n", yytext);
            // verificaçao se é um numero ou uma variavel
            if(strtol($<string>3 , NULL , 0)!=0)
                fprintf(arq, "\n\t\tBIPUSH %s", $<string>3);
            else
                fprintf(arq, "\n\t\tILOAD %s", $<string>3);
            if(strtol($<string>5 , NULL , 0)!=0)
                fprintf(arq, "\n\t\tBIPUSH %s", $<string>5);
            else
                fprintf(arq, "\n\t\tILOAD %s", $<string>5);
            if(strcmp($<string>4 , "+")==0)
                fprintf(arq, "\n\t\tIADD");
            else
                fprintf(arq, "\n\t\tISUB");
            fprintf(arq, "\n\t\tISTORE %s", $<string>1);
        }

    }commands


cmddeclaration:
    reservated ID FINAL {
        if(contPasso == PASSO_SIMBOLO){
            
            printf("\n\t SIMBOLO reconhecido, nome: %s valor: VAZIO tipo: %s indice: %d\n\n", $2,$<string>1,contSimbolo);
            contSimbolo++;
            if(PASSO_SIMBOLO_SET==1){
               
                int aux =verify_table(table , $2);
                if(aux!=-1) {
                    printf("\n\tERROR : Simbolo %s ja foi definido\n",$2);
                    contSimbolo--; 
                if(abortar!=0){printf("\n ABORTANDO COMPILAÇÃO!!!!! LINHA: %d\n\n\n",cont);contPasso+=10; yyterminate();}

                }else{

                table[contSimbolo-1].name = $2; 
                table[contSimbolo-1].value = NULL;
                table[contSimbolo-1].type = $<string>1;
                printf("\n\t testando função %d",aux);
                printf("\n\t TESTANDO TABELA DE SIMBOLOS>> %s valor: VAZIO %p Tipo: %s indice: %d\n", table[contSimbolo-1].name, 
                                                                                               NULL,
                                                                                               table[contSimbolo-1].type,
                                                                                               contSimbolo-1);

                }
            }
            
        }
        if(contPasso == PASSO_MAIN) {
            printf("\n\tDeclaracao reconhecida!\n\n");
        }

    } commands
    
cmddeclarationinst:
    reservated ID ATTRIBUITION value FINAL {
        if(contPasso == PASSO_SIMBOLO){
            
             printf("\n\t SIMBOLO reconhecido, nome: %s valor: %s tipo: %s indice: %d\n\n", $2,$<string>4,$<string>1,contSimbolo);
             contSimbolo++;
            if(PASSO_SIMBOLO_SET==1){
                //contSimbolo++;
                int aux =verify_table(table , $2);
                if(aux!=-1) {
                    printf("\n\tERROR : Simbolo %s ja foi definido\n",$2);
                    contSimbolo--; 
                if(abortar!=0){printf("\n ABORTANDO COMPILAÇÃO!!!!! LINHA: %d\n\n\n",cont);contPasso+=10; yyterminate();}

                }else{

                table[contSimbolo-1].name = $2; 
                table[contSimbolo-1].value = $<string>4;
                table[contSimbolo-1].type = $<string>1;
                printf("\n\t testando função %d",aux);
                printf("\n\t TESTANDO TABELA DE SIMBOLOS>> %s valor: %s Tipo: %s indice: %d\n", table[contSimbolo-1].name, 
                                                                                               $<string>4,
                                                                                               table[contSimbolo-1].type,
                                                                                               contSimbolo-1);
                //contSimbolo--;
                }
            }



        }
        if(contPasso == PASSO_MAIN) {
            printf("\n\tDeclaracao com instanciacao reconhecida!\n\n");
            //fprintf(arq,"\n\t\tBIPUSH %s\n\t\tISTORE %s",$<string>4,$2);
            // verificaçao se é um numero ou uma variavel
            if(strtol($<string>4 , NULL , 0)!=0)
                fprintf(arq, "\n\t\tBIPUSH %s\n\t\tISTORE %s", $<string>4, $2);
            else
                fprintf(arq, "\n\t\tILOAD %s\n\t\tISTORE %s", $<string>4, $2);

        }

    } commands


cmdattribuition:
    ID ATTRIBUITION value FINAL {   
        if(contPasso == PASSO_SIMBOLO){
            printf("\n\t ATRIBUICAO reconhecido, nome: %s valor: %s indice: %d\n\n", $1,$<string>3,contSimbolo);
            if(PASSO_SIMBOLO_SET==1){
                   
                    int aux =verify_table(table , $1);
                    if(aux==-1) {// o simbolo TEM que existir
                        printf("\n\tERROR : Simbolo %s NUNCA foi definido\n",$1);
                    //yyterminate();

                    }else{

                    table[aux].name = $1; 
                    table[aux].value = $<string>3;
                    printf("\n\t testando função %d",aux);
                    printf("\n\t TESTANDO TABELA DE SIMBOLOS>> %s valor: %s Tipo: %s indice: %d\n", table[aux].name, 
                                                                                                   $<string>3,
                                                                                                   table[aux].type,
                                                                                                   aux);

                    }
            }
        }
        if(contPasso == PASSO_MAIN){
            printf("\n\tAtribuicao reconhecida!\n\n", yytext);
            // verificaçao se é um numero ou uma variavel
            if(strtol($<string>3 , NULL , 0)!=0)
                fprintf(arq, "\n\t\tBIPUSH %s\n\t\tISTORE %s", $<string>3, $1);
            else
                fprintf(arq, "\n\t\tILOAD %s\n\t\tISTORE %s", $<string>3, $1);
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
        FOR LEFT_PARENTHENSIS value ATTRIBUITION value FINAL value COMPARE value FINAL value operatoras operatoras RIGHT_PARENTHENSIS LEFT_KEY {
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
    DO LEFT_KEY {
       if(contPasso == PASSO_MAIN){
            contKeys++;
            checkDo++;
            printf("\n\tComando do-while reconhecido!\n\n");
        } 
    } commands

    
cmdwhilefinal:
    RIGHT_KEY WHILE LEFT_PARENTHENSIS value COMPARE value RIGHT_PARENTHENSIS FINAL {
        if(contPasso == PASSO_MAIN){
            contKeys--;
            checkDo--;
            if(checkDo > 0){
                printf("\n\tComando do-while reconhecido!\n\n");
            }
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
            if(PASSO_SIMBOLO_SET==0){
                table = (simbolo *) calloc(contSimbolo,sizeof(simbolo));     
                PASSO_SIMBOLO_SET++;
               
                contSimbolo =0;
                yyterminate();
            }
            print_table(table);
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
            printf("\tEstrutura DO-WHILE completo: %d\n\n", checkDo);
             printf("\tNumero de simbolos na tabela %d\n\n", contSimbolo);
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
        // este passo é composto de 2 sub-passos um para contar os simbolos e outro para realizar as alterações e verificações
            //primeiro sub-passo
                if (argc > 0)
                    yyin = fopen( argv[0], "r");
                else
                    yyin = stdin;

                if(contPasso==0){
                    printf("\nPasso %d: LENDO TABELA DE SIMBOLOS\n\n",contPasso+1);
                    yyparse();
                }

            //segundo sub-passo
                if (argc > 0)
                    yyin = fopen( argv[0], "r");
                else
                    yyin = stdin;

                if(contPasso==0){
                    printf("\nPasso %d: AINDA LENDO TABELA DE SIMBOLOS\n\n",contPasso+1);
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
                
                //imprimindo declaração de variaveis dentro da função main
                fprintf(arq,"\n\n.var");
                int i;
                for (i = 0; i < contSimbolo; i++){
                    if(table[i].name!= NULL && strcmp(table[i].type , "#define")!=0) fprintf(arq,"\n%s", table[i].name);
                }
                fprintf(arq,"\n.end-var");

                yyparse();
            }
        
        //quarto passo
            if (argc > 0)
            yyin = fopen( argv[0], "r");
            else
            yyin = stdin;
            
            if(contPasso==3){
                printf("\nPasso %d: VERIFICANDO CODIGO\n\n", contPasso+1);
                yyparse();
            }
       
         //quinto passo
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

//procura na tabela por um nome, caso exista retorna o indice do mesmo.
int verify_table(simbolo * table , char * name){
    int i;
    printf("\n\tTOTAL = %d", contSimbolo);
    for (i = 0; i <= contSimbolo-1; i++)
    {
        printf("\n>>>>>>> [%s]\t[%s] %d",table[i].name , name,i);
        // se nao testar para NULL ele da um erro de segmentação de comparação entre string e ponteiro
        if(table[i].name!= NULL && strcmp(table[i].name , name)==0) return i;
        
    }

    return -1;
}

void print_table(simbolo * table){
    int i;
    printf("\n\t TAMANHO TOTAL TABELA: %d\n", contSimbolo);
    for (i = 0; i < contSimbolo; i++)
    {
        printf("\n\t INDICE: %d \t nome: %s \t valor: %s \t tipo: %s ",i, table[i].name ,table[i].value,table[i].type);
        
    }


}