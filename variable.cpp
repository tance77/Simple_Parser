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
    m_iValue = target->getintValue();
    m_dValue = target->getdoubleValue();
    m_sValue = target->getstringValue();
    m_Type = m_Symbol->getType();
  }
    // else{
    //m_sValue = getsValue();
    // m_Symbol = new Symbol(INT, m_sValue, 0);
    //m_Expression = NULL;
    //m_Type = INT;
    //}
}
Variable::Variable(std::string value, Expression *e) //array
{
  if(e->get_gType()== INT){
    m_Symbol = TheTable->lookup(value + "[0]");
    if(m_Symbol == NULL){
      m_Symbol = new Symbol(INT, value, 0);
      Error::error(Error::UNDECLARED_VARIABLE, value);
    }
    else{
      m_Expression = e;
      m_Type = m_Symbol->getType();
    }
    
  }
  else if(e->get_gType() == DOUBLE){
    ostringstream ss;
    ss << e->evaldouble();
    m_sValue = value;
    Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, value, "A double expression");
    m_Symbol = TheTable->lookup(value);
    m_Expression = new Expression(0.0,DOUBLE);
    m_Type = m_Expression->get_gType();
    
  }
  else if (e->get_gType() == STRING){
    Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, value, "A string expression");
    m_sValue = value;
    m_Symbol = TheTable->lookup(value);
    m_Expression = new Expression("0", STRING);
    m_Type = m_Expression->get_gType();
    
    
  }
    //  m_Type = INT;
  
  
    //m_sValue = value;
    //m_Expression = e;
}

int Variable::getiValue()
{
  cout << "getivalue()\n";
       if(m_Symbol != NULL){
       return m_Symbol->getintValue();
        }
//        else{
//        return 0;
//        }
//  if(m_Expression == NULL)
//    {
//    if(m_Symbol == NULL)
//      {
//      Error::error(Error::UNDECLARED_VARIABLE, m_sValue);
//      return 0;
//      }
//    }
  else
    {
    assert(m_Expression);
    stringstream ss;
    ss << m_Expression->evalint();
    Symbol* sym = TheTable->lookup(m_sValue + '[' + ss.str() + ']');
    
    cout << "right place sym = " << (void *) sym << endl;
    if(sym == NULL)
      {
      stringstream ss2;
      ss2 << m_Expression->evalint();
            Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS, m_sValue, ss2.str());
      }
    else
      {
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
