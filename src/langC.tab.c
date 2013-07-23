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
     IF = 258,
     WHILE = 259,
     DO = 260,
     ELSE = 261,
     SWITCH = 262,
     CASE = 263,
     FOR = 264,
     ID = 265,
     INT = 266,
     FLOAT = 267,
     DEMAIS = 268,
     LEFT_PARENTHENSIS = 269,
     RIGHT_PARENTHENSIS = 270,
     FINAL = 271,
     ATTRIBUITION = 272,
     COMPARE = 273,
     LEFT_KEY = 274,
     RIGHT_KEY = 275,
     ASP = 276,
     END_OF_FILE = 277,
     OPERATOR = 278,
     ADD = 279,
     SUB = 280,
     BREAK = 281,
     INTEGER = 282,
     FLOATING = 283,
     MAIN = 284,
     DEFINE = 285,
     RETURN = 286
   };
#endif
/* Tokens.  */
#define IF 258
#define WHILE 259
#define DO 260
#define ELSE 261
#define SWITCH 262
#define CASE 263
#define FOR 264
#define ID 265
#define INT 266
#define FLOAT 267
#define DEMAIS 268
#define LEFT_PARENTHENSIS 269
#define RIGHT_PARENTHENSIS 270
#define FINAL 271
#define ATTRIBUITION 272
#define COMPARE 273
#define LEFT_KEY 274
#define RIGHT_KEY 275
#define ASP 276
#define END_OF_FILE 277
#define OPERATOR 278
#define ADD 279
#define SUB 280
#define BREAK 281
#define INTEGER 282
#define FLOATING 283
#define MAIN 284
#define DEFINE 285
#define RETURN 286




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
int to_buffer = 0;

