#include "variable.h"
#include "expression.h"
#include "error.h"

Variable::Variable(Symbol *target)
{
  m_Symbol = target;
  m_iValue = getiValue();
  m_dValue = getdValue();
  m_sValue = getsValue();
  m_Type = m_Symbol->getType();
}
Variable::Variable(std::string value, Expression *e) //array
{
  if(e->get_gType() == DOUBLE){
    Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, value, "A double expression");
    m_Type = INT;
    m_Symbol = NULL;
  }
  else if (e->get_gType() == STRING){
    Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, value, "A string expression");
    m_Type = INT;
    m_Symbol = NULL;

  }
  m_Type = INT;
  
  
  m_sValue = value;
  m_Expression = e;
}

int Variable::getiValue()
{
  if(m_Symbol != NULL){
    return m_Symbol->getintValue();
  }
  else{
    return 0;
  }
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
