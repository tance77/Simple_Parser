%{  // bison syntax to indicate the start of the header
  // the header is copied directly into y.tab.c

  extern int yylex();         // this lexer function returns next token
  extern int yyerror(char *); // used to print errors
  extern int line_count;      // the current line in the input; from array.l


#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


#include "animation_block.h"
#include "assignment_statement.h"
#include "circle.h"
#include "error.h"
#include "event_manager.h"
#include "exit_statement.h"
#include "expression.h"
#include "for_statement.h"
#include "game_object.h"
#include "gpl_assert.h"
#include "gpl_type.h"
#include "if_statement.h"
#include "parser.h"
#include "pixmap.h"
#include "print_statement.h"
#include "rectangle.h"
#include "statement.h"
#include "symbol.h"
#include "symbol_table.h"
#include "textbox.h"
#include "triangle.h"
#include "variable.h"
#include "window.h"

  using namespace std;

  static Symbol_table *TheTable = Symbol_table::instance();
  Game_object *curr_object_under_constructions;
  std::string name_of_curr_object_under_constructions;
  std::string name_of_curr_animation_block;

  %}

  %union {
    int            union_int;
    std::string    *union_string;  // MUST be a pointer to a string (this sucks!)
    double         union_double;
    Gpl_type       union_gpl_type;
    Operator_type  union_operator_type;
    Expression*    union_expression;
    Variable*      union_variable;
    // Game_object*   union_game_object;
    //Animation_block* union_animation_block;
    Symbol*        union_symbol;
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
%token <union_int>T_FORWARD
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

%type <union_expression> expression
%type <union_expression> primary_expression
%type <union_expression> optional_initializer
%type <union_variable> variable
%type <union_variable> variable_declaration
%type <union_gpl_type> simple_type
%type <union_operator_type> math_operator
%type <union_int> object_type // for p6
%type <union_symbol> animation_parameter // for p6

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
//  /*--------------------------RESERVED WORDS START----------------------------*/
//  
//  if(*$2 == "window_width" || *$2 == "window_height" || *$2 == "window_x" || *$2 == "window_y" || *$2 == "animation_speed")  /*reserved words of type int*/
//  {
//    if($1 != INT)
//    {
//      if($1 == DOUBLE)
//      Error::error(Error::INVALID_TYPE_FOR_RESERVED_VARIABLE, *$2,"double","int");
//      if($1 == STRING)
//        Error::error(Error::INVALID_TYPE_FOR_RESERVED_VARIABLE, *$2,"string","int");
//    }
//  }
//  else if(*$2 == "window_red" || *$2 == "window_blue" || *$2 == "window_green")  /*reserved words of type double*/
//  {
//    if($1 != DOUBLE)
//    {
//      if($1 == INT)
//      Error::error(Error::INVALID_TYPE_FOR_RESERVED_VARIABLE, *$2,"int","double");
//      else if($1 == STRING)
//      Error::error(Error::INVALID_TYPE_FOR_RESERVED_VARIABLE, *$2,"string","double");
//    }
//  }
//  else if(*$2 == "window_title") /*reserved words of type string*/
//  {
//    if($1 != STRING)
//    {
//      if($1 == INT)
//       Error::error(Error::INVALID_TYPE_FOR_RESERVED_VARIABLE, *$2,"int","string");
//       else if($1 == DOUBLE)
//       Error::error(Error::INVALID_TYPE_FOR_RESERVED_VARIABLE, *$2,"double","string");
//    }
//  }
//  
///*--------------------------RESERVED WORDS END-----------------------------*/

  if(TheTable->lookup(*$2) == NULL && TheTable->lookup(*$2 + "[0]") == NULL)
  {
    switch($1){
      case INT: /*INT*/
        if($3){
          if ($3->get_gType() == DOUBLE || $3 -> get_gType() == STRING) {
            Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE, *$2);
            TheTable->insert(*$2, new Symbol($1, *$2, 0));
          }
          else
            TheTable->insert(*$2, new Symbol($1, *$2, $3->evalint()));
        }
        else /* No expression */
          TheTable->insert(*$2, new Symbol($1, *$2, 0));
        break;
      case DOUBLE: /*DOUBLE*/
        if($3){
          if($3->get_gType() == STRING ){
            Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE, *$2);
            TheTable->insert(*$2, new Symbol($1, *$2, 0.0));
          }
          else
          {
            if($3->get_gType() == INT)
              TheTable->insert(*$2, new Symbol($1, *$2, (double)$3->evalint()));
            else if($3->get_gType() ==  DOUBLE)
              TheTable->insert(*$2, new Symbol($1, *$2, $3->evaldouble()));
          }
        }
        else /* No expression */
          TheTable->insert(*$2, new Symbol($1, *$2, (double)0));
        break;
      case STRING:/*STRING*/
        if($3){
          if($3->get_gType() == INT){
            ostringstream ss;
            ss << $3->evalint();
            TheTable->insert(*$2, new Symbol($1, *$2, ss.str()));
          }
          else if($3->get_gType() ==  DOUBLE){
            ostringstream ss;
            ss << $3->evaldouble();
            TheTable->insert(*$2, new Symbol($1, *$2, ss.str()));
          }
          else if($3->get_gType() == STRING){
            TheTable->insert(*$2, new Symbol($1, *$2, $3->evalstring()));
          }
        }
        else /* No expression */{
          TheTable->insert(*$2, new Symbol($1, *$2, ""));
        }
        break;
      default: /*DEFAULT*/
        Error::error(Error::ASSIGNMENT_TYPE_ERROR);
        break;
    }
  }
  else
    Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *$2);
}
| simple_type  T_ID  T_LBRACKET expression T_RBRACKET
{
  if($4->get_gType() == INT)
  {
    ostringstream oss;
    if(TheTable->lookup(*$2) == NULL && TheTable->lookup(*$2 + "[0]") == NULL)
    {
      if($4->evalint() == 0)
      {
        Error::error(Error::INVALID_ARRAY_SIZE, *$2, "0");
      }
      for(int i = 0; i < $4->evalint(); i++)
      {
        oss.str("");
        oss << *$2;
        oss << '[' << i << ']';
        string *s  = new string(oss.str());

        if($1 == INT)
          TheTable->insert(*s, new Symbol($1, *s, 0));
        if($1 == DOUBLE)
          TheTable->insert(*s, new Symbol($1, *s, 0.0));
        if($1 == STRING)
          TheTable->insert(*s, new Symbol($1, *s, ""));
      }
    }
    else
      Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *$2);
  }
  else if($4->get_gType() == DOUBLE){
    ostringstream ss;
    ss << $4->evaldouble();
    Error::error(Error::INVALID_ARRAY_SIZE, *$2, ss.str());
  }
  else if($4->get_gType() == STRING){
    ostringstream ss;
    ss << $4->evalstring();
    Error::error(Error::INVALID_ARRAY_SIZE, *$2, ss.str());
  }

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
{
  $$ = $2;
}
| empty
{
  $$ = NULL;
}
;

