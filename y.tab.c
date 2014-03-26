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
     T_INT = 258,
     T_DOUBLE = 259,
     T_STRING = 260,
     T_TRIANGLE = 261,
     T_PIXMAP = 262,
     T_CIRCLE = 263,
     T_RECTANGLE = 264,
     T_TEXTBOX = 265,
     T_FORWARD = 266,
     T_INITIALIZATION = 267,
     T_TRUE = 268,
     T_FALSE = 269,
     T_ON = 270,
     T_SPACE = 271,
     T_LEFTARROW = 272,
     T_RIGHTARROW = 273,
     T_UPARROW = 274,
     T_DOWNARROW = 275,
     T_LEFTMOUSE_DOWN = 276,
     T_MIDDLEMOUSE_DOWN = 277,
     T_RIGHTMOUSE_DOWN = 278,
     T_LEFTMOUSE_UP = 279,
     T_MIDDLEMOUSE_UP = 280,
     T_RIGHTMOUSE_UP = 281,
     T_MOUSE_MOVE = 282,
     T_MOUSE_DRAG = 283,
     T_F1 = 284,
     T_AKEY = 285,
     T_SKEY = 286,
     T_DKEY = 287,
     T_FKEY = 288,
     T_HKEY = 289,
     T_JKEY = 290,
     T_KKEY = 291,
     T_LKEY = 292,
     T_WKEY = 293,
     T_TOUCHES = 294,
     T_NEAR = 295,
     T_ANIMATION = 296,
     T_IF = 297,
     T_FOR = 298,
     T_ELSE = 299,
     T_EXIT = 300,
     T_LPAREN = 301,
     T_RPAREN = 302,
     T_LBRACE = 303,
     T_RBRACE = 304,
     T_LBRACKET = 305,
     T_RBRACKET = 306,
     T_SEMIC = 307,
     T_COMMA = 308,
     T_PERIOD = 309,
     T_ASSIGN = 310,
     T_PLUS_ASSIGN = 311,
     T_MINUS_ASSIGN = 312,
     T_PLUS_PLUS = 313,
     T_MINUS_MINUS = 314,
     T_ASTERISK = 315,
     T_DIVIDE = 316,
     T_MOD = 317,
     T_PLUS = 318,
     T_MINUS = 319,
     T_SIN = 320,
     T_COS = 321,
     T_TAN = 322,
     T_ASIN = 323,
     T_ACOS = 324,
     T_ATAN = 325,
     T_SQRT = 326,
     T_FLOOR = 327,
     T_ABS = 328,
     T_RANDOM = 329,
     T_LESS = 330,
     T_GREATER = 331,
     T_LESS_EQUAL = 332,
     T_GREATER_EQUAL = 333,
     T_EQUAL = 334,
     T_NOT_EQUAL = 335,
     T_AND = 336,
     T_OR = 337,
     T_NOT = 338,
     T_ID = 339,
     T_INT_CONSTANT = 340,
     T_DOUBLE_CONSTANT = 341,
     T_STRING_CONSTANT = 342,
     T_PRINT = 343,
     T_ERROR = 344,
     IF_NO_ELSE = 345,
     UNARY_OPS = 346
   };
#endif
/* Tokens.  */
#define T_INT 258
#define T_DOUBLE 259
#define T_STRING 260
#define T_TRIANGLE 261
#define T_PIXMAP 262
#define T_CIRCLE 263
#define T_RECTANGLE 264
#define T_TEXTBOX 265
#define T_FORWARD 266
#define T_INITIALIZATION 267
#define T_TRUE 268
#define T_FALSE 269
#define T_ON 270
#define T_SPACE 271
#define T_LEFTARROW 272
#define T_RIGHTARROW 273
#define T_UPARROW 274
#define T_DOWNARROW 275
#define T_LEFTMOUSE_DOWN 276
#define T_MIDDLEMOUSE_DOWN 277
#define T_RIGHTMOUSE_DOWN 278
#define T_LEFTMOUSE_UP 279
#define T_MIDDLEMOUSE_UP 280
#define T_RIGHTMOUSE_UP 281
#define T_MOUSE_MOVE 282
#define T_MOUSE_DRAG 283
#define T_F1 284
#define T_AKEY 285
#define T_SKEY 286
#define T_DKEY 287
#define T_FKEY 288
#define T_HKEY 289
#define T_JKEY 290
#define T_KKEY 291
#define T_LKEY 292
#define T_WKEY 293
#define T_TOUCHES 294
#define T_NEAR 295
#define T_ANIMATION 296
#define T_IF 297
#define T_FOR 298
#define T_ELSE 299
#define T_EXIT 300
#define T_LPAREN 301
#define T_RPAREN 302
#define T_LBRACE 303
#define T_RBRACE 304
#define T_LBRACKET 305
#define T_RBRACKET 306
#define T_SEMIC 307
#define T_COMMA 308
#define T_PERIOD 309
#define T_ASSIGN 310
#define T_PLUS_ASSIGN 311
#define T_MINUS_ASSIGN 312
#define T_PLUS_PLUS 313
#define T_MINUS_MINUS 314
#define T_ASTERISK 315
#define T_DIVIDE 316
#define T_MOD 317
#define T_PLUS 318
#define T_MINUS 319
#define T_SIN 320
#define T_COS 321
#define T_TAN 322
#define T_ASIN 323
#define T_ACOS 324
#define T_ATAN 325
#define T_SQRT 326
#define T_FLOOR 327
#define T_ABS 328
#define T_RANDOM 329
#define T_LESS 330
#define T_GREATER 331
#define T_LESS_EQUAL 332
#define T_GREATER_EQUAL 333
#define T_EQUAL 334
#define T_NOT_EQUAL 335
#define T_AND 336
#define T_OR 337
#define T_NOT 338
#define T_ID 339
#define T_INT_CONSTANT 340
#define T_DOUBLE_CONSTANT 341
#define T_STRING_CONSTANT 342
#define T_PRINT 343
#define T_ERROR 344
#define IF_NO_ELSE 345
#define UNARY_OPS 346




