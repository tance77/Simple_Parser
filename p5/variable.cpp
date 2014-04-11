#include "variable.h"
#include "expression.h"
#include "gpl_assert.h"
#include "error.h"
#include "symbol_table.h"

Symbol_table* TheTable = Symbol_table::instance();

Variable::Variable(Symbol *target)
{
  if(target != NULL){
    m_Expression = NULL;
    m_Symbol = target;
    m_Type = m_Symbol->getType();
  }
  else {
      //WTF goes here?
  }
}
Variable::Variable(std::string value, Expression *e) //array
{
  m_Symbol = NULL;
  if(e->get_gType()== INT){
    m_sValue = value;
    Symbol *tmp_Symbol = TheTable->lookup(value + "[0]");
    if(tmp_Symbol == NULL){
      // if we can't find name [0], then this variable needs to reference
      // a dummy symbol
      m_Symbol = new Symbol(INT, value, 0);
      m_Expression = new Expression(0, INT);
      Error::error(Error::VARIABLE_NOT_AN_ARRAY, value);
    }
    else{
      m_Expression = e;
      m_Type = tmp_Symbol->getType();
    }
  }
  else if(e->get_gType() == DOUBLE){
    ostringstream ss;
    ss << e->evaldouble();
    m_sValue = value;
    Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, value, "A double expression");
    m_Symbol = new Symbol(INT, value, 0);
    m_Expression = new Expression(0, INT);
    m_Type = INT;

  }
  else if (e->get_gType() == STRING){
    Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, value, "A string expression");
    m_sValue = value;
    m_Symbol = new Symbol(INT, value, 0);
    m_Expression = new Expression(0, INT);
    m_Type = INT;
  }
}

int Variable::getiValue()
{
  if(m_Symbol != NULL){
    return m_Symbol->getintValue();
  }
  else
  {
    stringstream ss;
    ss << m_Expression->evalint();
    Symbol* sym = TheTable->lookup(m_sValue + '[' + ss.str() + ']');
    if(sym == NULL)
    {
      stringstream ss2;
      ss2 << m_Expression->evalint();
      Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS, m_sValue, ss2.str());
    }
    else{
      return sym->getintValue();
    }
  }
  return 0;
}
double Variable::getdValue()
{
  if(m_Symbol)
    return m_Symbol->getdoubleValue();
  return 0;
}
std::string Variable::getsValue()
{
  if(m_Symbol){
    return m_Symbol->getstringValue();
  }
  return "";
}
Gpl_type Variable::gettype()
{
  return m_Type;
}