//---------------------------------------------------------------------
object_declaration:
object_type T_ID
{
  name_of_curr_object_under_constructions = *$2;
  switch($1)
  {
    case T_TRIANGLE:
      curr_object_under_constructions = new Triangle();
      TheTable->insert(*$2, new Symbol(*$2, curr_object_under_constructions));
      break;
    case T_PIXMAP:
      curr_object_under_constructions = new Pixmap();
      TheTable->insert(*$2, new Symbol(*$2, curr_object_under_constructions));
      break;
    case T_CIRCLE:
      curr_object_under_constructions = new Circle();
      TheTable->insert(*$2, new Symbol(*$2, curr_object_under_constructions));
      break;
    case T_RECTANGLE:
      curr_object_under_constructions = new Rectangle();
      TheTable->insert(*$2, new Symbol(*$2, curr_object_under_constructions));
      break;
    case T_TEXTBOX:
      curr_object_under_constructions = new Textbox();
      TheTable->insert(*$2, new Symbol(*$2, curr_object_under_constructions));
      break;
    default:
      break;

  }
}
T_LPAREN parameter_list_or_empty T_RPAREN
{
}
| object_type T_ID T_LBRACKET expression T_RBRACKET // this is an array
{
  if($4->get_gType() == INT)
  {
    ostringstream oss;
    if(TheTable->lookup(*$2) == NULL && TheTable->lookup(*$2 + "[0]") == NULL)
    {
      if($4->evalint() == 0)
      {
        Error::error(Error::INVALID_ARRAY_SIZE, *$2, "0");
      }
      for(int i = 0; i < $4->evalint(); i++)
      {
        oss.str("");
        oss << *$2;
        oss << '[' << i << ']';
        string *s  = new string(oss.str());
        name_of_curr_object_under_constructions = *s;
        switch($1)
        {
          case T_TRIANGLE:
            curr_object_under_constructions = new Triangle();
            TheTable->insert(*s, new Symbol(*s, curr_object_under_constructions));
            break;
          case T_PIXMAP:
            curr_object_under_constructions = new Pixmap();
            TheTable->insert(*s, new Symbol(*s, curr_object_under_constructions));
            break;
          case T_CIRCLE:
            curr_object_under_constructions = new Circle();
            TheTable->insert(*s, new Symbol(*s, curr_object_under_constructions));
            break;
          case T_RECTANGLE:
            curr_object_under_constructions = new Rectangle();
            TheTable->insert(*s, new Symbol(*s, curr_object_under_constructions));
            break;
          case T_TEXTBOX:
            curr_object_under_constructions = new Textbox();
            TheTable->insert(*s, new Symbol(*s, curr_object_under_constructions));
            break;
          default:

            //probably an error
            break;

        }
      }
    }
    else
      Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *$2);
  }
  else if($4->get_gType() == DOUBLE){
    ostringstream ss;
    ss << $4->evaldouble();
    Error::error(Error::INVALID_ARRAY_SIZE, *$2, ss.str());
  }
  else if($4->get_gType() == STRING){
    ostringstream ss;
    ss << $4->evalstring();
    Error::error(Error::INVALID_ARRAY_SIZE, *$2, ss.str());
  }
}
;

