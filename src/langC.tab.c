/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PRINTF = 258,
     IF = 259,
     WHILE = 260,
     DO = 261,
     ELSE = 262,
     SWITCH = 263,
     CASE = 264,
     FOR = 265,
     ID = 266,
     INT = 267,
     FLOAT = 268,
     DEMAIS = 269,
     LEFT_PARENTHENSIS = 270,
     RIGHT_PARENTHENSIS = 271,
     FINAL = 272,
     ATTRIBUITION = 273,
     COMPARE = 274,
     LEFT_KEY = 275,
     RIGHT_KEY = 276,
     ASP = 277,
     END_OF_FILE = 278,
     OPERATOR = 279,
     ADD = 280,
     SUB = 281,
     BREAK = 282,
     INTEGER = 283,
     FLOATING = 284,
     MAIN = 285,
     DEFINE = 286,
     RETURN = 287
   };
#endif
/* Tokens.  */
#define PRINTF 258
#define IF 259
#define WHILE 260
#define DO 261
#define ELSE 262
#define SWITCH 263
#define CASE 264
#define FOR 265
#define ID 266
#define INT 267
#define FLOAT 268
#define DEMAIS 269
#define LEFT_PARENTHENSIS 270
#define RIGHT_PARENTHENSIS 271
#define FINAL 272
#define ATTRIBUITION 273
#define COMPARE 274
#define LEFT_KEY 275
#define RIGHT_KEY 276
#define ASP 277
#define END_OF_FILE 278
#define OPERATOR 279
#define ADD 280
#define SUB 281
#define BREAK 282
#define INTEGER 283
#define FLOATING 284
#define MAIN 285
#define DEFINE 286
#define RETURN 287




