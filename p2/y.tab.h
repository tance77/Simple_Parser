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
     T_COMMA = 258,
     T_ASSIGN = 259,
     T_LBRACE = 260,
     T_RBRACE = 261,
     T_INT = 262,
     T_SEMIC = 263,
     T_INT_CONSTANT = 264,
     T_ID = 265,
     T_ERROR = 266,
     T_STRING_CONSTANT = 267,
     T_DOUBLE_CONSTANT = 268
   };
#endif
/* Tokens.  */
#define T_COMMA 258
#define T_ASSIGN 259
#define T_LBRACE 260
#define T_RBRACE 261
#define T_INT 262
#define T_SEMIC 263
#define T_INT_CONSTANT 264
#define T_ID 265
#define T_ERROR 266
#define T_STRING_CONSTANT 267
#define T_DOUBLE_CONSTANT 268




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 61 "array.y"
{
                int            union_int;
                string         *union_string;  // MUST be a pointer to a string (this sucks!)
                double         union_double;
                Variable_type  union_variable_type;
        }
/* Line 1529 of yacc.c.  */
#line 82 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