//---------------------------------------------------------------------
object_type:
T_TRIANGLE
{
  $$ = T_TRIANGLE;
}
| T_PIXMAP
{
  $$ = T_PIXMAP;
}
| T_CIRCLE
{
  $$ = T_CIRCLE;
}
| T_RECTANGLE
{
  $$ = T_RECTANGLE;
}
| T_TEXTBOX
{
  $$ = T_TEXTBOX;
}
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
{
  
  /*Debugging purposes*/
  
  std::string ID = *$1;
    // Expression *e = $3;
    Gpl_type d3 = $3->get_gType(); /*So I don't have to type $3->get_gType() every time. also for debugging purposes.*/
    
    /*Debugging purposes end*/
//    if($3->get_gType() == ANIMATION_BLOCK){}
//    Error::error(Error::TYPE_MISMATCH_BETWEEN_ANIMATION_BLOCK_AND_OBJECT,name_of_curr_object_under_constructions, name_of_curr_animation_block);
//    else
//    {
      Gpl_type gpl_RHS;
      Status s = (curr_object_under_constructions->get_member_variable_type(*$1, gpl_RHS));
        // gpl_RHS; //debugging
        if(s == OK)
        {
          switch(gpl_RHS)
          {
            case INT:/*INT*/
            if(d3 != DOUBLE && d3 != STRING && d3 != ANIMATION_BLOCK)
            {
              s =  curr_object_under_constructions->set_member_variable(*$1, $3->evalint());
              break;
            }
            else
            {
              Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE,name_of_curr_object_under_constructions,*$1);
              break;
            }
            case DOUBLE:/*DOOUBLE*/
            if(d3 != STRING && d3 != ANIMATION_BLOCK)
            {
              curr_object_under_constructions->set_member_variable(*$1, $3->evaldouble());
              break;
            }
            else
            {
              Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE,name_of_curr_object_under_constructions,*$1);
              break;
            }
            case STRING:/*STRING*/
            if(d3 != ANIMATION_BLOCK)
            {
              curr_object_under_constructions->set_member_variable(*$1, $3->evalstring());
              break;
            }
            else
            {
              Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE,name_of_curr_object_under_constructions,*$1);
              break;
            }
            case ANIMATION_BLOCK:/*ANIMATION BLOCK*/
           if(d3 != INT && d3 != DOUBLE && d3 != STRING)
            {
              Animation_block *block = $3->get_Animation();
              assert(block);
              Symbol *tmpSym = block->get_parameter_symbol();
              Game_object *param = tmpSym->getgameobjectValue();
              if(curr_object_under_constructions->type() != param->type())
              {
                Error::error(Error::TYPE_MISMATCH_BETWEEN_ANIMATION_BLOCK_AND_OBJECT,name_of_curr_object_under_constructions, name_of_curr_animation_block);
              }
              else
              {
              curr_object_under_constructions->set_member_variable(*$1, $3->get_Animation());
              break;
              }
            }
            else
            {
              Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE,name_of_curr_animation_block,*$1);
              break;
            }
            break;
            default:
              //Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, name_of_curr_object_under_constructions, *$1);
                  Error::error(Error::TYPE_MISMATCH_BETWEEN_ANIMATION_BLOCK_AND_OBJECT,name_of_curr_object_under_constructions, name_of_curr_animation_block);
            break;
          }
        } 
        else if(s == MEMBER_NOT_DECLARED)
        {
          Error::error(Error::UNKNOWN_CONSTRUCTOR_PARAMETER, curr_object_under_constructions->type() , *$1);
        }
          // }
}
;