/* Copy the first part of user declarations.  */
#line 1 "langC.y"

  /* A lexer for the basic grammar to use for recognizing
     English sentences. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define POOL 1048576
FILE *arq;//depuração
//arq = fopen("depuracao.asm","w");//depuração

//contadores
int contKeys = 0;
int contJumps = 0;
int contJumpGeral = 0;
int contJumpsDo = 0;
int contJumpWhile = 0;
int contParenthensis = 0;
int contPasso = 0;
int contSimbolo=0;
int checkDo = 0;

//variaveis para controle das passadas
int PASSO_SIMBOLO = 0;
int PASSO_SIMBOLO_SET = 0;
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
//variavel para armasenar temporariamente o codigo
FILE * temp;
FILE * tempw;
int to_buffer_if = 0;
int to_buffer_while = 0;

#line 85 "langC.y"
#include "lex.yy.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 87 "langC.y"
{
  char *string;  /* string buffer */
}
/* Line 193 of yacc.c.  */
#line 219 "langC.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 232 "langC.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  59
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  153

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    46,    56,    57,    63,    64,    72,
      73,    79,    80,    84,    85,    89,    90,    94,    95,    99,
     101,   103,   105,   107,   109,   111,   113,   114,   123,   124,
     130,   131,   139,   140,   147,   148,   158,   159,   177,   178,
     188,   189,   194,   195,   206,   207,   212,   213,   218,   219,
     227
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    54,    -1,    60,    -1,    62,    -1,    43,
      -1,    45,    -1,    64,    -1,    66,    -1,    68,    -1,    70,
      -1,    72,    -1,    74,    -1,    76,    -1,    47,    -1,    49,
      -1,    56,    -1,    58,    -1,    39,    -1,    37,    -1,    35,
      -1,    41,    -1,    78,    -1,    -1,     3,    15,    22,    11,
      22,    16,    17,    36,    34,    -1,    -1,    31,    11,    12,
      38,    34,    -1,    -1,    28,    30,    15,    16,    20,    40,
      34,    -1,    -1,    32,    12,    17,    42,    34,    -1,    -1,
      21,    44,    34,    -1,    -1,    20,    46,    34,    -1,    -1,
      15,    48,    34,    -1,    -1,    16,    50,    34,    -1,    11,
      -1,    12,    -1,    13,    -1,    28,    -1,    29,    -1,    25,
      -1,    26,    -1,    -1,    11,    18,    51,    53,    51,    17,
      55,    34,    -1,    -1,    52,    11,    17,    57,    34,    -1,
      -1,    52,    11,    18,    51,    17,    59,    34,    -1,    -1,
      11,    18,    51,    17,    61,    34,    -1,    -1,     4,    15,
      51,    19,    51,    16,    20,    63,    34,    -1,    -1,    10,
      15,    51,    18,    51,    17,    51,    19,    51,    17,    51,
      53,    53,    16,    20,    65,    34,    -1,    -1,     5,    15,
      51,    19,    51,    16,    20,    67,    34,    -1,    -1,     6,
      20,    69,    34,    -1,    -1,    21,     5,    15,    51,    19,
      51,    16,    17,    71,    34,    -1,    -1,     9,    14,    73,
      34,    -1,    -1,    27,    17,    75,    34,    -1,    -1,     8,
      15,    51,    16,    20,    77,    34,    -1,    23,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,    95,    96,    96,    96,    97,    98,    98,
      98,    99,    99,    99,   100,   100,   101,   101,   102,   103,
     103,   104,   104,   109,   109,   142,   142,   182,   182,   190,
     190,   197,   197,   213,   213,   218,   218,   223,   223,   229,
     249,   249,   253,   253,   256,   256,   259,   259,   332,   332,
     367,   367,   428,   428,   477,   477,   495,   495,   503,   503,
     515,   515,   527,   527,   539,   539,   546,   546,   553,   553,
     562
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINTF", "IF", "WHILE", "DO", "ELSE",
  "SWITCH", "CASE", "FOR", "ID", "INT", "FLOAT", "DEMAIS",
  "LEFT_PARENTHENSIS", "RIGHT_PARENTHENSIS", "FINAL", "ATTRIBUITION",
  "COMPARE", "LEFT_KEY", "RIGHT_KEY", "ASP", "END_OF_FILE", "OPERATOR",
  "ADD", "SUB", "BREAK", "INTEGER", "FLOATING", "MAIN", "DEFINE", "RETURN",
  "$accept", "commands", "cmdprintf", "@1", "cmddefine", "@2", "cmdmain",
  "@3", "return", "@4", "cmdrk", "@5", "cmdlk", "@6", "cmdlp", "@7",
  "cmdrp", "@8", "value", "reservated", "operatoras", "cmdaddsub", "@9",
  "cmddeclaration", "@10", "cmddeclarationinst", "@11", "cmdattribuition",
  "@12", "cmdif", "@13", "cmdfor", "@14", "cmdwhile", "@15", "cmddowhile",
  "@16", "cmdwhilefinal", "@17", "cmdcase", "@18", "cmdbreak", "@19",
  "cmdswitch", "@20", "exit", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    36,    35,    38,    37,    40,    39,    42,
      41,    44,    43,    46,    45,    48,    47,    50,    49,    51,
      51,    51,    52,    52,    53,    53,    55,    54,    57,    56,
      59,    58,    61,    60,    63,    62,    65,    64,    67,    66,
      69,    68,    71,    70,    73,    72,    75,    74,    77,    76,
      78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     9,     0,     5,     0,     7,     0,
       5,     0,     3,     0,     3,     0,     3,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     0,     8,     0,     5,
       0,     7,     0,     6,     0,     9,     0,    17,     0,     9,
       0,     4,     0,    10,     0,     4,     0,     4,     0,     7,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
      37,    33,    31,    70,     0,    42,    43,     0,     0,     0,
      20,    19,    18,    21,     5,     6,    14,    15,     0,     2,
      16,    17,     3,     4,     7,     8,     9,    10,    11,    12,
      13,    22,     0,     0,     0,    60,     0,    64,     0,     0,
       0,     0,     0,     0,     0,    66,     0,     0,     0,     1,
       0,     0,    39,    40,    41,     0,     0,     0,     0,     0,
       0,     0,    36,    38,    34,     0,    32,     0,     0,    25,
      29,    48,     0,     0,     0,     0,    61,     0,    65,     0,
      52,    44,    45,     0,     0,    67,     0,     0,     0,     0,
       0,     0,     0,     0,    68,     0,     0,     0,     0,    27,
      26,    30,    49,    50,     0,     0,     0,     0,     0,    53,
      46,     0,     0,     0,    23,    54,    58,    69,     0,     0,
       0,    28,    51,     0,     0,     0,     0,    47,    62,    24,
      55,    59,     0,     0,     0,    63,     0,     0,     0,     0,
      56,     0,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,   133,    21,    97,    22,   122,    23,    98,
      24,    54,    25,    52,    26,    50,    27,    51,    65,    28,
      93,    29,   129,    30,    99,    31,   123,    32,   106,    33,
     134,    34,   151,    35,   135,    36,    67,    37,   143,    38,
      69,    39,    77,    40,   117,    41
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -105
static const yytype_int8 yypact[] =
{
       5,   -12,     3,     9,    -8,    14,    17,    20,    26,  -105,
    -105,  -105,    40,  -105,    29,    21,  -105,    42,    45,    58,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,    48,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,    38,    -6,    -6,  -105,    -6,  -105,    -6,    -6,
       5,     5,     5,    46,     5,  -105,    47,    51,    49,  -105,
      23,    53,  -105,  -105,  -105,    50,    52,     5,    54,     5,
      56,    13,  -105,  -105,  -105,    -6,  -105,     5,    59,  -105,
    -105,  -105,    -6,    43,    -6,    -6,  -105,    57,  -105,    -6,
    -105,  -105,  -105,    -6,    61,  -105,    62,     5,     5,     5,
      69,    60,    71,    73,  -105,    75,     5,    77,    -6,  -105,
    -105,  -105,  -105,  -105,    79,    78,    80,     5,    -6,  -105,
    -105,    81,     5,     5,  -105,  -105,  -105,  -105,    83,     5,
      86,  -105,  -105,     5,     5,     5,    -6,  -105,  -105,  -105,
    -105,  -105,    87,     5,    -6,  -105,    -3,    -3,    89,    88,
    -105,     5,  -105
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -105,   -50,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,     6,  -105,
    -104,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      72,    73,    74,    42,    76,    62,    63,    64,     1,     2,
       3,     4,    45,     5,     6,     7,     8,    86,    43,    88,
       9,    10,    91,    92,    44,    11,    12,    95,    13,    46,
      90,    47,    14,    15,    16,    48,    17,    18,    91,    92,
      81,    82,   147,   148,    49,    53,    55,   110,   111,   112,
      66,    56,    68,    57,    70,    71,   119,    58,    59,    60,
      61,    75,    78,    79,    83,   101,    80,   127,     0,    84,
      87,    85,   131,   132,    89,    96,   114,   104,     0,   137,
     108,    94,   109,   139,   140,   141,   113,   115,   100,   116,
     102,   103,   118,   145,   120,   105,   124,   130,   125,   107,
     126,   152,   136,   138,   144,   149,     0,     0,   150,     0,
       0,     0,     0,     0,   121,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,     0,     0,     0,     0,     0,     0,     0,
     146
};

