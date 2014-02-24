%{  // bison syntax to indicate the start of the header
    // the header is copied directly into y.tab.c

    extern int yylex();         // this lexer function returns next token
    extern int yyerror(char *); // used to print errors
    extern int line_count;      // the current line in the input; from array.l


#include "error.h"      // class for printing errors (used by gpl)
#include "gpl_assert.h" // function version of standard assert.h
#include "parser.h"
#include <iostream>
#include <assert.h>
#include <vector>
#include <string>
#include <sstream>
#include "symbol.h"
#include "symbol_table.h"

    using namespace std;

    static Symbol_table *TheTable = Symbol_table::instance();

    %} 

    %union {
        int            union_int;
        std::string    *union_string;  // MUST be a pointer to a string (this sucks!)
        double         union_double;
        Gpl_type       union_gpl_type;
    }


// each token in the language is defined here


%token T_INT
%token T_DOUBLE
%token T_STRING
%token T_TRIANGLE
%token T_PIXMAP
%token T_CIRCLE
%token T_RECTANGLE
%token T_TEXTBOX
%token T_FORWARD
%token T_INITIALIZATION

%token T_TRUE
%token T_FALSE

%token T_ON
%token T_SPACE
%token T_LEFTARROW
%token T_RIGHTARROW
%token T_UPARROW
%token T_DOWNARROW
%token T_LEFTMOUSE_DOWN
%token T_MIDDLEMOUSE_DOWN
%token T_RIGHTMOUSE_DOWN
%token T_LEFTMOUSE_UP
%token T_MIDDLEMOUSE_UP
%token T_RIGHTMOUSE_UP
%token T_MOUSE_MOVE
%token T_MOUSE_DRAG

%token T_F1
%token T_AKEY
%token T_SKEY
%token T_DKEY
%token T_FKEY
%token T_HKEY
%token T_JKEY
%token T_KKEY
%token T_LKEY
%token T_WKEY

%token T_TOUCHES
%token T_NEAR

%token T_ANIMATION

%token T_IF
%token T_FOR
%token T_ELSE

%token T_EXIT

%token T_LPAREN
%token T_RPAREN
%token T_LBRACE
%token T_RBRACE
%token T_LBRACKET
%token T_RBRACKET
%token T_SEMIC
%token T_COMMA
%token T_PERIOD

%token T_ASSIGN
%token T_PLUS_ASSIGN
%token T_MINUS_ASSIGN
%token T_PLUS_PLUS
%token T_MINUS_MINUS

%token T_ASTERISK
%token T_DIVIDE
%token T_MOD
%token T_PLUS
%token T_MINUS
%token T_SIN
%token T_COS
%token T_TAN
%token T_ASIN
%token T_ACOS
%token T_ATAN
%token T_SQRT
%token T_FLOOR
%token T_ABS
%token T_RANDOM

%token T_LESS
%token T_GREATER
%token T_LESS_EQUAL
%token T_GREATER_EQUAL
%token T_EQUAL
%token T_NOT_EQUAL

%token T_AND
%token T_OR
%token T_NOT

%token <union_string> T_ID
%token <union_int> T_INT_CONSTANT
%token <union_double> T_DOUBLE_CONSTANT
%token <union_string> T_STRING_CONSTANT
%token <union_int> T_PRINT // returns line number

%token T_ERROR// Grammar symbols that have values associated with them need to be


%nonassoc IF_NO_ELSE
%nonassoc T_ELSE
%right T_ASSIGN
%left T_OR
%left T_AND
%left T_EQUAL T_NOT_EQUAL
%left T_LESS T_LESS_EQUAL T_GREATER T_GREATER_EQUAL
%left T_PLUS T_MINUS
%left T_ASTERISK T_DIVIDE T_MOD
%nonassoc T_NOT UNARY_OPS

%type <union_gpl_type> simple_type
%% // indicates the start of the rules
//---------------------------------------------------------------------
program:
declaration_list block_list
;