//---------------------------------------------------------------------
forward_declaration:
T_FORWARD T_ANIMATION T_ID T_LPAREN animation_parameter T_RPAREN
{
  assert($5);
  name_of_curr_animation_block = *$3;
  Animation_block* new_animation = new Animation_block($1, $5, *$3);
  Symbol *tmp = new Symbol(*$3, new_animation);
  if(!TheTable->insert(*$3, tmp))
   Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *$3);
  
}
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
{
  Game_object *parameter;
  switch($1)
  {
    case T_TRIANGLE:
      parameter = new Triangle();
      break;
    case T_RECTANGLE:
      parameter = new Rectangle();
      break;
    case T_CIRCLE:
      parameter = new Circle();
      break;
    case T_PIXMAP:
      parameter = new Pixmap();
      break;
    case T_TEXTBOX:
      parameter = new Textbox();
      break;
    default:
      //error
      break;
  }

  parameter->never_animate();
  parameter->never_draw();

  Symbol *passmeup = new Symbol(*$2, parameter);

  if(!TheTable->insert(*$2, passmeup))
  Error::error(Error::ANIMATION_PARAMETER_NAME_NOT_UNIQUE, *$2);
  $$ = passmeup;
}
;

//---------------------------------------------------------------------
check_animation_parameter:
T_TRIANGLE T_ID
{
}
| T_PIXMAP T_ID
{
}
| T_CIRCLE T_ID
{
}
| T_RECTANGLE T_ID
{
}
| T_TEXTBOX T_ID
{
}
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
{
  Symbol *sTmp = new Symbol;
  sTmp = TheTable->lookup(*$1);
  if(!sTmp)
  {
    Error::error(Error::UNDECLARED_VARIABLE, *$1);
    $$ = new Variable(new Symbol(INT, "", 0));
  }
  else
  {
    $$ = new Variable(sTmp);
  }
}
| T_ID T_LBRACKET expression T_RBRACKET
{
  $$ = new Variable(*$1, $3);
}
| T_ID T_PERIOD T_ID /*rect.x*/
{
  if(!TheTable->lookup(*$1))//if it isn't null then you can insert
  {
    Error::error(Error::UNDECLARED_VARIABLE, *$1);
    $$ = new Variable(new Symbol(INT, "", 0)); /*DUMBY VAR*/
    
  }
  else
  {
    Gpl_type gpl_LHS = TheTable->lookup(*$1)->getType();
    if (gpl_LHS == INT || gpl_LHS == DOUBLE || gpl_LHS == STRING)
    {
      Error::error(Error::LHS_OF_PERIOD_MUST_BE_OBJECT, *$1);
      $$ = new Variable(new Symbol(INT, "", 0)); /*DUMBY VAR*/
    }
    else
    {
        //int iTmp;
        //double dTmp;
        //string sTmp;
        Gpl_type gpl_RHS;
        Status s = (TheTable->lookup(*$1))->getgameobjectValue()->get_member_variable_type(*$3, gpl_RHS);
        if(s == OK)
        {
          assert(gpl_LHS == GAME_OBJECT);
          Variable *blah = new Variable(TheTable->lookup(*$1), *$3);
          $$ = new Variable(TheTable->lookup(*$1), *$3);
          
        }
        else
        {
          //wtf your status isnt ok??? Maybe eror
          assert(s = MEMBER_NOT_DECLARED);
          Error::error(Error::UNDECLARED_MEMBER, *$1, *$3);
          $$ = new Variable(new Symbol(INT, "", 0)); /*DUMBY VAR*/
        }
    }
  }
}
| T_ID T_LBRACKET expression T_RBRACKET T_PERIOD T_ID
{
  stringstream ss;
  ss << *$1;
  ss << "[" << "0" << "]";
  Gpl_type fuckthisshit = TheTable->lookup(ss.str())->getType();
  if(fuckthisshit == GAME_OBJECT)
  $$ = new Variable($3, *$1, *$6);
  else
  {
  assert(fuckthisshit != GAME_OBJECT);
  Error::error(Error::LHS_OF_PERIOD_MUST_BE_OBJECT, *$1);
  $$ = new Variable(new Symbol(INT, "", 0)); /*DUMBY VAR*/
  }
  
}
;