static const yytype_int16 yycheck[] =
{
      50,    51,    52,    15,    54,    11,    12,    13,     3,     4,
       5,     6,    20,     8,     9,    10,    11,    67,    15,    69,
      15,    16,    25,    26,    15,    20,    21,    77,    23,    15,
      17,    14,    27,    28,    29,    15,    31,    32,    25,    26,
      17,    18,   146,   147,    18,     5,    17,    97,    98,    99,
      44,    30,    46,    11,    48,    49,   106,    12,     0,    11,
      22,    15,    15,    12,    11,    22,    17,   117,    -1,    19,
      16,    19,   122,   123,    18,    16,    16,    20,    -1,   129,
      19,    75,    20,   133,   134,   135,    17,    16,    82,    16,
      84,    85,    17,   143,    17,    89,    17,    16,    20,    93,
      20,   151,    19,    17,    17,    16,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     8,     9,    10,    11,    15,
      16,    20,    21,    23,    27,    28,    29,    31,    32,    34,
      35,    37,    39,    41,    43,    45,    47,    49,    52,    54,
      56,    58,    60,    62,    64,    66,    68,    70,    72,    74,
      76,    78,    15,    15,    15,    20,    15,    14,    15,    18,
      48,    50,    46,     5,    44,    17,    30,    11,    12,     0,
      11,    22,    11,    12,    13,    51,    51,    69,    51,    73,
      51,    51,    34,    34,    34,    15,    34,    75,    15,    12,
      17,    17,    18,    11,    19,    19,    34,    16,    34,    18,
      17,    25,    26,    53,    51,    34,    16,    38,    42,    57,
      51,    22,    51,    51,    20,    51,    61,    51,    19,    20,
      34,    34,    34,    17,    16,    16,    16,    77,    17,    34,
      17,    51,    40,    59,    17,    20,    20,    34,    51,    55,
      16,    34,    34,    36,    63,    67,    19,    34,    17,    34,
      34,    34,    51,    71,    17,    34,    51,    53,    53,    16,
      20,    65,    34
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 23:
#line 109 "langC.y"
    {
        if(contPasso==PASSO_MAIN){
            printf("\n\tComando printf reconhecido!!\n\n");
            if(to_buffer_if==0){

                char palavra[strlen((yyvsp[(4) - (7)].string))];
                int i;
                for(i=0;i<strlen((yyvsp[(4) - (7)].string));i++) {
                    fprintf(arq, "\n\t\tBIPUSH '%c'\n\t\tOUT", (yyvsp[(4) - (7)].string)[i]);
                }
             }

            if(to_buffer_if==1){

                char palavra[strlen((yyvsp[(4) - (7)].string))];
                int i;
                for(i=0;i<strlen((yyvsp[(4) - (7)].string));i++) {
                    fprintf(temp, "\n\t\tBIPUSH '%c'\n\t\tOUT", (yyvsp[(4) - (7)].string)[i]);
                }
             }
            if(to_buffer_while == 1){

                char palavra[strlen((yyvsp[(4) - (7)].string))];
                int i;
                for(i=0;i<strlen((yyvsp[(4) - (7)].string));i++) {
                    fprintf(tempw, "\n\t\tBIPUSH '%c'\n\t\tOUT", (yyvsp[(4) - (7)].string)[i]);
                }
            } 
        }

    ;}
    break;

  case 25:
#line 142 "langC.y"
    {
        if(contPasso == PASSO_SIMBOLO){
            
            printf("\n\t SIMBOLO reconhecido, nome: %s valor: %s tipo: %s tamanho tabela: %d\n", (yyvsp[(2) - (3)].string),(yyvsp[(3) - (3)].string),(yyvsp[(1) - (3)].string),contSimbolo);
            contSimbolo++;
            if(PASSO_SIMBOLO_SET==1){
                int aux =verify_table(table , (yyvsp[(2) - (3)].string));
                
                if(aux!=-1) {
                    printf("\n\tERROR : Simbolo %s ja foi definido\n",(yyvsp[(2) - (3)].string));
                    contSimbolo--; 
                if(abortar!=0){printf("\n ABORTANDO COMPILAÇÃO!!!!! LINHA: %d\n\n\n",cont);contPasso+=10; yyterminate();}

                }else{

                table[contSimbolo-1].name = (yyvsp[(2) - (3)].string); 
                table[contSimbolo-1].value = (yyvsp[(3) - (3)].string);
                table[contSimbolo-1].type = (yyvsp[(1) - (3)].string);
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
            char palavra[strlen((yyvsp[(2) - (3)].string))];
            for(i=0;i<strlen((yyvsp[(2) - (3)].string));i++) {
                palavra[i]=tolower((yyvsp[(2) - (3)].string)[i]);
            }
            fprintf(arq, "\n%s\t%s",palavra, (yyvsp[(3) - (3)].string));
        }
    ;}
    break;

  case 27:
#line 182 "langC.y"
    {
        if(contPasso == PASSO_MAIN){
            contKeys++;
            printf("\n\tFuncao main reconhecida!\n\n");
        }
    ;}
    break;

  case 29:
#line 190 "langC.y"
    {
        if(contPasso == PASSO_MAIN){
            printf("\n\tRetorno da funcao main reconhecida!\n\n");
        }
;}
    break;

  case 31:
#line 197 "langC.y"
    {
        if(contPasso == PASSO_LIMPA)
            contKeys--;
        if(contPasso == PASSO_MAIN && to_buffer_if==1){
            fprintf(temp, "\nGOTO G%d\n\n",contJumpGeral);
            to_buffer_if--;

        }
        if(contPasso == PASSO_MAIN && to_buffer_while == 1){
            fprintf(tempw, "\nGOTO G%d\n\n",contJumpGeral);
            to_buffer_while--;

        }
    ;}
    break;

  case 33:
#line 213 "langC.y"
    {
        contKeys++;
    ;}
    break;

  case 35:
#line 218 "langC.y"
    {
        contParenthensis++;
    ;}
    break;

  case 37:
#line 223 "langC.y"
    {
        if(contPasso == PASSO_LIMPA)
        contParenthensis--;
    ;}
    break;

  case 39:
#line 229 "langC.y"
    {if(contPasso == PASSO_SIMBOLO){
            //printf("\n\t AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
            if(PASSO_SIMBOLO_SET==1){
                   
                    int aux =verify_table(table , (yyvsp[(1) - (1)].string));
                    if(aux==-1) {// o simbolo TEM que existir
                    printf("\n\tERROR : Simbolo %s NUNCA foi definido\n",(yyvsp[(1) - (1)].string));

                    if(abortar!=0){printf("\n ABORTANDO COMPILAÇÃO!!!!! LINHA: %d\n\n\n",cont);contPasso+=10; yyterminate();}

                    }else{

                    table[aux].name = (yyvsp[(1) - (1)].string); 
                    //table[aux].value = $<string>3;
                    //printf("\n\t testando função %d",aux);
                    //printf("\n\t TESTANDO TABELA DE SIMBOLOS>> %s valor: %s Tipo: %s indice: %d\n", table[aux].name,$<string>3,table[aux].type,aux);

                    }
            }
        }
    ;}
    break;

  case 46:
#line 259 "langC.y"
    {
        if(contPasso == PASSO_SIMBOLO){
            printf("\n\tSOMA reconhecido" );
            if(PASSO_SIMBOLO_SET==1){
                   
                    int aux =verify_table(table , (yyvsp[(1) - (6)].string));
                    if(aux==-1) {// o simbolo TEM que existir
                        printf("\n\tERROR : Simbolo %s NUNCA foi definido\n",(yyvsp[(1) - (6)].string));
                    //yyterminate();

                    }
            }
        }
        if(contPasso == PASSO_MAIN){
            if(to_buffer_if==0){
                printf("\n\tSoma reconhecida!\n\n", yytext);
                // verificaçao se é um numero ou uma variavel
                if(strtol((yyvsp[(3) - (6)].string) , NULL , 0)!=0)
                    fprintf(arq, "\n\t\tBIPUSH %s", (yyvsp[(3) - (6)].string));
                else
                    fprintf(arq, "\n\t\tILOAD %s", (yyvsp[(3) - (6)].string));
                if(strtol((yyvsp[(5) - (6)].string) , NULL , 0)!=0)
                    fprintf(arq, "\n\t\tBIPUSH %s", (yyvsp[(5) - (6)].string));
                else
                    fprintf(arq, "\n\t\tILOAD %s", (yyvsp[(5) - (6)].string));
                if(strcmp((yyvsp[(4) - (6)].string) , "+")==0)
                    fprintf(arq, "\n\t\tIADD");
                else
                    fprintf(arq, "\n\t\tISUB");
                fprintf(arq, "\n\t\tISTORE %s", (yyvsp[(1) - (6)].string));
            }
            if (to_buffer_if==1){
                printf("\n\tSoma reconhecida!\n\n", yytext);
                // verificaçao se é um numero ou uma variavel
                if(strtol((yyvsp[(3) - (6)].string) , NULL , 0)!=0)
                    fprintf(temp, "\n\t\tBIPUSH %s", (yyvsp[(3) - (6)].string));
                else
                    fprintf(temp, "\n\t\tILOAD %s", (yyvsp[(3) - (6)].string));
                if(strtol((yyvsp[(5) - (6)].string) , NULL , 0)!=0)
                    fprintf(temp, "\n\t\tBIPUSH %s", (yyvsp[(5) - (6)].string));
                else
                    fprintf(temp, "\n\t\tILOAD %s", (yyvsp[(5) - (6)].string));
                if(strcmp((yyvsp[(4) - (6)].string) , "+")==0)
                    fprintf(temp, "\n\t\tIADD");
                else
                    fprintf(temp, "\n\t\tISUB");
                fprintf(temp, "\n\t\tISTORE %s", (yyvsp[(1) - (6)].string));
                /* code */
            }
            if (to_buffer_while ==1){
                printf("\n\tSoma reconhecida!\n\n", yytext);
                // verificaçao se é um numero ou uma variavel
                if(strtol((yyvsp[(3) - (6)].string) , NULL , 0)!=0)
                    fprintf(tempw, "\n\t\tBIPUSH %s", (yyvsp[(3) - (6)].string));
                else
                    fprintf(tempw, "\n\t\tILOAD %s", (yyvsp[(3) - (6)].string));
                if(strtol((yyvsp[(5) - (6)].string) , NULL , 0)!=0)
                    fprintf(tempw, "\n\t\tBIPUSH %s", (yyvsp[(5) - (6)].string));
                else
                    fprintf(tempw, "\n\t\tILOAD %s", (yyvsp[(5) - (6)].string));
                if(strcmp((yyvsp[(4) - (6)].string) , "+")==0)
                    fprintf(tempw, "\n\t\tIADD");
                else
                    fprintf(tempw, "\n\t\tISUB");
                fprintf(tempw, "\n\t\tISTORE %s", (yyvsp[(1) - (6)].string));
                /* code */
            }
        }

    ;}
    break;

  case 48:
#line 332 "langC.y"
    {
        if(contPasso == PASSO_SIMBOLO){
            
            printf("\n\t SIMBOLO reconhecido, nome: %s valor: VAZIO tipo: %s indice: %d\n\n", (yyvsp[(2) - (3)].string),(yyvsp[(1) - (3)].string),contSimbolo);
            contSimbolo++;
            if(PASSO_SIMBOLO_SET==1){
               
                int aux =verify_table(table , (yyvsp[(2) - (3)].string));
                if(aux!=-1) {
                    printf("\n\tERROR : Simbolo %s ja foi definido\n",(yyvsp[(2) - (3)].string));
                    contSimbolo--; 
                if(abortar!=0){printf("\n ABORTANDO COMPILAÇÃO!!!!! LINHA: %d\n\n\n",cont);contPasso+=10; yyterminate();}

                }else{

                table[contSimbolo-1].name = (yyvsp[(2) - (3)].string); 
                table[contSimbolo-1].value = NULL;
                table[contSimbolo-1].type = (yyvsp[(1) - (3)].string);
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

    ;}
    break;

  case 50:
#line 367 "langC.y"
    {
        if(contPasso == PASSO_SIMBOLO){
            
             printf("\n\t SIMBOLO reconhecido, nome: %s valor: %s tipo: %s indice: %d\n\n", (yyvsp[(2) - (5)].string),(yyvsp[(4) - (5)].string),(yyvsp[(1) - (5)].string),contSimbolo);
             contSimbolo++;
            if(PASSO_SIMBOLO_SET==1){
                //contSimbolo++;
                int aux =verify_table(table , (yyvsp[(2) - (5)].string));
                if(aux!=-1) {
                    printf("\n\tERROR : Simbolo %s ja foi definido\n",(yyvsp[(2) - (5)].string));
                    contSimbolo--; 
                if(abortar!=0){printf("\n ABORTANDO COMPILAÇÃO!!!!! LINHA: %d\n\n\n",cont);contPasso+=10; yyterminate();}

                }else{

                table[contSimbolo-1].name = (yyvsp[(2) - (5)].string); 
                table[contSimbolo-1].value = (yyvsp[(4) - (5)].string);
                table[contSimbolo-1].type = (yyvsp[(1) - (5)].string);
                printf("\n\t testando função %d",aux);
                printf("\n\t TESTANDO TABELA DE SIMBOLOS>> %s valor: %s Tipo: %s indice: %d\n", table[contSimbolo-1].name, 
                                                                                               (yyvsp[(4) - (5)].string),
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
            if(to_buffer_if==0){
                if(strtol((yyvsp[(4) - (5)].string) , NULL , 0)!=0)
                    fprintf(arq, "\n\t\tBIPUSH %s\n\t\tISTORE %s", (yyvsp[(4) - (5)].string), (yyvsp[(2) - (5)].string));
                else
                    fprintf(arq, "\n\t\tILOAD %s\n\t\tISTORE %s", (yyvsp[(4) - (5)].string), (yyvsp[(2) - (5)].string));
            }

            if(to_buffer_if==1){
                if(strtol((yyvsp[(4) - (5)].string) , NULL , 0)!=0)
                    fprintf(temp, "\n\t\tBIPUSH %s\n\t\tISTORE %s", (yyvsp[(4) - (5)].string), (yyvsp[(2) - (5)].string));
                else
                    fprintf(temp, "\n\t\tILOAD %s\n\t\tISTORE %s", (yyvsp[(4) - (5)].string), (yyvsp[(2) - (5)].string));
            }
            if(to_buffer_while==1){
                if(strtol((yyvsp[(4) - (5)].string) , NULL , 0)!=0)
                    fprintf(tempw, "\n\t\tBIPUSH %s\n\t\tISTORE %s", (yyvsp[(4) - (5)].string), (yyvsp[(2) - (5)].string));
                else
                    fprintf(tempw, "\n\t\tILOAD %s\n\t\tISTORE %s", (yyvsp[(4) - (5)].string), (yyvsp[(2) - (5)].string));
            }


        }

    ;}
    break;

  case 52:
#line 428 "langC.y"
    {   
        if(contPasso == PASSO_SIMBOLO){
            printf("\n\t ATRIBUICAO reconhecido, nome: %s valor: %s indice: %d\n\n", (yyvsp[(1) - (4)].string),(yyvsp[(3) - (4)].string),contSimbolo);
            if(PASSO_SIMBOLO_SET==1){
                   
                    int aux =verify_table(table , (yyvsp[(1) - (4)].string));
                    if(aux==-1) {// o simbolo TEM que existir
                        printf("\n\tERROR : Simbolo %s NUNCA foi definido\n",(yyvsp[(1) - (4)].string));
                    //yyterminate();

                    }else{

                    table[aux].name = (yyvsp[(1) - (4)].string); 
                    table[aux].value = (yyvsp[(3) - (4)].string);
                    printf("\n\t testando função %d",aux);
                    printf("\n\t TESTANDO TABELA DE SIMBOLOS>> %s valor: %s Tipo: %s indice: %d\n", table[aux].name, 
                                                                                                   (yyvsp[(3) - (4)].string),
                                                                                                   table[aux].type,
                                                                                                   aux);

                    }
            }
        }
        if(contPasso == PASSO_MAIN){
            if(to_buffer_if==0){
                printf("\n\tAtribuicao reconhecida!\n\n", yytext);
                // verificaçao se é um numero ou uma variavel
                if(strtol((yyvsp[(3) - (4)].string) , NULL , 0)!=0)
                    fprintf(arq, "\n\t\tBIPUSH %s\n\t\tISTORE %s", (yyvsp[(3) - (4)].string), (yyvsp[(1) - (4)].string));
                else
                    fprintf(arq, "\n\t\tILOAD %s\n\t\tISTORE %s", (yyvsp[(3) - (4)].string), (yyvsp[(1) - (4)].string));
            }
            if (to_buffer_if==1){
                if(strtol((yyvsp[(3) - (4)].string) , NULL , 0)!=0)
                    fprintf(temp, "\n\t\tBIPUSH %s\n\t\tISTORE %s", (yyvsp[(3) - (4)].string), (yyvsp[(1) - (4)].string));
                else
                    fprintf(temp, "\n\t\tILOAD %s\n\t\tISTORE %s", (yyvsp[(3) - (4)].string), (yyvsp[(1) - (4)].string));
            }
            if (to_buffer_while ==1){
                if(strtol((yyvsp[(3) - (4)].string) , NULL , 0)!=0)
                    fprintf(tempw, "\n\t\tBIPUSH %s\n\t\tISTORE %s", (yyvsp[(3) - (4)].string), (yyvsp[(1) - (4)].string));
                else
                    fprintf(tempw, "\n\t\tILOAD %s\n\t\tISTORE %s", (yyvsp[(3) - (4)].string), (yyvsp[(1) - (4)].string));
            }
        }
    ;}
    break;

  case 54:
#line 477 "langC.y"
    {
        if(contPasso == PASSO_MAIN){
            contKeys++;
            contJumps++;
            contJumpGeral++;
            if(to_buffer_if==0){
                printf("\n\tComando if reconhecido!\n\n");
                
                fprintf(arq, "\n\t\tILOAD %s\n\t\tBIPUSH %s\n\t\tIF_ICMPEQ L%d\nG%d:", (yyvsp[(3) - (7)].string), (yyvsp[(5) - (7)].string), contJumps, contJumpGeral);
                fprintf(temp,"L%d:",contJumps);
                to_buffer_if++;
            }     

        }
    
    ;}
    break;

  case 56:
#line 495 "langC.y"
    {
            if(contPasso == PASSO_MAIN){
                contKeys++;
                printf("\n\tComando for reconhecido!\n\n");
            }
    ;}
    break;

  case 58:
#line 503 "langC.y"
    {
        if(contPasso == PASSO_MAIN){
            contKeys++;
            contJumpWhile++;
            contJumpGeral++;
            to_buffer_while++;
            printf("\n\tComando while reconhecido!\n\n");
            fprintf(arq, "\nW%d: \n\t\tILOAD %s\n\t\tBIPUSH %s\n\t\tIF_ICMPEQ LW%d\nG%d:", contJumpWhile, (yyvsp[(3) - (7)].string), (yyvsp[(5) - (7)].string), contJumpWhile, contJumpGeral);
        }
    ;}
    break;

  case 60:
#line 515 "langC.y"
    {
       if(contPasso == PASSO_MAIN){
            contKeys++;
            checkDo++;
            contJumpsDo++;
            printf("\n\tComando do-while reconhecido!\n\n");
           fprintf(arq, "\nDO%d:", contJumpsDo);
        } 
    ;}
    break;

  case 62:
#line 527 "langC.y"
    {
        if(contPasso == PASSO_MAIN){
            contKeys--;
            if(checkDo > 0){
                checkDo--;
                printf("\n\tComando do-while reconhecido!\n\n");
                fprintf(arq, "\n\t\tILOAD %s\n\t\tBIPUSH %s\n\t\tIF_ICMPEQ DO%d\n", (yyvsp[(4) - (8)].string), (yyvsp[(6) - (8)].string), contJumpsDo);
            }
        }
    ;}
    break;

  case 64:
#line 539 "langC.y"
    {
        if(contPasso == PASSO_MAIN){
            printf("\n\tComando case  reconhecido!\n\n");
        }
    ;}
    break;

  case 66:
#line 546 "langC.y"
    {
        if(contPasso == PASSO_MAIN){
            printf("\n\tComando break reconhecido!\n\n");
        }
    ;}
    break;

  case 68:
#line 553 "langC.y"
    {
        if(contPasso == PASSO_MAIN){
            contKeys++;
            printf("\n\tComando switch reconhecido!\n\n");
        }
    ;}
    break;

  case 70:
#line 563 "langC.y"
    {
    switch(contPasso){
        case 0:
            if(PASSO_SIMBOLO_SET==0){
                table = (simbolo *) calloc(contSimbolo,sizeof(simbolo));    
                PASSO_SIMBOLO_SET++;

               
                contSimbolo =0;
                cont = 1;  
                yyterminate();
            }
            print_table(table);
            contPasso++;
            cont =0;
            yyterminate();
            break;
            
        case 1:
            contPasso++;
            cont = 1;
            fprintf(arq, "\n.end-constant");
            yyterminate();
            break;
        
        case 2:
            contPasso++;
            cont = 1;
            yyterminate();
            break;
        
        default:
            

            //imprime as funções armasenadas no buffer

            fclose(temp);
            fclose(tempw);
            temp = fopen("temp.txt","r");
            tempw = fopen("tempw.txt","r");
            fprintf(arq,"\n\n");
            fprintf(arq, "\nhalt\n");
            char c;

            while (c != EOF){
                c = fgetc(temp);
                if(c!= EOF)
                fprintf(arq, "%c",c);
            }

            c = ' ';
            while (c != EOF){
                c = fgetc(tempw);
                if(c!= EOF)
                fprintf(arq, "%c",c);
            }


            fclose (temp);
            fclose(tempw);

            // encerra o programa
            fprintf(arq, "\n.end-main");
            printf("\n\n\tNumero de parentesis abertos: %d\n\n", contParenthensis);
            printf("\tNumero de chaves abertas: %d\n\n", contKeys);
            printf("\tEstrutura DO-WHILE completo: %d\n\n", checkDo);
             printf("\tNumero de simbolos na tabela %d\n\n", contSimbolo);
            yyterminate();
            break;
    } 
    

;}
    break;


/* Line 1267 of yacc.c.  */
#line 2120 "langC.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 637 "langC.y"


main( argc, argv)
int argc;
char **argv;
    {
        ++argv, --argc;
        char nameRead[30], nameWrite[30], name[30];
        memcpy(nameRead, argv[0], strlen(argv[0]));
        memcpy(name, nameRead, strlen(nameRead));
        sprintf(nameWrite, "%s.jas", name);
        
        arq = fopen(nameWrite, "w");
        temp = fopen("temp.txt", "w");
        tempw = fopen("tempw.txt", "w");
        
        //primeiro passo: LENDO TABELA DE SIMBOLOS
        // este passo é composto de 2 sub-passos um para contar os simbolos e outro para realizar as alterações e verificações
            //primeiro sub-passo
                if (argc > 0)
                    yyin = fopen( nameRead, "r");
                else
                    yyin = stdin;

                if(contPasso==0){
                    printf("\nPasso %d: RECONHECENDO SIMBOLOS\n\n",contPasso+1);
                    yyparse();
                }

            //segundo sub-passo
                if (argc > 0)
                    yyin = fopen( nameRead, "r");
                else
                    yyin = stdin;

                if(contPasso==0){
                    printf("\nPasso %d: POPULANDO TABELA DE SIMBOLOS\n\n",contPasso+2);
                    yyparse();
                }
                

        //segundo passo: IDENTIFICANDO CONSTANTES
            if (argc > 0)
                yyin = fopen( nameRead, "r");
            else
                yyin = stdin;
                
            if(contPasso==1){
                printf("\n\nPasso %d: IDENTIFICANDO CONSTANTES\n\n",contPasso+2);
                fprintf(arq, "\n.constant");
                yyparse();
            }
        
        //terceiro passo: LENDO FUNCAO PRINCIPAL
            if (argc > 0)
                yyin = fopen( nameRead, "r");
            else
                yyin = stdin;
            
            if(contPasso==2){
                printf("\nPasso %d: LENDO FUNCAO PRINCIPAL\n\n",contPasso+2);
                fprintf(arq, "\n\n.main");
                
                //imprimindo declaração de variaveis dentro da função main
                fprintf(arq,"\n\n.var");
                int i;
                for (i = 0; i < contSimbolo; i++){
                    if(table[i].name!= NULL && strcmp(table[i].type , "#define")!=0) fprintf(arq,"\n%s", table[i].name);
                }
                fprintf(arq,"\n.end-var\n");

                yyparse();
            }
        
        //quarto passo
            if (argc > 0)
            yyin = fopen( nameRead, "r");
            else
            yyin = stdin;
            
            if(contPasso==3){
                printf("\nPasso %d: VERIFICANDO CODIGO\n\n", contPasso+2);
                yyparse();
            }
       
         //quinto passo
            if (argc > 0)
                yyin = fopen( nameRead, "r");
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
