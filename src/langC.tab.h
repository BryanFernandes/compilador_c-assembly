/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
     EQUALS = 269,
     LEFT_PARENTHENSIS = 270,
     RIGHT_PARENTHENSIS = 271,
     FINAL = 272,
     ATTRIBUITION = 273,
     COMPARE = 274,
     LEFT_KEY = 275,
     RIGHT_KEY = 276,
     ASP = 277
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
#define EQUALS 269
#define LEFT_PARENTHENSIS 270
#define RIGHT_PARENTHENSIS 271
#define FINAL 272
#define ATTRIBUITION 273
#define COMPARE 274
#define LEFT_KEY 275
#define RIGHT_KEY 276
#define ASP 277




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 39 "langC.y"
{
  char *string;  /* string buffer */
}
/* Line 1529 of yacc.c.  */
#line 97 "langC.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