//---------------------------------------------------------------------
declaration_list:
declaration_list declaration
| empty
;

//---------------------------------------------------------------------
declaration:
variable_declaration T_SEMIC
| object_declaration T_SEMIC
| forward_declaration T_SEMIC
;

//---------------------------------------------------------------------
variable_declaration:
simple_type  T_ID  optional_initializer
{
    if(TheTable->lookup(*$2) == NULL && TheTable->lookup(*$2 + "[0]") == NULL)
    {
        if($1 == INT)
            TheTable->insert(*$2, new Symbol($1, *$2, *$3));
        if($1 == DOUBLE)
            TheTable->insert(*$2, new Symbol($1, *$2, *$3));
        if($1 == STRING)
            TheTable->insert(*$2, new Symbol($1, *$2, *$3));
    }
    else
        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *$2);
}
| simple_type  T_ID  T_LBRACKET expression T_RBRACKET
{
    ostringstream oss;
    if(TheTable->lookup(*$2) == NULL && TheTable->lookup(*$2 + "[0]") == NULL)
    {
        for(int i = 0; i < $4; i++)
        {
            oss.str("");
            oss << *$2;
            oss << '[' << i << ']';
            string *s  = new string(oss.str());
        
        if($1 == INT)
            TheTable->insert(*s, new Symbol($1, *s, 42));
        if($1 == DOUBLE)
            TheTable->insert(*s, new Symbol($1, *s, 3.145));
        if($1 == STRING)
            TheTable->insert(*s, new Symbol($1, *s, "\"Hello world\""));
        }
    }
        else
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *$2);
}
;

//---------------------------------------------------------------------
simple_type:
T_INT
{
    $$ = INT;
}
| T_DOUBLE
{
    $$ = DOUBLE;
}
| T_STRING
{
    $$ = STRING;
}
;

//---------------------------------------------------------------------
optional_initializer:
T_ASSIGN expression
| empty
;

//---------------------------------------------------------------------
object_declaration:
object_type T_ID T_LPAREN parameter_list_or_empty T_RPAREN
| object_type T_ID T_LBRACKET expression T_RBRACKET
;

//---------------------------------------------------------------------
object_type:
T_TRIANGLE
| T_PIXMAP
| T_CIRCLE
| T_RECTANGLE
| T_TEXTBOX
;

//---------------------------------------------------------------------
parameter_list_or_empty :
parameter_list
| empty
;

//---------------------------------------------------------------------
parameter_list :
parameter_list T_COMMA parameter
| parameter
;

//---------------------------------------------------------------------
parameter:
T_ID T_ASSIGN expression
;

//---------------------------------------------------------------------
forward_declaration:
T_FORWARD T_ANIMATION T_ID T_LPAREN animation_parameter T_RPAREN
;

//---------------------------------------------------------------------
block_list:
block_list block
| empty
;

//---------------------------------------------------------------------
block:
initialization_block
| animation_block
| on_block
;

//---------------------------------------------------------------------
initialization_block:
T_INITIALIZATION statement_block
;

//---------------------------------------------------------------------
animation_block:
T_ANIMATION T_ID T_LPAREN check_animation_parameter T_RPAREN T_LBRACE { } statement_list T_RBRACE end_of_statement_block
;

//---------------------------------------------------------------------
animation_parameter:
object_type T_ID
;

//---------------------------------------------------------------------
check_animation_parameter:
T_TRIANGLE T_ID
| T_PIXMAP T_ID
| T_CIRCLE T_ID
| T_RECTANGLE T_ID
| T_TEXTBOX T_ID
;

//---------------------------------------------------------------------
on_block:
T_ON keystroke statement_block
;