/* Copy the first part of user declarations.  */
#line 1 "gpl.y"
  // bison syntax to indicate the start of the header
  // the header is copied directly into y.tab.c

  extern int yylex();         // this lexer function returns next token
  extern int yyerror(char *); // used to print errors
  extern int line_count;      // the current line in the input; from array.l


#include "error.h"      // class for printing errors (used by gpl)
#include "gpl_assert.h" // function version of standard assert.h
#include "parser.h"
#include "expression.h"
#include "variable.h"
#include <iostream>
#include <assert.h>
#include <vector>
#include <string>
#include <sstream>
#include "symbol.h"
#include "symbol_table.h"
#include "gpl_type.h"

  using namespace std;

  static Symbol_table *TheTable = Symbol_table::instance();

  

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
#line 29 "gpl.y"
{
    int            union_int;
    std::string    *union_string;  // MUST be a pointer to a string (this sucks!)
    double         union_double;
    Gpl_type       union_gpl_type;
    Operator_type  union_operator_type;
    Expression*    union_expression;
    Variable*      union_variable;
  }
/* Line 193 of yacc.c.  */
#line 316 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 329 "y.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   422

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNRULES -- Number of states.  */
#define YYNSTATES  227

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   346

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    11,    14,    17,    20,    24,
      30,    32,    34,    36,    39,    41,    47,    53,    55,    57,
      59,    61,    63,    65,    67,    71,    73,    77,    84,    87,
      89,    91,    93,    95,    98,    99,   110,   113,   116,   119,
     122,   125,   128,   132,   134,   136,   138,   140,   142,   144,
     146,   148,   150,   152,   154,   156,   158,   160,   162,   164,
     166,   168,   170,   172,   174,   176,   178,   182,   184,   190,
     191,   192,   195,   197,   199,   201,   204,   207,   210,   216,
     224,   238,   243,   248,   252,   256,   260,   262,   267,   271,
     278,   280,   284,   288,   292,   296,   300,   304,   308,   312,
     316,   320,   324,   328,   332,   335,   338,   343,   347,   351,
     353,   355,   357,   359,   361,   363,   365,   367,   369,   371,
     373,   375,   377,   379,   381,   383,   385,   387
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      93,     0,    -1,    94,   105,    -1,    94,    95,    -1,   130,
      -1,    96,    52,    -1,    99,    52,    -1,   104,    52,    -1,
      97,    84,    98,    -1,    97,    84,    50,   126,    51,    -1,
       3,    -1,     4,    -1,     5,    -1,    55,   126,    -1,   130,
      -1,   100,    84,    46,   101,    47,    -1,   100,    84,    50,
     126,    51,    -1,     6,    -1,     7,    -1,     8,    -1,     9,
      -1,    10,    -1,   102,    -1,   130,    -1,   102,    53,   103,
      -1,   103,    -1,    84,    55,   126,    -1,    11,    41,    84,
      46,   110,    47,    -1,   105,   106,    -1,   130,    -1,   107,
      -1,   108,    -1,   112,    -1,    12,   115,    -1,    -1,    41,
      84,    46,   111,    47,    48,   109,   118,    49,   117,    -1,
     100,    84,    -1,     6,    84,    -1,     7,    84,    -1,     8,
      84,    -1,     9,    84,    -1,    10,    84,    -1,    15,   113,
     115,    -1,    16,    -1,    19,    -1,    20,    -1,    17,    -1,
      18,    -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,
      25,    -1,    26,    -1,    27,    -1,    28,    -1,    30,    -1,
      31,    -1,    32,    -1,    33,    -1,    34,    -1,    35,    -1,
      36,    -1,    37,    -1,    38,    -1,    29,    -1,   116,   119,
     117,    -1,   115,    -1,    48,   116,   118,    49,   117,    -1,
      -1,    -1,   118,   119,    -1,   130,    -1,   120,    -1,   121,
      -1,   124,    52,    -1,   122,    52,    -1,   123,    52,    -1,
      42,    46,   126,    47,   114,    -1,    42,    46,   126,    47,
     114,    44,   114,    -1,    43,    46,   116,   124,   117,    52,
     126,    52,   116,   124,   117,    47,   115,    -1,    88,    46,
     126,    47,    -1,    45,    46,   126,    47,    -1,   125,    55,
     126,    -1,   125,    56,   126,    -1,   125,    57,   126,    -1,
      84,    -1,    84,    50,   126,    51,    -1,    84,    54,    84,
      -1,    84,    50,   126,    51,    54,    84,    -1,   127,    -1,
     126,    82,   126,    -1,   126,    81,   126,    -1,   126,    77,
     126,    -1,   126,    78,   126,    -1,   126,    75,   126,    -1,
     126,    76,   126,    -1,   126,    79,   126,    -1,   126,    80,
     126,    -1,   126,    63,   126,    -1,   126,    64,   126,    -1,
     126,    60,   126,    -1,   126,    61,   126,    -1,   126,    62,
     126,    -1,    64,   126,    -1,    83,   126,    -1,   129,    46,
     126,    47,    -1,   125,   128,   125,    -1,    46,   126,    47,
      -1,   125,    -1,    85,    -1,    13,    -1,    14,    -1,    86,
      -1,    87,    -1,    39,    -1,    40,    -1,    65,    -1,    66,
      -1,    67,    -1,    68,    -1,    69,    -1,    70,    -1,    71,
      -1,    73,    -1,    72,    -1,    74,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   168,   168,   173,   174,   179,   180,   181,   186,   248,
     289,   293,   297,   305,   309,   317,   318,   323,   324,   325,
     326,   327,   332,   333,   338,   339,   344,   349,   354,   355,
     360,   361,   362,   367,   372,   372,   377,   382,   383,   384,
     385,   386,   391,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   423,   424,   429,   433,
     438,   444,   445,   450,   451,   452,   453,   454,   459,   460,
     465,   470,   475,   480,   481,   482,   487,   501,   505,   508,
     515,   519,   529,   538,   542,   546,   550,   554,   558,   562,
     566,   575,   584,   593,   602,   606,   610,   717,   723,   727,
     731,   735,   739,   743,   747,   755,   756,   761,   765,   769,
     773,   777,   781,   785,   789,   793,   797,   804
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_INT", "T_DOUBLE", "T_STRING",
  "T_TRIANGLE", "T_PIXMAP", "T_CIRCLE", "T_RECTANGLE", "T_TEXTBOX",
  "T_FORWARD", "T_INITIALIZATION", "T_TRUE", "T_FALSE", "T_ON", "T_SPACE",
  "T_LEFTARROW", "T_RIGHTARROW", "T_UPARROW", "T_DOWNARROW",
  "T_LEFTMOUSE_DOWN", "T_MIDDLEMOUSE_DOWN", "T_RIGHTMOUSE_DOWN",
  "T_LEFTMOUSE_UP", "T_MIDDLEMOUSE_UP", "T_RIGHTMOUSE_UP", "T_MOUSE_MOVE",
  "T_MOUSE_DRAG", "T_F1", "T_AKEY", "T_SKEY", "T_DKEY", "T_FKEY", "T_HKEY",
  "T_JKEY", "T_KKEY", "T_LKEY", "T_WKEY", "T_TOUCHES", "T_NEAR",
  "T_ANIMATION", "T_IF", "T_FOR", "T_ELSE", "T_EXIT", "T_LPAREN",
  "T_RPAREN", "T_LBRACE", "T_RBRACE", "T_LBRACKET", "T_RBRACKET",
  "T_SEMIC", "T_COMMA", "T_PERIOD", "T_ASSIGN", "T_PLUS_ASSIGN",
  "T_MINUS_ASSIGN", "T_PLUS_PLUS", "T_MINUS_MINUS", "T_ASTERISK",
  "T_DIVIDE", "T_MOD", "T_PLUS", "T_MINUS", "T_SIN", "T_COS", "T_TAN",
  "T_ASIN", "T_ACOS", "T_ATAN", "T_SQRT", "T_FLOOR", "T_ABS", "T_RANDOM",
  "T_LESS", "T_GREATER", "T_LESS_EQUAL", "T_GREATER_EQUAL", "T_EQUAL",
  "T_NOT_EQUAL", "T_AND", "T_OR", "T_NOT", "T_ID", "T_INT_CONSTANT",
  "T_DOUBLE_CONSTANT", "T_STRING_CONSTANT", "T_PRINT", "T_ERROR",
  "IF_NO_ELSE", "UNARY_OPS", "$accept", "program", "declaration_list",
  "declaration", "variable_declaration", "simple_type",
  "optional_initializer", "object_declaration", "object_type",
  "parameter_list_or_empty", "parameter_list", "parameter",
  "forward_declaration", "block_list", "block", "initialization_block",
  "animation_block", "@1", "animation_parameter",
  "check_animation_parameter", "on_block", "keystroke", "if_block",
  "statement_block", "statement_block_creator", "end_of_statement_block",
  "statement_list", "statement", "if_statement", "for_statement",
  "print_statement", "exit_statement", "assign_statement", "variable",
  "expression", "primary_expression", "geometric_operator",
  "math_operator", "empty", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    94,    94,    95,    95,    95,    96,    96,
      97,    97,    97,    98,    98,    99,    99,   100,   100,   100,
     100,   100,   101,   101,   102,   102,   103,   104,   105,   105,
     106,   106,   106,   107,   109,   108,   110,   111,   111,   111,
     111,   111,   112,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   114,   114,   115,   116,
     117,   118,   118,   119,   119,   119,   119,   119,   120,   120,
     121,   122,   123,   124,   124,   124,   125,   125,   125,   125,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   127,   127,
     127,   127,   127,   127,   127,   128,   128,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   130
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     2,     2,     2,     3,     5,
       1,     1,     1,     2,     1,     5,     5,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     6,     2,     1,
       1,     1,     1,     2,     0,    10,     2,     2,     2,     2,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     5,     0,
       0,     2,     1,     1,     1,     2,     2,     2,     5,     7,
      13,     4,     4,     3,     3,     3,     1,     4,     3,     6,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     4,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     127,     0,   127,     4,     1,    10,    11,    12,    17,    18,
      19,    20,    21,     0,     3,     0,     0,     0,     0,     0,
       2,    29,     0,     5,   127,     6,     0,     7,     0,     0,
       0,    28,    30,    31,    32,     0,     0,     0,     8,    14,
     127,     0,    69,    33,    43,    46,    47,    44,    45,    48,
      49,    50,    51,    52,    53,    54,    55,    65,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,     0,     0,
     111,   112,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   125,   124,   126,     0,    86,   110,   113,   114,   109,
       0,    90,     0,    13,     0,     0,    22,    25,    23,     0,
     127,    42,     0,     0,     0,     0,   104,   105,     0,     0,
     115,   116,     0,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,    16,     0,    72,     0,     0,     0,     0,     0,     0,
      36,    27,   108,     0,    88,   107,   101,   102,   103,    99,
     100,    95,    96,    93,    94,    97,    98,    92,    91,     0,
      26,    24,     0,     0,     0,    70,     0,    71,    73,    74,
       0,     0,     0,     0,    37,    38,    39,    40,    41,     0,
      87,   106,     0,    69,     0,    68,     0,    76,    77,    75,
       0,     0,     0,    34,     0,     0,     0,     0,     0,    83,
      84,    85,   127,    89,    69,    70,    82,    81,     0,    78,
      67,     0,     0,    70,    69,    70,     0,    35,    79,    66,
       0,    69,     0,    70,     0,     0,    80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    14,    15,    16,    38,    17,    18,    95,
      96,    97,    19,    20,    31,    32,    33,   202,   104,   139,
      34,    67,   209,   210,   211,   185,   132,   167,   168,   169,
     170,   171,   172,    89,    90,    91,   112,    92,   133
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -190
static const yytype_int16 yypact[] =
{
    -190,    15,   122,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,    -9,  -190,    -6,   -33,     0,   -25,     8,
       9,  -190,   -15,  -190,   -42,  -190,   -24,  -190,    13,   336,
     -14,  -190,  -190,  -190,  -190,    25,    30,    30,  -190,  -190,
     -11,    30,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,    13,    28,    58,
    -190,  -190,    30,    30,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,    30,   -23,  -190,  -190,  -190,    -5,
     192,  -190,    29,   315,    22,    59,    56,  -190,  -190,   215,
    -190,  -190,   156,    26,    64,    60,  -190,  -190,    30,    34,
    -190,  -190,    50,  -190,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,  -190,
     -11,  -190,   -39,  -190,    61,    63,    65,    67,    68,   106,
    -190,  -190,  -190,   238,  -190,  -190,  -190,  -190,  -190,   -20,
     -20,   128,   128,   128,   128,   344,   344,   323,   247,    97,
     315,  -190,    66,   121,   125,  -190,   136,  -190,  -190,  -190,
     116,   117,   142,    -1,  -190,  -190,  -190,  -190,  -190,   147,
     157,  -190,    30,  -190,    30,  -190,    30,  -190,  -190,  -190,
      30,    30,    30,  -190,   112,   123,    50,   146,   169,   315,
     315,   315,  -190,  -190,    13,  -190,  -190,  -190,   -31,   168,
    -190,   -26,   161,  -190,    13,  -190,    30,  -190,  -190,  -190,
     269,  -190,    50,  -190,   167,    13,  -190
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,   148,  -190,
    -190,    85,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,     4,   -28,   -40,  -185,    17,    24,  -190,  -190,
    -190,  -190,  -189,  -103,   -36,  -190,  -190,  -190,    23
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      43,    93,   100,   162,   163,    99,   164,   205,    36,   145,
     165,   162,   163,    37,   164,     4,   162,   163,   213,   164,
     212,    28,    40,     3,    29,    21,    41,   108,   217,   173,
     219,   109,    22,   223,   110,   111,   105,   106,   224,   101,
     114,   115,   116,    70,    71,    85,    23,    39,   107,   166,
      30,    24,    25,    85,   190,   191,   192,   166,    85,    26,
      27,    42,   166,    98,     8,     9,    10,    11,    12,    35,
      68,    69,   143,    94,   102,   127,    72,   128,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   173,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,   173,   129,   142,   173,   130,
     140,   141,   182,    84,    85,    86,    87,    88,   144,   173,
     114,   115,   116,   117,   118,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    85,   119,   120,   121,   122,   123,
     124,   125,   126,   196,   181,   174,   195,   175,   197,   176,
     198,   177,   178,   179,   199,   200,   201,   114,   115,   116,
     117,   118,   134,   135,   136,   137,   138,   183,   187,   188,
     204,   184,   119,   120,   121,   122,   123,   124,   125,   126,
     220,   222,   186,   114,   115,   116,   117,   118,   114,   115,
     116,   117,   118,   206,   189,   193,   203,   226,   119,   120,
     121,   122,   123,   124,   125,   126,   114,   115,   116,   117,
     118,   194,   214,   216,   225,   161,   207,   103,   218,   208,
       0,   119,   120,   121,   122,   123,   124,   125,   126,   114,
     115,   116,   117,   118,     0,   215,     0,     0,     0,     0,
       0,     0,     0,   113,   119,   120,   121,   122,   123,   124,
     125,   126,   114,   115,   116,   117,   118,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,   119,   120,   121,
     122,   123,   124,   125,   126,   114,   115,   116,   117,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   180,
     119,   120,   121,   122,   123,   124,   125,   126,   114,   115,
     116,   117,   118,     0,     0,     0,     0,   114,   115,   116,
     117,   118,     0,   119,   120,   121,   122,   123,   124,   125,
     126,   221,   119,   120,   121,   122,   123,   124,   125,   114,
     115,   116,   117,   118,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,   120,   121,   122,   123,   124,
     125,   126,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,   114,   115,   116,   117,   118,
       0,     0,     0,   114,   115,   116,   117,   118,     0,     0,
     119,   120,   121,   122,   123,   124,   125,   126,   119,   120,
     121,   122,   123,   124,   114,   115,   116,   117,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   119,
     120,   121,   122
};

