/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 86 "langC.y"

  char *string;  /* string buffer */



/* Line 2068 of yacc.c  */
#line 88 "langC.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


