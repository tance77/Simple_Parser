#include "expression.h"
#include "variable.h"
#include "gpl_assert.h"
#include <sstream>
#include <math.h>

Expression::Expression(Operator_type type, Expression *LHS, Expression *RHS)
{
  m_oType = type,
          m_kind = "EXPRESSION",
          m_LHS = LHS,
          m_RHS = RHS;

  if((m_LHS->get_gType() == STRING || m_RHS->get_gType() == STRING))
    m_gType = STRING;
  else if(m_LHS->get_gType() == DOUBLE || m_RHS->get_gType() == DOUBLE)
    m_gType = DOUBLE;
  else
    m_gType = INT;
}

int Expression::evalint()
{
  //assert(m_gType == INT);
  if(m_kind == "VARIABLE")
    return m_Variable->getiValue();
  if(m_kind == "INT_CONSTANT")
    return m_iValue;
  else{
    switch (m_oType) {
      case OR:
        return m_LHS->evalint() || m_RHS->evalint();
      case AND:
        return m_LHS->evalint() && m_RHS->evalint();
      case LESS_THAN_EQUAL:
        {
          if (m_LHS->m_gType == STRING || m_RHS->m_gType == STRING)
            return m_LHS->evalstring() <= m_RHS->evalstring();
          else if (m_LHS->m_gType == INT || m_RHS->m_gType == INT)
            return (m_LHS->evalint() <= m_RHS->evalint());
          else return (m_LHS->evaldouble() <= m_RHS->evaldouble());
        }
      case LESS_THAN:
        {
          if (m_LHS->m_gType == STRING || m_RHS->m_gType == STRING)
            return m_LHS->evalstring() < m_RHS->evalstring();
          else if (m_LHS->m_gType == INT || m_RHS->m_gType == INT)
            return (m_LHS->evalint() < m_RHS->evalint());
          else return (m_LHS->evaldouble() < m_RHS->evaldouble());
        }
      case GREATER_THAN_EQUAL:
        {
          if (m_LHS->m_gType == STRING || m_RHS->m_gType == STRING)
            return m_LHS->evalstring() >= m_RHS->evalstring();
          else if (m_LHS->m_gType == INT || m_RHS->m_gType == INT)
            return (m_LHS->evalint() >= m_RHS->evalint());
          else return (m_LHS->evaldouble() >= m_RHS->evaldouble());
        }
      case GREATER_THAN:
        {
          if (m_LHS->m_gType == STRING || m_RHS->m_gType == STRING)
            return m_LHS->evalstring() > m_RHS->evalstring();
          else if (m_LHS->m_gType == INT || m_RHS->m_gType == INT)
            return (m_LHS->evalint() > m_RHS->evalint());
          else return (m_LHS->evaldouble() > m_RHS->evaldouble());
        }
      case EQUAL:
        {
          if (m_LHS->m_gType == STRING || m_RHS->m_gType == STRING)
            return m_LHS->evalstring() == m_RHS->evalstring();
          else if (m_LHS->m_gType == INT || m_RHS->m_gType == INT)
            return (m_LHS->evalint() == m_RHS->evalint());
          else return (m_LHS->evaldouble() == m_RHS->evaldouble());
        }
      case NOT_EQUAL:
        {
          if (m_LHS->m_gType == STRING || m_RHS->m_gType == STRING)
            return m_LHS->evalstring() != m_RHS->evalstring();
          else if (m_LHS->m_gType == INT || m_RHS->m_gType == INT)
            return (m_LHS->evalint() != m_RHS->evalint());
          else return (m_LHS->evaldouble() != m_RHS->evaldouble());
        }
      case PLUS: 
        {
          if (m_LHS->m_gType == INT && m_RHS->m_gType == INT)
            return m_LHS->evalint() + m_RHS->evalint();
          else if (m_LHS->m_gType == DOUBLE && m_RHS->m_gType == INT)
            return m_LHS->evaldouble() + m_RHS->evalint();
          else if (m_LHS->m_gType == INT && m_RHS->m_gType == DOUBLE)
            return m_LHS->evalint() + m_RHS->evaldouble();
          else if (m_LHS->m_gType == DOUBLE && m_RHS->m_gType == DOUBLE)
            return m_LHS->evaldouble() + m_RHS->evaldouble();
        }
      case MINUS:
        return m_LHS->evalint() - m_RHS->evalint();
      case MULTIPLY:
        return m_LHS->evalint() * m_RHS->evalint();
      case DIVIDE:
        return m_LHS->evalint() * m_RHS->evalint();
      case MOD:
        return m_LHS->evalint() % m_RHS->evalint();
      default:
        return m_iValue;
    }
  }
}
double Expression::evaldouble()
{
  if(m_kind == "VARIABLE")
    return m_Variable->getdValue();
  else if(m_kind == "DOUBLE_CONSTANT")
    return m_dValue;
  switch (m_oType) {
    case SIN:
      return sin(m_RHS->evaldouble());
    case COS:
      return cos(m_RHS->evaldouble());
    case TAN:
      return tan(m_RHS->evaldouble());
    case ASIN:
      return asin(m_RHS->evaldouble());
    case ACOS:
      return acos(m_RHS->evaldouble());
    case ATAN:
      return atan(m_RHS->evaldouble());
    case PLUS:
    {
      if (m_LHS->m_gType == INT && m_RHS->m_gType == INT)
        return m_LHS->evalint() + m_RHS->evalint();
      else if (m_LHS->m_gType == DOUBLE && m_RHS->m_gType == INT)
        return m_LHS->evaldouble() + m_RHS->evalint();
      else if (m_LHS->m_gType == INT && m_RHS->m_gType == DOUBLE)
        return m_LHS->evalint() + m_RHS->evaldouble();
      else if (m_LHS->m_gType == DOUBLE && m_RHS->m_gType == DOUBLE)
        return m_LHS->evaldouble() + m_RHS->evaldouble();
      return m_LHS->evaldouble() + m_RHS->evaldouble();
    }
    case MINUS:
      return m_LHS->evaldouble() - m_RHS->evaldouble();
    case MULTIPLY:
      return m_LHS->evaldouble() * m_RHS->evaldouble();
    case DIVIDE:
      return m_LHS->evaldouble() * m_RHS->evaldouble();
    default:
      return m_dValue;
  }
}
std::string Expression::evalstring()
{
  if(m_kind == "VARIABLE")
    return m_Variable->getsValue();
  else if(m_oType == GARBAGE)
    return m_sValue;
  else
  {
    switch (m_oType) {

      case PLUS:
        {
          if (m_LHS != NULL && m_RHS != NULL)
          {
            if(m_LHS->get_gType() == INT && m_RHS->get_gType() == INT)                  // CHILDREN ARE BOTH INTS
            {
              ostringstream ss;
              ss << ((m_LHS->evalint() + m_RHS->evalint()));
              return ss.str();
            }
            else if((m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == DOUBLE))     // CHILDREN ARE BOTH DOUBLES
            {
              ostringstream ss;
              ss << ((m_LHS->evaldouble() + m_RHS->evaldouble()));
              return ss.str();
            }
            else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == INT)         // LEFT IS DOUBLE RIGHT IS INT
            {
              ostringstream ss;
              ss << (m_LHS->evaldouble() + m_RHS->evalint());
              return ss.str();
            }
            else if(m_LHS->get_gType() == INT && m_RHS->get_gType() == DOUBLE)          // LEFT IS INT RIGHT IS DOUBLE
            {
              ostringstream ss;
              ss << ((m_LHS->evalint()) + (m_RHS->evaldouble()));
              std::cout << ss.str();
              return ss.str();
            }
            else if(m_LHS->get_gType() == STRING && m_RHS->get_gType() == INT)
            {
              ostringstream ss;
              ss << m_LHS->evalstring();
              ss << m_RHS->evalint();
              return ss.str();
            }
            else if(m_LHS->get_gType() == STRING && m_RHS->get_gType() == DOUBLE)
            {
              ostringstream ss;
              ss << m_LHS->evalstring();
              ss << m_RHS->evaldouble();
              return ss.str();
            }
            else if(m_LHS->get_gType() == INT && m_RHS->get_gType() == STRING)
            {
              ostringstream ss;
              ss << m_LHS->evalint();
              ss << m_RHS->evalstring();
              return ss.str();
            }
            else if(m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == STRING)
            {
              ostringstream ss;
              ss << m_LHS->evaldouble();
              ss << m_RHS->evalstring();
              return ss.str();
            }
            else                                                                        // ELSE YOUR A STRING
              return m_LHS->evalstring() + m_RHS->evalstring();
          }
          return m_LHS->evalstring() + m_RHS->evalstring();                               // ADDING TO STRING CONSTANTS
        }
      default:
        return m_sValue;                                                                // IF THE OPERATOR TYPE WAS SOMEHOW NULL
    }
  }
}
Gpl_type Expression::get_gType()
{
  if(this != NULL)
  {
    if(m_kind == "VARIABLE")
      return m_Variable->gettype();
    else
      return m_gType; //your a constnat at this point hopefully or an EXPRESSION
  }
  else
    return m_gType;
}
Operator_type Expression::get_oType()
{
  return m_oType;
}
int Expression::getiValue()
{
  return m_iValue;
}
double Expression::getdValue()
{
  return m_dValue;
}
std::string Expression::getsValue()
{
  return m_sValue;
}
/*template <typename T>
  std::string NumberToString ( T Number )
  {
  ostringstream ss;
  ss << Number;
  return ss.str();
  }*/