static const yytype_int16 yycheck[] =
{
      28,    37,    42,    42,    43,    41,    45,   196,    50,   112,
      49,    42,    43,    55,    45,     0,    42,    43,    49,    45,
     205,    12,    46,     0,    15,     2,    50,    50,   213,   132,
     215,    54,    41,   222,    39,    40,    72,    73,   223,    67,
      60,    61,    62,    13,    14,    84,    52,    24,    84,    88,
      41,    84,    52,    84,    55,    56,    57,    88,    84,    84,
      52,    48,    88,    40,     6,     7,     8,     9,    10,    84,
      84,    46,   108,    84,    46,    46,    46,    55,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   196,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,   208,    47,    47,   211,    53,
      84,    47,    46,    83,    84,    85,    86,    87,    84,   222,
      60,    61,    62,    63,    64,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    84,    75,    76,    77,    78,    79,
      80,    81,    82,   183,    47,    84,   182,    84,   184,    84,
     186,    84,    84,    47,   190,   191,   192,    60,    61,    62,
      63,    64,     6,     7,     8,     9,    10,    46,    52,    52,
      47,    46,    75,    76,    77,    78,    79,    80,    81,    82,
     216,   221,    46,    60,    61,    62,    63,    64,    60,    61,
      62,    63,    64,    47,    52,    48,    84,   225,    75,    76,
      77,    78,    79,    80,    81,    82,    60,    61,    62,    63,
      64,    54,    44,    52,    47,   130,    47,    69,   214,   202,
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    60,
      61,    62,    63,    64,    -1,   211,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    75,    76,    77,    78,    79,    80,
      81,    82,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    75,    76,    77,
      78,    79,    80,    81,    82,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      75,    76,    77,    78,    79,    80,    81,    82,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    64,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    52,    75,    76,    77,    78,    79,    80,    81,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    60,    61,    62,    63,    64,    -1,    -1,
      75,    76,    77,    78,    79,    80,    81,    82,    75,    76,
      77,    78,    79,    80,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    78
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    93,    94,   130,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    95,    96,    97,    99,   100,   104,
     105,   130,    41,    52,    84,    52,    84,    52,    12,    15,
      41,   106,   107,   108,   112,    84,    50,    55,    98,   130,
      46,    50,    48,   115,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,   113,    84,    46,
      13,    14,    46,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    83,    84,    85,    86,    87,   125,
     126,   127,   129,   126,    84,   101,   102,   103,   130,   126,
     116,   115,    46,   100,   110,   126,   126,   126,    50,    54,
      39,    40,   128,    51,    60,    61,    62,    63,    64,    75,
      76,    77,    78,    79,    80,    81,    82,    46,    55,    47,
      53,    51,   118,   130,     6,     7,     8,     9,    10,   111,
      84,    47,    47,   126,    84,   125,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   103,    42,    43,    45,    49,    88,   119,   120,   121,
     122,   123,   124,   125,    84,    84,    84,    84,    84,    47,
      51,    47,    46,    46,    46,   117,    46,    52,    52,    52,
      55,    56,    57,    48,    54,   126,   116,   126,   126,   126,
     126,   126,   109,    84,    47,   124,    47,    47,   118,   114,
     115,   116,   117,    49,    44,   119,    52,   117,   114,   117,
     126,    52,   116,   124,   117,    47,   115
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
        case 8:
#line 187 "gpl.y"
    {
  if(TheTable->lookup(*(yyvsp[(2) - (3)].union_string)) == NULL && TheTable->lookup(*(yyvsp[(2) - (3)].union_string) + "[0]") == NULL)
  {
    if((yyvsp[(1) - (3)].union_gpl_type) == INT){
      if((yyvsp[(3) - (3)].union_expression)){
        if((yyvsp[(3) - (3)].union_expression)->get_Kind() == "DOUBLE_CONSTANT" || (yyvsp[(3) - (3)].union_expression)->get_Kind() == "STRING_CONSTANT"){
          Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE, *(yyvsp[(2) - (3)].union_string));
        }
        else{
          TheTable->insert(*(yyvsp[(2) - (3)].union_string), new Symbol((yyvsp[(1) - (3)].union_gpl_type), *(yyvsp[(2) - (3)].union_string), (yyvsp[(3) - (3)].union_expression)->evalint()));
        }
      }
      else /* No expression */{
        TheTable->insert(*(yyvsp[(2) - (3)].union_string), new Symbol((yyvsp[(1) - (3)].union_gpl_type), *(yyvsp[(2) - (3)].union_string), 0));
      }
    }
    else if((yyvsp[(1) - (3)].union_gpl_type) == DOUBLE){
      if((yyvsp[(3) - (3)].union_expression)){
        if((yyvsp[(3) - (3)].union_expression)->get_Kind() == "STRING_CONSTANT"){
          Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE, *(yyvsp[(2) - (3)].union_string));
        }
        else{
          if((yyvsp[(3) - (3)].union_expression)->get_gType() == INT){
            TheTable->insert(*(yyvsp[(2) - (3)].union_string), new Symbol((yyvsp[(1) - (3)].union_gpl_type), *(yyvsp[(2) - (3)].union_string), (double)(yyvsp[(3) - (3)].union_expression)->evalint()));
          }
          else if((yyvsp[(3) - (3)].union_expression)->get_gType() ==  DOUBLE){
            TheTable->insert(*(yyvsp[(2) - (3)].union_string), new Symbol((yyvsp[(1) - (3)].union_gpl_type), *(yyvsp[(2) - (3)].union_string), (yyvsp[(3) - (3)].union_expression)->evaldouble()));
          }
        }
      }
      else /* No expression */{
        TheTable->insert(*(yyvsp[(2) - (3)].union_string), new Symbol((yyvsp[(1) - (3)].union_gpl_type), *(yyvsp[(2) - (3)].union_string), (double)0));
      }
    }
    else if((yyvsp[(1) - (3)].union_gpl_type) == STRING){
      if((yyvsp[(3) - (3)].union_expression)){
        if((yyvsp[(3) - (3)].union_expression)->get_gType() == INT){
          ostringstream ss;
          ss << (yyvsp[(3) - (3)].union_expression)->evalint();
          TheTable->insert(*(yyvsp[(2) - (3)].union_string), new Symbol((yyvsp[(1) - (3)].union_gpl_type), *(yyvsp[(2) - (3)].union_string), ss.str()));
        }
        else if((yyvsp[(3) - (3)].union_expression)->get_gType() ==  DOUBLE){
          ostringstream ss;
          ss << (yyvsp[(3) - (3)].union_expression)->evaldouble();
          TheTable->insert(*(yyvsp[(2) - (3)].union_string), new Symbol((yyvsp[(1) - (3)].union_gpl_type), *(yyvsp[(2) - (3)].union_string), ss.str()));
        }
        else if((yyvsp[(3) - (3)].union_expression)->get_gType() == STRING){
          TheTable->insert(*(yyvsp[(2) - (3)].union_string), new Symbol((yyvsp[(1) - (3)].union_gpl_type), *(yyvsp[(2) - (3)].union_string), (yyvsp[(3) - (3)].union_expression)->evalstring()));
        }
      }
      else /* No expression */{
        TheTable->insert(*(yyvsp[(2) - (3)].union_string), new Symbol((yyvsp[(1) - (3)].union_gpl_type), *(yyvsp[(2) - (3)].union_string), ""));
      }
    }
    else{
      Error::error(Error::ASSIGNMENT_TYPE_ERROR);
    }
  }
  else //if none of the above we have an error
    Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *(yyvsp[(2) - (3)].union_string));
}
    break;

  case 9:
#line 249 "gpl.y"
    {
  if((yyvsp[(4) - (5)].union_expression)->get_gType() == INT)
  {
    ostringstream oss;
    if(TheTable->lookup(*(yyvsp[(2) - (5)].union_string)) == NULL && TheTable->lookup(*(yyvsp[(2) - (5)].union_string) + "[0]") == NULL)
    {
      for(int i = 0; i < (yyvsp[(4) - (5)].union_expression)->evalint(); i++)
      {
        oss.str("");
        oss << *(yyvsp[(2) - (5)].union_string);
        oss << '[' << i << ']';
        string *s  = new string(oss.str());

        if((yyvsp[(1) - (5)].union_gpl_type) == INT)
          TheTable->insert(*s, new Symbol((yyvsp[(1) - (5)].union_gpl_type), *s, 0));
        if((yyvsp[(1) - (5)].union_gpl_type) == DOUBLE)
          TheTable->insert(*s, new Symbol((yyvsp[(1) - (5)].union_gpl_type), *s, 0.0));
        if((yyvsp[(1) - (5)].union_gpl_type) == STRING)
          TheTable->insert(*s, new Symbol((yyvsp[(1) - (5)].union_gpl_type), *s, ""));
      }
    }
    else
      Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *(yyvsp[(2) - (5)].union_string));
  }
  else if((yyvsp[(4) - (5)].union_expression)->get_gType() == DOUBLE){
    ostringstream ss;
    ss << (yyvsp[(4) - (5)].union_expression)->evaldouble();
    Error::error(Error::INVALID_ARRAY_SIZE, *(yyvsp[(2) - (5)].union_string), ss.str());
  }
  else if((yyvsp[(4) - (5)].union_expression)->get_gType() == STRING){
    ostringstream ss;
    ss << (yyvsp[(4) - (5)].union_expression)->evalstring();
    Error::error(Error::INVALID_ARRAY_SIZE, *(yyvsp[(2) - (5)].union_string), ss.str());
  }

}
    break;

  case 10:
#line 290 "gpl.y"
    {
  (yyval.union_gpl_type) = INT;
}
    break;

  case 11:
#line 294 "gpl.y"
    {
  (yyval.union_gpl_type) = DOUBLE;
}
    break;

  case 12:
#line 298 "gpl.y"
    {
  (yyval.union_gpl_type) = STRING;
}
    break;

  case 13:
#line 306 "gpl.y"
    {
  (yyval.union_expression) = (yyvsp[(2) - (2)].union_expression);
}
    break;

  case 14:
#line 310 "gpl.y"
    {
  (yyval.union_expression) = NULL;
}
    break;

  case 34:
#line 372 "gpl.y"
    { }
    break;

  case 86:
#line 488 "gpl.y"
    {
  Symbol *sTmp = new Symbol;
  sTmp = TheTable->lookup(*(yyvsp[(1) - (1)].union_string));
  if(!sTmp)
  {
    Error::error(Error::UNDECLARED_VARIABLE, *(yyvsp[(1) - (1)].union_string));
    (yyval.union_variable) = new Variable(sTmp);
  }
  else
  {
    (yyval.union_variable) = new Variable(sTmp);
  }
}
    break;

  case 87:
#line 502 "gpl.y"
    {
  (yyval.union_variable) = new Variable(*(yyvsp[(1) - (4)].union_string), (yyvsp[(3) - (4)].union_expression));
}
    break;

  case 88:
#line 506 "gpl.y"
    {
}
    break;

  case 89:
#line 509 "gpl.y"
    {
}
    break;

  case 90:
#line 516 "gpl.y"
    {
  (yyval.union_expression) = (yyvsp[(1) - (1)].union_expression);
}
    break;

  case 91:
#line 520 "gpl.y"
    {
  /*need to check to see weather or not we can or two things forexample a string cant or  integer*/
  if((yyvsp[(1) - (3)].union_expression)->get_gType() == STRING)
    Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "||");
  else if ((yyvsp[(3) - (3)].union_expression)->get_gType() == STRING)
    Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "||");
  else
    (yyval.union_expression) = new Expression(OR, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
}
    break;

  case 92:
#line 530 "gpl.y"
    {
  if((yyvsp[(1) - (3)].union_expression)->get_gType() == STRING)
    Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "&&");
  else if ((yyvsp[(3) - (3)].union_expression)->get_gType() == STRING)
    Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "&&");
  else
    (yyval.union_expression) = new Expression(AND, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
}
    break;

  case 93:
#line 539 "gpl.y"
    {
  (yyval.union_expression) = new Expression(LESS_THAN_EQUAL, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
}
    break;

  case 94:
#line 543 "gpl.y"
    {
  (yyval.union_expression) = new Expression(GREATER_THAN_EQUAL, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
}
    break;

  case 95:
#line 547 "gpl.y"
    {
  (yyval.union_expression) = new Expression(LESS_THAN, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
}
    break;

  case 96:
#line 551 "gpl.y"
    {
  (yyval.union_expression) = new Expression(GREATER_THAN, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
}
    break;

  case 97:
#line 555 "gpl.y"
    {
  (yyval.union_expression) = new Expression(EQUAL, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
}
    break;

  case 98:
#line 559 "gpl.y"
    {
  (yyval.union_expression) = new Expression(NOT_EQUAL, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
}
    break;

  case 99:
#line 563 "gpl.y"
    {
  (yyval.union_expression) = new Expression(PLUS, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
}
    break;

  case 100:
#line 567 "gpl.y"
    {
  if((yyvsp[(1) - (3)].union_expression)->get_gType() == STRING)
    Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "-");
  else if ((yyvsp[(3) - (3)].union_expression)->get_gType() == STRING)
    Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "-");
  else
    (yyval.union_expression) = new Expression(MINUS, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
}
    break;

  case 101:
#line 576 "gpl.y"
    {
  if((yyvsp[(1) - (3)].union_expression)->get_gType() == STRING)
    Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "*");
  else if ((yyvsp[(3) - (3)].union_expression)->get_gType() == STRING)
    Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "*");
  else
    (yyval.union_expression) = new Expression(MULTIPLY, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
}
    break;

  case 102:
#line 585 "gpl.y"
    {
  if((yyvsp[(1) - (3)].union_expression)->get_gType() == STRING)
    Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "/");
  else if ((yyvsp[(3) - (3)].union_expression)->get_gType() == STRING)
    Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "/");
  else
    (yyval.union_expression) = new Expression(DIVIDE, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
}
    break;

  case 103:
#line 594 "gpl.y"
    {
  if((yyvsp[(1) - (3)].union_expression)->get_gType() == STRING)
    Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "%");
  else if ((yyvsp[(3) - (3)].union_expression)->get_gType() == STRING)
    Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "%");
  else
    (yyval.union_expression) = new Expression(MOD, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
}
    break;

  case 104:
#line 603 "gpl.y"
    {
  (yyval.union_expression) = new Expression(UNARY_MINUS, (yyvsp[(2) - (2)].union_expression));
}
    break;

  case 105:
#line 607 "gpl.y"
    {
  (yyval.union_expression) = new Expression(NOT, (yyvsp[(2) - (2)].union_expression));
}
    break;

  case 106:
#line 611 "gpl.y"
    {
  if((yyvsp[(1) - (4)].union_operator_type) == SIN)
  {
    if((yyvsp[(3) - (4)].union_expression)->get_gType() == STRING){
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "sin");
      (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),0);
    }
    else
    {
      (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),(yyvsp[(3) - (4)].union_expression));
    }
  }
  else if ((yyvsp[(1) - (4)].union_operator_type) == COS)
  {
    if((yyvsp[(3) - (4)].union_expression)->get_gType() == STRING){
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "cos");
      (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),0);
    }
    else
    {
      (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),(yyvsp[(3) - (4)].union_expression));
    }
  }
  else if ((yyvsp[(1) - (4)].union_operator_type) == TAN){
    if((yyvsp[(3) - (4)].union_expression)->get_gType() == STRING){
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "tan");
      (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),0);
    }
    else
    {
      (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),(yyvsp[(3) - (4)].union_expression));
    }
  }
  else if ((yyvsp[(1) - (4)].union_operator_type) == ASIN){
    if((yyvsp[(3) - (4)].union_expression)->get_gType() == STRING){
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "asin");
      (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),0);
    }
    else
    {
      (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),(yyvsp[(3) - (4)].union_expression));
    }
  }
  else if ((yyvsp[(1) - (4)].union_operator_type) == ACOS){
    if((yyvsp[(3) - (4)].union_expression)->get_gType() == STRING){
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "acos");
      (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),0);
    }
    else
    {
      (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),(yyvsp[(3) - (4)].union_expression));
    }
  }
  else if ((yyvsp[(1) - (4)].union_operator_type) == ATAN){
    if((yyvsp[(3) - (4)].union_expression)->get_gType() == STRING){
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "atan");
      (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),0);
    }
    else
    {
      (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),(yyvsp[(3) - (4)].union_expression));
    }
  }
  else if ((yyvsp[(1) - (4)].union_operator_type) == ABS){
    if((yyvsp[(3) - (4)].union_expression)->get_gType() == STRING){
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "abs");
      (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),0);
    }
    else
    {
      (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),(yyvsp[(3) - (4)].union_expression));
    }
  }
  else if ((yyvsp[(1) - (4)].union_operator_type) == FLOOR){
    if((yyvsp[(3) - (4)].union_expression)->get_gType() == STRING){
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "floor");
      (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),0);
    }
    else
    {
      (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),(yyvsp[(3) - (4)].union_expression));
    }
  }
  else if ((yyvsp[(1) - (4)].union_operator_type) == RANDOM){
    if((yyvsp[(3) - (4)].union_expression)->get_gType() == STRING){
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "random");
      (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),0);
    }
    else
    {
      (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),(yyvsp[(3) - (4)].union_expression));
    }
  }
  else if ((yyvsp[(1) - (4)].union_operator_type) == SQRT){
    if((yyvsp[(3) - (4)].union_expression)->get_gType() == STRING){
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "sqrt");
      (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),0);
    }
    else
    {
      (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),(yyvsp[(3) - (4)].union_expression));
    }
  }
  else
    (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_operator_type),(yyvsp[(3) - (4)].union_expression));
}
    break;

  case 107:
#line 718 "gpl.y"
    {
}
    break;

  case 108:
#line 724 "gpl.y"
    {
  (yyval.union_expression) = (yyvsp[(2) - (3)].union_expression);
}
    break;

  case 109:
#line 728 "gpl.y"
    {
  (yyval.union_expression) = new Expression((yyvsp[(1) - (1)].union_variable));
}
    break;

  case 110:
#line 732 "gpl.y"
    {
  (yyval.union_expression) = new Expression((yyvsp[(1) - (1)].union_int), INT);
}
    break;

  case 111:
#line 736 "gpl.y"
    {
  (yyval.union_expression) = new Expression(1, INT);
}
    break;

  case 112:
#line 740 "gpl.y"
    {
  (yyval.union_expression) = new Expression(0, INT);
}
    break;

  case 113:
#line 744 "gpl.y"
    {
  (yyval.union_expression) = new Expression((yyvsp[(1) - (1)].union_double), DOUBLE);
}
    break;

  case 114:
#line 748 "gpl.y"
    {
  (yyval.union_expression) = new Expression(*(yyvsp[(1) - (1)].union_string), STRING);
}
    break;

  case 117:
#line 762 "gpl.y"
    {
  (yyval.union_operator_type) = SIN;
}
    break;

  case 118:
#line 766 "gpl.y"
    {
  (yyval.union_operator_type) = COS;
}
    break;

  case 119:
#line 770 "gpl.y"
    {
  (yyval.union_operator_type) = TAN;
}
    break;

  case 120:
#line 774 "gpl.y"
    {
  (yyval.union_operator_type) = ASIN;
}
    break;

  case 121:
#line 778 "gpl.y"
    {
  (yyval.union_operator_type) = ACOS;
}
    break;

  case 122:
#line 782 "gpl.y"
    {
  (yyval.union_operator_type) = ATAN;
}
    break;

  case 123:
#line 786 "gpl.y"
    {
  (yyval.union_operator_type) = SQRT;
}
    break;

  case 124:
#line 790 "gpl.y"
    {
  (yyval.union_operator_type) = ABS;
}
    break;

  case 125:
#line 794 "gpl.y"
    {
  (yyval.union_operator_type) = FLOOR;
}
    break;

  case 126:
#line 798 "gpl.y"
    {
  (yyval.union_operator_type) = RANDOM;
}
    break;


/* Line 1267 of yacc.c.  */
#line 2354 "y.tab.c"
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