#line 82 "langC.y"
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
#line 84 "langC.y"
{
  char *string;  /* string buffer */
}
/* Line 193 of yacc.c.  */
#line 214 "langC.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 227 "langC.tab.c"

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
#define YYFINAL  56
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNRULES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    44,    50,    51,    59,    60,    66,    67,
      71,    72,    76,    77,    81,    82,    86,    88,    90,    92,
      94,    96,    98,   100,   101,   110,   111,   117,   118,   126,
     127,   134,   135,   145,   146,   164,   165,   175,   176,   181,
     182,   193,   194,   199,   200,   205,   206,   214
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      33,     0,    -1,    51,    -1,    57,    -1,    59,    -1,    40,
      -1,    42,    -1,    61,    -1,    63,    -1,    65,    -1,    67,
      -1,    69,    -1,    71,    -1,    73,    -1,    44,    -1,    46,
      -1,    53,    -1,    55,    -1,    36,    -1,    34,    -1,    38,
      -1,    75,    -1,    -1,    30,    10,    11,    35,    33,    -1,
      -1,    27,    29,    14,    15,    19,    37,    33,    -1,    -1,
      31,    11,    16,    39,    33,    -1,    -1,    20,    41,    33,
      -1,    -1,    19,    43,    33,    -1,    -1,    14,    45,    33,
      -1,    -1,    15,    47,    33,    -1,    10,    -1,    11,    -1,
      12,    -1,    27,    -1,    28,    -1,    24,    -1,    25,    -1,
      -1,    10,    17,    48,    50,    48,    16,    52,    33,    -1,
      -1,    49,    10,    16,    54,    33,    -1,    -1,    49,    10,
      17,    48,    16,    56,    33,    -1,    -1,    10,    17,    48,
      16,    58,    33,    -1,    -1,     3,    14,    48,    18,    48,
      15,    19,    60,    33,    -1,    -1,     9,    14,    48,    17,
      48,    16,    48,    18,    48,    16,    48,    50,    50,    15,
      19,    62,    33,    -1,    -1,     4,    14,    48,    18,    48,
      15,    19,    64,    33,    -1,    -1,     5,    19,    66,    33,
      -1,    -1,    20,     4,    14,    48,    18,    48,    15,    16,
      68,    33,    -1,    -1,     8,    13,    70,    33,    -1,    -1,
      26,    16,    72,    33,    -1,    -1,     7,    14,    48,    15,
      19,    74,    33,    -1,    22,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    91,    91,    92,    93,    93,    93,    94,    95,    95,
      95,    96,    96,    96,    97,    97,    98,    98,    99,   100,
     101,   101,   104,   104,   144,   144,   152,   152,   159,   159,
     170,   170,   175,   175,   180,   180,   186,   206,   206,   210,
     210,   213,   213,   216,   216,   271,   271,   306,   306,   361,
     361,   404,   404,   421,   421,   429,   429,   439,   439,   451,
     451,   463,   463,   470,   470,   477,   477,   486
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "WHILE", "DO", "ELSE", "SWITCH",
  "CASE", "FOR", "ID", "INT", "FLOAT", "DEMAIS", "LEFT_PARENTHENSIS",
  "RIGHT_PARENTHENSIS", "FINAL", "ATTRIBUITION", "COMPARE", "LEFT_KEY",
  "RIGHT_KEY", "ASP", "END_OF_FILE", "OPERATOR", "ADD", "SUB", "BREAK",
  "INTEGER", "FLOATING", "MAIN", "DEFINE", "RETURN", "$accept", "commands",
  "cmddefine", "@1", "cmdmain", "@2", "return", "@3", "cmdrk", "@4",
  "cmdlk", "@5", "cmdlp", "@6", "cmdrp", "@7", "value", "reservated",
  "operatoras", "cmdaddsub", "@8", "cmddeclaration", "@9",
  "cmddeclarationinst", "@10", "cmdattribuition", "@11", "cmdif", "@12",
  "cmdfor", "@13", "cmdwhile", "@14", "cmddowhile", "@15", "cmdwhilefinal",
  "@16", "cmdcase", "@17", "cmdbreak", "@18", "cmdswitch", "@19", "exit", 0
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
     285,   286
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    35,    34,    37,    36,    39,    38,    41,    40,
      43,    42,    45,    44,    47,    46,    48,    48,    48,    49,
      49,    50,    50,    52,    51,    54,    53,    56,    55,    58,
      57,    60,    59,    62,    61,    64,    63,    66,    65,    68,
      67,    70,    69,    72,    71,    74,    73,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     0,     7,     0,     5,     0,     3,
       0,     3,     0,     3,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     0,     8,     0,     5,     0,     7,     0,
       6,     0,     9,     0,    17,     0,     9,     0,     4,     0,
      10,     0,     4,     0,     4,     0,     7,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,    32,    34,
      30,    28,    67,     0,    39,    40,     0,     0,     0,    19,
      18,    20,     5,     6,    14,    15,     0,     2,    16,    17,
       3,     4,     7,     8,     9,    10,    11,    12,    13,    21,
       0,     0,    57,     0,    61,     0,     0,     0,     0,     0,
       0,     0,    63,     0,     0,     0,     1,     0,    36,    37,
      38,     0,     0,     0,     0,     0,     0,     0,    33,    35,
      31,     0,    29,     0,     0,    22,    26,    45,     0,     0,
       0,    58,     0,    62,     0,    49,    41,    42,     0,     0,
      64,     0,     0,     0,     0,     0,     0,     0,    65,     0,
       0,     0,     0,    24,    23,    27,    46,    47,     0,     0,
       0,     0,    50,    43,     0,     0,     0,    51,    55,    66,
       0,     0,     0,    25,    48,     0,     0,     0,    44,    59,
      52,    56,     0,     0,     0,    60,     0,     0,     0,     0,
      53,     0,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    18,    19,    92,    20,   115,    21,    93,    22,    51,
      23,    49,    24,    47,    25,    48,    61,    26,    88,    27,
     121,    28,    94,    29,   116,    30,   100,    31,   125,    32,
     141,    33,   126,    34,    63,    35,   133,    36,    65,    37,
      73,    38,   110,    39
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -113
static const yytype_int8 yypact[] =
{
      92,    -8,    -6,     0,    13,    15,    16,    12,  -113,  -113,
    -113,    27,  -113,     1,     5,  -113,    22,    25,    33,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,    28,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
       3,     3,  -113,     3,  -113,     3,     3,    92,    92,    92,
      23,    92,  -113,    26,    30,    34,  -113,     4,  -113,  -113,
    -113,    21,    31,    92,    36,    92,    37,   -13,  -113,  -113,
    -113,     3,  -113,    92,    40,  -113,  -113,  -113,     3,     3,
       3,  -113,    38,  -113,     3,  -113,  -113,  -113,     3,    41,
    -113,    39,    92,    92,    92,    44,    46,    47,  -113,    48,
      92,    49,     3,  -113,  -113,  -113,  -113,  -113,    51,    52,
      92,     3,  -113,  -113,    57,    92,    92,  -113,  -113,  -113,
      55,    92,    60,  -113,  -113,    92,    92,     3,  -113,  -113,
    -113,  -113,    61,    92,     3,  -113,    -2,    -2,    65,    62,
    -113,    92,  -113
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -113,   -47,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,   -36,  -113,  -112,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      68,    69,    70,    85,    72,    62,    40,    64,    41,    66,
      67,    86,    87,    58,    59,    60,    81,    52,    83,    42,
      77,    78,    86,    87,   137,   138,    90,    43,    44,    46,
      45,    50,    54,    56,    53,    89,    55,    71,    57,    79,
      74,    75,    95,    96,    97,   104,   105,   106,    99,    80,
      76,    82,   101,   112,    84,    91,     0,    98,   103,   102,
     107,   108,   109,   119,   111,   113,   114,     0,   123,   124,
     117,   118,   122,   127,   128,   120,   129,   134,   130,   131,
     139,   140,     0,     0,     0,     0,   135,     0,     0,     0,
       0,   132,     0,     0,   142,     1,     2,     3,   136,     4,
       5,     6,     7,     0,     0,     0,     8,     9,     0,     0,
       0,    10,    11,     0,    12,     0,     0,     0,    13,    14,
      15,     0,    16,    17
};