//---------------------------------------------------------------------
expression:
primary_expression
{
  $$ = $1;
}
| expression T_OR expression
{
  /*need to check to see weather or not we can or two things forexample a string cant or  integer*/
  if($1->get_gType() == STRING)
    Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "||");
  else if ($3->get_gType() == STRING)
    Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "||");
  else
    $$ = new Expression(OR, $1, $3);
}
| expression T_AND expression
{
  if($1->get_gType() == STRING)
    Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "&&");
  else if ($3->get_gType() == STRING)
    Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "&&");
  else
    $$ = new Expression(AND, $1, $3);
}
| expression T_LESS_EQUAL expression
{
  $$ = new Expression(LESS_THAN_EQUAL, $1, $3);
}
| expression T_GREATER_EQUAL  expression
{
  $$ = new Expression(GREATER_THAN_EQUAL, $1, $3);
}
| expression T_LESS expression
{
  $$ = new Expression(LESS_THAN, $1, $3);
}
| expression T_GREATER  expression
{
  $$ = new Expression(GREATER_THAN, $1, $3);
}
| expression T_EQUAL expression
{
  $$ = new Expression(EQUAL, $1, $3);
}
| expression T_NOT_EQUAL expression
{
  $$ = new Expression(NOT_EQUAL, $1, $3);
}
| expression T_PLUS expression
{
  $$ = new Expression(PLUS, $1, $3);
}
| expression T_MINUS expression
{
  if($1->get_gType() == STRING)
    Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "-");
  else if ($3->get_gType() == STRING)
    Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "-");
  else
    $$ = new Expression(MINUS, $1, $3);
}
| expression T_ASTERISK expression
{
  if($1->get_gType() == STRING)
    Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "*");
  else if ($3->get_gType() == STRING)
    Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "*");
  else
    $$ = new Expression(MULTIPLY, $1, $3);
}
| expression T_DIVIDE expression
{
  if($1->get_gType() == STRING)
    Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "/");
  else if ($3->get_gType() == STRING)
    Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "/");
  else
    $$ = new Expression(DIVIDE, $1, $3);
}
| expression T_MOD expression
{
  if($1->get_gType() == STRING)
    Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "%");
  else if ($3->get_gType() == STRING)
    Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "%");
  else
    $$ = new Expression(MOD, $1, $3);
}
| T_MINUS  expression %prec UNARY_OPS
{
  $$ = new Expression(UNARY_MINUS, $2);
}
| T_NOT  expression %prec UNARY_OPS
{
  $$ = new Expression(NOT, $2);
}
| math_operator T_LPAREN expression T_RPAREN
{
  if($1 == SIN)
  {
    if($3->get_gType() == STRING){
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "sin");
      $$ = new Expression($1,0);
    }
    else
    {
      $$ = new Expression($1,$3);
    }
  }
  else if ($1 == COS)
  {
    if($3->get_gType() == STRING){
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "cos");
      $$ = new Expression($1,0);
    }
    else
    {
      $$ = new Expression($1,$3);
    }
  }
  else if ($1 == TAN){
    if($3->get_gType() == STRING){
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "tan");
      $$ = new Expression($1,0);
    }
    else
    {
      $$ = new Expression($1,$3);
    }
  }
  else if ($1 == ASIN){
    if($3->get_gType() == STRING){
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "asin");
      $$ = new Expression($1,0);
    }
    else
    {
      $$ = new Expression($1,$3);
    }
  }
  else if ($1 == ACOS){
    if($3->get_gType() == STRING){
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "acos");
      $$ = new Expression($1,0);
    }
    else
    {
      $$ = new Expression($1,$3);
    }
  }
  else if ($1 == ATAN){
    if($3->get_gType() == STRING){
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "atan");
      $$ = new Expression($1,0);
    }
    else
    {
      $$ = new Expression($1,$3);
    }
  }
  else if ($1 == ABS){
    if($3->get_gType() == STRING){
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "abs");
      $$ = new Expression(0, INT);
    }
    else
    {
      $$ = new Expression($1,$3);
    }
  }
  else if ($1 == FLOOR){
    if($3->get_gType() == STRING){
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "floor");
      $$ = new Expression(0,INT);
    }
    else
    {
      $$ = new Expression($1,$3);
    }
  }
  else if ($1 == RANDOM){
    if($3->get_gType() == STRING){
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "random");
      $$ = new Expression($1,0);
    }
    else
    {
      $$ = new Expression($1,$3);
    }
  }
  else if ($1 == SQRT){
    if($3->get_gType() == STRING){
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "sqrt");
      $$ = new Expression(0, INT);
    }
    else
    {
      $$ = new Expression($1,$3);
    }
  }
  else
    $$ = new Expression($1,$3);
}
| variable geometric_operator variable
{
}
;
//---------------------------------------------------------------------
primary_expression:
T_LPAREN  expression T_RPAREN
{
  $$ = $2;
}
| variable
{
  $$ = new Expression($1);
}
| T_INT_CONSTANT /*This runs when i say double i = 22 it returns a 0*/
{
  $$ = new Expression($1, INT);
}
| T_TRUE
{
  $$ = new Expression(1, INT);
}
| T_FALSE
{
  $$ = new Expression(0, INT);
}
| T_DOUBLE_CONSTANT
{
  $$ = new Expression($1, DOUBLE);
}
| T_STRING_CONSTANT
{
  $$ = new Expression(*$1, STRING);
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
{
  $$ = SIN;
}
| T_COS
{
  $$ = COS;
}
| T_TAN
{
  $$ = TAN;
}
| T_ASIN
{
  $$ = ASIN;
}
| T_ACOS
{
  $$ = ACOS;
}
| T_ATAN
{
  $$ = ATAN;
}
| T_SQRT
{
  $$ = SQRT;
}
| T_ABS
{
  $$ = ABS;
}
| T_FLOOR
{
  $$ = FLOOR;
}
| T_RANDOM
{
  $$ = RANDOM;
}
;

//---------------------------------------------------------------------
empty:
;