//---------------------------------------------------------------------
keystroke:
T_SPACE
| T_UPARROW
| T_DOWNARROW
| T_LEFTARROW
| T_RIGHTARROW
| T_LEFTMOUSE_DOWN
| T_MIDDLEMOUSE_DOWN
| T_RIGHTMOUSE_DOWN
| T_LEFTMOUSE_UP
| T_MIDDLEMOUSE_UP
| T_RIGHTMOUSE_UP
| T_MOUSE_MOVE
| T_MOUSE_DRAG
| T_AKEY 
| T_SKEY 
| T_DKEY 
| T_FKEY 
| T_HKEY 
| T_JKEY 
| T_KKEY 
| T_LKEY 
| T_WKEY 
| T_F1
;

//---------------------------------------------------------------------
if_block:
statement_block_creator statement end_of_statement_block
| statement_block
;

//---------------------------------------------------------------------
statement_block:
T_LBRACE statement_block_creator statement_list T_RBRACE end_of_statement_block
;

//---------------------------------------------------------------------
statement_block_creator:
// this goes to nothing so that you can put an action here in p7
;

//---------------------------------------------------------------------
end_of_statement_block:
// this goes to nothing so that you can put an action here in p7
;

//---------------------------------------------------------------------
statement_list:
statement_list statement
| empty
;

//---------------------------------------------------------------------
statement:
if_statement
| for_statement
| assign_statement T_SEMIC
| print_statement T_SEMIC
| exit_statement T_SEMIC
;

//---------------------------------------------------------------------
if_statement:
T_IF T_LPAREN expression T_RPAREN if_block %prec IF_NO_ELSE
| T_IF T_LPAREN expression T_RPAREN if_block T_ELSE if_block %prec T_ELSE 
;

//---------------------------------------------------------------------
for_statement:
T_FOR T_LPAREN statement_block_creator assign_statement end_of_statement_block T_SEMIC expression T_SEMIC statement_block_creator assign_statement end_of_statement_block T_RPAREN statement_block
;

//---------------------------------------------------------------------
print_statement:
T_PRINT T_LPAREN expression T_RPAREN
;

//---------------------------------------------------------------------
exit_statement:
T_EXIT T_LPAREN expression T_RPAREN
;

//---------------------------------------------------------------------
assign_statement:
variable T_ASSIGN expression
| variable T_PLUS_ASSIGN expression
| variable T_MINUS_ASSIGN expression
;

//---------------------------------------------------------------------
variable:
T_ID
| T_ID T_LBRACKET expression T_RBRACKET
| T_ID T_PERIOD T_ID
| T_ID T_LBRACKET expression T_RBRACKET T_PERIOD T_ID
;

//---------------------------------------------------------------------
expression:
primary_expression
| expression T_OR expression
| expression T_AND expression
| expression T_LESS_EQUAL expression
| expression T_GREATER_EQUAL  expression
| expression T_LESS expression 
| expression T_GREATER  expression
| expression T_EQUAL expression
| expression T_NOT_EQUAL expression
| expression T_PLUS expression 
| expression T_MINUS expression 
| expression T_ASTERISK expression
| expression T_DIVIDE expression
| expression T_MOD expression
| T_MINUS  expression %prec UNARY_OPS
| T_NOT  expression %prec UNARY_OPS
| math_operator T_LPAREN expression T_RPAREN
| variable geometric_operator variable
;

//---------------------------------------------------------------------
primary_expression:
T_LPAREN  expression T_RPAREN
| variable
| T_INT_CONSTANT
{
}
| T_TRUE
| T_FALSE
| T_DOUBLE_CONSTANT
{
}
| T_STRING_CONSTANT
{
}
;

//---------------------------------------------------------------------
geometric_operator:
T_TOUCHES
| T_NEAR
;

//---------------------------------------------------------------------
math_operator:
T_SIN
| T_COS
| T_TAN
| T_ASIN
| T_ACOS
| T_ATAN
| T_SQRT
| T_ABS
| T_FLOOR
| T_RANDOM
;

//---------------------------------------------------------------------
empty:
;