static const yytype_int16 yycheck[] =
{
      47,    48,    49,    16,    51,    41,    14,    43,    14,    45,
      46,    24,    25,    10,    11,    12,    63,    16,    65,    19,
      16,    17,    24,    25,   136,   137,    73,    14,    13,    17,
      14,     4,    10,     0,    29,    71,    11,    14,    10,    18,
      14,    11,    78,    79,    80,    92,    93,    94,    84,    18,
      16,    15,    88,   100,    17,    15,    -1,    19,    19,    18,
      16,    15,    15,   110,    16,    16,   102,    -1,   115,   116,
      19,    19,    15,    18,   121,   111,    16,    16,   125,   126,
      15,    19,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,   127,    -1,    -1,   141,     3,     4,     5,   134,     7,
       8,     9,    10,    -1,    -1,    -1,    14,    15,    -1,    -1,
      -1,    19,    20,    -1,    22,    -1,    -1,    -1,    26,    27,
      28,    -1,    30,    31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,     8,     9,    10,    14,    15,
      19,    20,    22,    26,    27,    28,    30,    31,    33,    34,
      36,    38,    40,    42,    44,    46,    49,    51,    53,    55,
      57,    59,    61,    63,    65,    67,    69,    71,    73,    75,
      14,    14,    19,    14,    13,    14,    17,    45,    47,    43,
       4,    41,    16,    29,    10,    11,     0,    10,    10,    11,
      12,    48,    48,    66,    48,    70,    48,    48,    33,    33,
      33,    14,    33,    72,    14,    11,    16,    16,    17,    18,
      18,    33,    15,    33,    17,    16,    24,    25,    50,    48,
      33,    15,    35,    39,    54,    48,    48,    48,    19,    48,
      58,    48,    18,    19,    33,    33,    33,    16,    15,    15,
      74,    16,    33,    16,    48,    37,    56,    19,    19,    33,
      48,    52,    15,    33,    33,    60,    64,    18,    33,    16,
      33,    33,    48,    68,    16,    33,    48,    50,    50,    15,
      19,    62,    33
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
        case 22:
#line 104 "langC.y"
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

  case 24:
#line 144 "langC.y"
    {
        if(contPasso == PASSO_MAIN){
            contKeys++;
            printf("\n\tFuncao main reconhecida!\n\n");
        }
    ;}
    break;

  case 26:
#line 152 "langC.y"
    {
        if(contPasso == PASSO_MAIN){
            printf("\n\tRetorno da funcao main reconhecida!\n\n");
        }
;}
    break;

  case 28:
#line 159 "langC.y"
    {
        if(contPasso == PASSO_LIMPA)
            contKeys--;
        if(contPasso == PASSO_MAIN && to_buffer==1){
            fprintf(temp, "\nGOTO G%d\n\n",contJumps);
            to_buffer--;

        }
    ;}
    break;

  case 30:
#line 170 "langC.y"
    {
        contKeys++;
    ;}
    break;

  case 32:
#line 175 "langC.y"
    {
        contParenthensis++;
    ;}
    break;

  case 34:
#line 180 "langC.y"
    {
        if(contPasso == PASSO_LIMPA)
        contParenthensis--;
    ;}
    break;

  case 36:
#line 186 "langC.y"
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

  case 43:
#line 216 "langC.y"
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
            if(to_buffer==0){
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
            if (to_buffer==1){
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
        }

    ;}
    break;

  case 45:
#line 271 "langC.y"
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

  case 47:
#line 306 "langC.y"
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
            if(to_buffer==0){
                if(strtol((yyvsp[(4) - (5)].string) , NULL , 0)!=0)
                    fprintf(arq, "\n\t\tBIPUSH %s\n\t\tISTORE %s", (yyvsp[(4) - (5)].string), (yyvsp[(2) - (5)].string));
                else
                    fprintf(arq, "\n\t\tILOAD %s\n\t\tISTORE %s", (yyvsp[(4) - (5)].string), (yyvsp[(2) - (5)].string));
            }

            if(to_buffer==1){
                if(strtol((yyvsp[(4) - (5)].string) , NULL , 0)!=0)
                    fprintf(temp, "\n\t\tBIPUSH %s\n\t\tISTORE %s", (yyvsp[(4) - (5)].string), (yyvsp[(2) - (5)].string));
                else
                    fprintf(temp, "\n\t\tILOAD %s\n\t\tISTORE %s", (yyvsp[(4) - (5)].string), (yyvsp[(2) - (5)].string));
            }


        }

    ;}
    break;

  case 49:
#line 361 "langC.y"
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
            if(to_buffer==0){
                printf("\n\tAtribuicao reconhecida!\n\n", yytext);
                // verificaçao se é um numero ou uma variavel
                if(strtol((yyvsp[(3) - (4)].string) , NULL , 0)!=0)
                    fprintf(arq, "\n\t\tBIPUSH %s\n\t\tISTORE %s", (yyvsp[(3) - (4)].string), (yyvsp[(1) - (4)].string));
                else
                    fprintf(arq, "\n\t\tILOAD %s\n\t\tISTORE %s", (yyvsp[(3) - (4)].string), (yyvsp[(1) - (4)].string));
            }
            if (to_buffer==1){
                if(strtol((yyvsp[(3) - (4)].string) , NULL , 0)!=0)
                    fprintf(temp, "\n\t\tBIPUSH %s\n\t\tISTORE %s", (yyvsp[(3) - (4)].string), (yyvsp[(1) - (4)].string));
                else
                    fprintf(temp, "\n\t\tILOAD %s\n\t\tISTORE %s", (yyvsp[(3) - (4)].string), (yyvsp[(1) - (4)].string));
            }
        }
    ;}
    break;

  case 51:
#line 404 "langC.y"
    {
        if(contPasso == PASSO_MAIN){
            contKeys++;
            contJumps++;
            if(to_buffer==0){
                printf("\n\tComando if reconhecido!\n\n");
                
                fprintf(arq, "\n\t\tILOAD %s\n\t\tBIPUSH %s\n\t\tIF_ICMPEQ L%d\nG%d:", (yyvsp[(3) - (7)].string), (yyvsp[(5) - (7)].string), contJumps, contJumps);
                fprintf(temp,"L%d:",contJumps);
                to_buffer++;
            }     

        }
    
    ;}
    break;

  case 53:
#line 421 "langC.y"
    {
            if(contPasso == PASSO_MAIN){
                contKeys++;
                printf("\n\tComando for reconhecido!\n\n");
            }
    ;}
    break;

  case 55:
#line 429 "langC.y"
    {
        if(contPasso == PASSO_MAIN){
            contKeys++;
            //contJumpWhile++;
            printf("\n\tComando while reconhecido!\n\n");
            //fprintf(arq, "\nW%d: \n\t\tILOAD %s\n\t\tBIPUSH %s\n\t\tIF_ICMPEQ L%d\nG%d:", contJumpWhile);
        }
    ;}
    break;

  case 57:
#line 439 "langC.y"
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

  case 59:
#line 451 "langC.y"
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

  case 61:
#line 463 "langC.y"
    {
        if(contPasso == PASSO_MAIN){
            printf("\n\tComando case  reconhecido!\n\n");
        }
    ;}
    break;

  case 63:
#line 470 "langC.y"
    {
        if(contPasso == PASSO_MAIN){
            printf("\n\tComando break reconhecido!\n\n");
        }
    ;}
    break;

  case 65:
#line 477 "langC.y"
    {
        if(contPasso == PASSO_MAIN){
            contKeys++;
            printf("\n\tComando switch reconhecido!\n\n");
        }
    ;}
    break;

  case 67:
#line 487 "langC.y"
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
            temp = fopen("temp.txt","r");
            fprintf(arq,"\n\n");
            fprintf(arq, "\nhalt\n");
            char c;
            while (c != EOF){
                c = fgetc(temp);
                if(c!= EOF)
                fprintf(arq, "%c",c);
            }
            fclose (temp);
            
          


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
#line 2018 "langC.tab.c"
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


#line 552 "langC.y"


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
        
        //primeiro passo: LENDO TABELA DE SIMBOLOS
        // este passo é composto de 2 sub-passos um para contar os simbolos e outro para realizar as alterações e verificações
            //primeiro sub-passo
                if (argc > 0)
                    yyin = fopen( nameRead, "r");
                else
                    yyin = stdin;

                if(contPasso==0){
                    printf("\nPasso %d: LENDO TABELA DE SIMBOLOS\n\n",contPasso+1);
                    yyparse();
                }

            //segundo sub-passo
                if (argc > 0)
                    yyin = fopen( nameRead, "r");
                else
                    yyin = stdin;

                if(contPasso==0){
                    printf("\nPasso %d: AINDA LENDO TABELA DE SIMBOLOS\n\n",contPasso+1);
                    yyparse();
                }
                

        //segundo passo: IDENTIFICANDO CONSTANTES
            if (argc > 0)
                yyin = fopen( nameRead, "r");
            else
                yyin = stdin;
                
            if(contPasso==1){
                printf("\nPasso %d: IDENTIFICANDO CONSTANTES\n\n",contPasso+1);
                fprintf(arq, "\n.constant");
                yyparse();
            }
        
        //terceiro passo: LENDO FUNCAO PRINCIPAL
            if (argc > 0)
                yyin = fopen( nameRead, "r");
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
                fprintf(arq,"\n.end-var\n");

                yyparse();
            }
        
        //quarto passo
            if (argc > 0)
            yyin = fopen( nameRead, "r");
            else
            yyin = stdin;
            
            if(contPasso==3){
                printf("\nPasso %d: VERIFICANDO CODIGO\n\n", contPasso+1);
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
