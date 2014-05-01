  #include "expression.h"
#include "variable.h"
#include "gpl_assert.h"
#include <stdio.h>
#include <stdlib.h>


Expression::Expression(Operator_type type, Expression *LHS, Expression *RHS)
{
    m_oType = type;
    m_kind = "EXPRESSION";
    m_LHS = LHS;
    m_RHS = RHS;
    m_Variable = NULL;
    if(type == OR || type == AND || type == GREATER_THAN || type == GREATER_THAN_EQUAL || type == LESS_THAN_EQUAL || type == LESS_THAN || type == EQUAL || type == NOT_EQUAL || type == NEAR || type == TOUCHES){
        m_gType = INT;
    }
    else if((m_LHS->get_gType() == STRING || m_RHS->get_gType() == STRING))
        m_gType = STRING;
    else if(m_LHS->get_gType() == DOUBLE || m_RHS->get_gType() == DOUBLE)
        m_gType = DOUBLE;
    else
        m_gType = INT;
}
Expression::Expression(Operator_type type, Expression *RHS)
{
    m_oType = type;
    m_kind = "EXPRESSION";
    m_LHS = NULL;
    m_RHS = RHS;
    m_Variable = NULL;
    if(type == FLOOR){
        m_gType = INT;
    }
    else if(type == SIN || type == COS || type == TAN || type == ASIN || type == ACOS || type == ATAN || type == SQRT){
        m_gType = DOUBLE;
    }
    else if(type == ABS || type == UNARY_MINUS){
        m_gType = m_RHS->get_gType();
    }
    else if(type == NOT)
        m_gType = INT;
}

int Expression::evalint()
{
        //assert(m_gType == INT);
    if(m_kind == "VARIABLE")
        return m_Variable->getiValue();
    else if(m_kind == "INT_CONSTANT")
        return m_iValue;
    else{
        switch (m_oType) {
            case GARBAGE:
                cout << "Hell Froze Over!" << endl;
            case AND:
                if(m_LHS->get_gType() == INT && m_RHS->get_gType() == INT)
                    return m_LHS->evalint() && m_RHS->evalint();
                else if(m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == DOUBLE)
                    return m_LHS->evaldouble() && m_RHS->evaldouble();
                else if(m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == INT)
                    return m_LHS->evaldouble() && m_RHS->evalint();
                else if(m_LHS->get_gType() == INT && m_RHS->get_gType() == DOUBLE)
                    return m_LHS->evalint() && m_RHS->evaldouble();
            case OR:
                if(m_LHS->get_gType() == INT && m_RHS->get_gType() == INT)
                    return m_LHS->evalint() || m_RHS->evalint();
                else if(m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == DOUBLE)
                    return m_LHS->evaldouble() || m_RHS->evaldouble();
                else if(m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == INT)
                    return m_LHS->evaldouble() || m_RHS->evalint();
                else if(m_LHS->get_gType() == INT && m_RHS->get_gType() == DOUBLE)
                    return m_LHS->evalint() || m_RHS->evaldouble();
            case LESS_THAN_EQUAL:
                if (m_LHS->get_gType() == STRING && m_RHS->get_gType() == STRING)
                    return m_LHS->evalstring() <= m_RHS->evalstring();
                else if(m_LHS->get_gType() == INT && m_RHS->get_gType() == STRING)
                  {
                    ostringstream ss;
                    ss << m_LHS->evalint();
                    return ss.str() <= m_RHS->evalstring();
                  }
                else if(m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == STRING)
                  {
                    ostringstream ss;
                    ss << m_LHS->evaldouble();
                    return ss.str() <= m_RHS->evalstring();
                  }
                else if(m_LHS->get_gType() == STRING && m_RHS->get_gType() == INT)
                  {
                    ostringstream ss;
                    ss << m_RHS->evalint();
                    return m_LHS->evalstring() <= ss.str();
                  }
                else if(m_LHS->get_gType() == STRING && m_RHS->get_gType() == DOUBLE)
                  {
                    ostringstream ss;
                    ss << m_RHS->evaldouble();
                    return m_LHS->evalstring() <= ss.str();
                  }
                else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == DOUBLE)
                    return (m_LHS->evaldouble() <= m_RHS->evaldouble());
                else if(m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == INT)
                    return m_LHS->evaldouble() <= m_RHS->evalint();
                else if(m_LHS->get_gType() == INT && m_RHS->get_gType() == DOUBLE)
                    return m_LHS->evalint() <= m_RHS->evaldouble();
                else if (m_LHS->get_gType() == INT && m_RHS->get_gType() == INT)
                    return (m_LHS->evalint() <= m_RHS->evalint());
            case LESS_THAN:
                if (m_LHS->get_gType() == STRING && m_RHS->get_gType() == STRING)
                    return m_LHS->evalstring() < m_RHS->evalstring();
                else if(m_LHS->get_gType() == INT && m_RHS->get_gType() == STRING)
                  {
                    ostringstream ss;
                    ss << m_LHS->evalint();
                    return ss.str() < m_RHS->evalstring();
                  }
                else if(m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == STRING)
                  {
                    ostringstream ss;
                    ss << m_LHS->evaldouble();
                    return ss.str() < m_RHS->evalstring();
                  }
                else if(m_LHS->get_gType() == STRING && m_RHS->get_gType() == INT)
                  {
                    ostringstream ss;
                    ss << m_RHS->evalint();
                    return m_LHS->evalstring() < ss.str();
                  }
                else if(m_LHS->get_gType() == STRING && m_RHS->get_gType() == DOUBLE)
                  {
                    ostringstream ss;
                    ss << m_RHS->evaldouble();
                    return m_LHS->evalstring() < ss.str();
                  }
                else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == DOUBLE)
                    return (m_LHS->evaldouble() < m_RHS->evaldouble());
                else if(m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == INT)
                    return m_LHS->evaldouble() < m_RHS->evalint();
                else if(m_LHS->get_gType() == INT && m_RHS->get_gType() == DOUBLE)
                    return m_LHS->evalint() < m_RHS->evaldouble();
                else if (m_LHS->get_gType() == INT && m_RHS->get_gType() == INT)
                    return (m_LHS->evalint() < m_RHS->evalint());
            case GREATER_THAN_EQUAL:
                if (m_LHS->get_gType() == INT && m_RHS->get_gType() == INT)
                    return (m_LHS->evalint() >= m_RHS->evalint());
                else if (m_LHS->get_gType() == STRING && m_RHS->get_gType() == STRING)
                    return m_LHS->evalstring() >= m_RHS->evalstring();
                else if(m_LHS->get_gType() == INT && m_RHS->get_gType() == STRING)
                  {
                    ostringstream ss;
                    ss << m_LHS->evalint();
                    return ss.str() >= m_RHS->evalstring();
                  }
                else if(m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == STRING)
                  {
                    ostringstream ss;
                    ss << m_LHS->evaldouble();
                    return ss.str() >= m_RHS->evalstring();
                  }
                else if(m_LHS->get_gType() == STRING && m_RHS->get_gType() == INT)
                  {
                    ostringstream ss;
                    ss << m_RHS->evalint();
                    return m_LHS->evalstring() >= ss.str();
                  }
                else if(m_LHS->get_gType() == STRING && m_RHS->get_gType() == DOUBLE)
                  {
                    ostringstream ss;
                    ss << m_RHS->evaldouble();
                    return m_LHS->evalstring() >= ss.str();
                  }
                else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == DOUBLE)
                    return (m_LHS->evaldouble() >= m_RHS->evaldouble());
                else if(m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == INT)
                    return m_LHS->evaldouble() >= m_RHS->evalint();
                else if(m_LHS->get_gType() == INT && m_RHS->get_gType() == DOUBLE)
                    return m_LHS->evalint() >= m_RHS->evaldouble();
            case GREATER_THAN:
                if (m_LHS->get_gType() == STRING && m_RHS->get_gType() == STRING)
                    return m_LHS->evalstring() > m_RHS->evalstring();
                else if(m_LHS->get_gType() == INT && m_RHS->get_gType() == STRING)
                  {
                    ostringstream ss;
                    ss << m_LHS->evalint();
                    return ss.str() > m_RHS->evalstring();
                  }
                else if(m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == STRING)
                  {
                    ostringstream ss;
                    ss << m_LHS->evaldouble();
                    return ss.str() > m_RHS->evalstring();
                  }
                else if(m_LHS->get_gType() == STRING && m_RHS->get_gType() == INT)
                  {
                    ostringstream ss;
                    ss << m_RHS->evalint();
                    return m_LHS->evalstring() > ss.str();
                  }
                else if(m_LHS->get_gType() == STRING && m_RHS->get_gType() == DOUBLE)
                  {
                    ostringstream ss;
                    ss << m_RHS->evaldouble();
                    return m_LHS->evalstring() > ss.str();
                  }
                else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == DOUBLE)
                    return (m_LHS->evaldouble() > m_RHS->evaldouble());
                else if(m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == INT)
                    return m_LHS->evaldouble() > m_RHS->evalint();
                else if(m_LHS->get_gType() == INT && m_RHS->get_gType() == DOUBLE)
                    return m_LHS->evalint() > m_RHS->evaldouble();
                else if (m_LHS->get_gType() == INT && m_RHS->get_gType() == INT)
                    return (m_LHS->evalint() > m_RHS->evalint());
                
            case EQUAL:
                if (m_LHS->get_gType() == STRING && m_RHS->get_gType() == STRING)
                    return m_LHS->evalstring() == m_RHS->evalstring();
                else if(m_LHS->get_gType() == INT && m_RHS->get_gType() == STRING)
                  {
                    ostringstream ss;
                    ss << m_LHS->evalint();
                    return ss.str() == m_RHS->evalstring();
                  }
                else if(m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == STRING)
                  {
                    ostringstream ss;
                    ss << m_LHS->evaldouble();
                    return ss.str() == m_RHS->evalstring();
                  }
                else if(m_LHS->get_gType() == STRING && m_RHS->get_gType() == INT)
                  {
                    ostringstream ss;
                    ss << m_RHS->evalint();
                    return m_LHS->evalstring() == ss.str();
                  }
                else if(m_LHS->get_gType() == STRING && m_RHS->get_gType() == DOUBLE)
                  {
                    ostringstream ss;
                    ss << m_RHS->evaldouble();
                    return m_LHS->evalstring() == ss.str();
                  }
                else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == DOUBLE)
                    return (m_LHS->evaldouble() == m_RHS->evaldouble());
                else if(m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == INT)
                    return m_LHS->evaldouble() == m_RHS->evalint();
                else if(m_LHS->get_gType() == INT && m_RHS->get_gType() == DOUBLE)
                    return m_LHS->evalint() == m_RHS->evaldouble();
                else if (m_LHS->get_gType() == INT && m_RHS->get_gType() == INT)
                    return (m_LHS->evalint() == m_RHS->evalint());
                
            case NOT_EQUAL:
                if (m_LHS->get_gType() == STRING && m_RHS->get_gType() == STRING)
                    return m_LHS->evalstring() != m_RHS->evalstring();
                else if(m_LHS->get_gType() == INT && m_RHS->get_gType() == STRING)
                  {
                    ostringstream ss;
                    ss << m_LHS->evalint();
                    return ss.str() != m_RHS->evalstring();
                  }
                else if(m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == STRING)
                  {
                    ostringstream ss;
                    ss << m_LHS->evaldouble();
                    return ss.str() != m_RHS->evalstring();
                  }
                else if(m_LHS->get_gType() == STRING && m_RHS->get_gType() == INT)
                  {
                    ostringstream ss;
                    ss << m_RHS->evalint();
                    return m_LHS->evalstring() != ss.str();
                  }
                else if(m_LHS->get_gType() == STRING && m_RHS->get_gType() == DOUBLE)
                  {
                    ostringstream ss;
                    ss << m_RHS->evaldouble();
                    return m_LHS->evalstring() != ss.str();
                  }
                else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == DOUBLE)
                    return (m_LHS->evaldouble() != m_RHS->evaldouble());
                else if(m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == INT)
                    return m_LHS->evaldouble() != m_RHS->evalint();
                else if(m_LHS->get_gType() == INT && m_RHS->get_gType() == DOUBLE)
                    return m_LHS->evalint() != m_RHS->evaldouble();
                else if (m_LHS->get_gType() == INT && m_RHS->get_gType() == INT)
                    return (m_LHS->evalint() != m_RHS->evalint());
                
            case PLUS:
                if (m_LHS->get_gType() == INT && m_RHS->get_gType() == INT)
                    return m_LHS->evalint() + m_RHS->evalint();
                else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == INT)
                    return m_LHS->evaldouble() + m_RHS->evalint();
                else if (m_LHS->get_gType() == INT && m_RHS->get_gType() == DOUBLE)
                    return m_LHS->evalint() + m_RHS->evaldouble();
                else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == DOUBLE)
                    return m_LHS->evaldouble() + m_RHS->evaldouble();
                
            case MINUS:
                if (m_LHS->get_gType() == INT && m_RHS->get_gType() == INT)
                    return m_LHS->evalint() - m_RHS->evalint();
                else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == INT)
                    return m_LHS->evaldouble() - m_RHS->evalint();
                else if (m_LHS->get_gType() == INT && m_RHS->get_gType() == DOUBLE)
                    return m_LHS->evalint() - m_RHS->evaldouble();
                else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == DOUBLE)
                    return m_LHS->evaldouble() - m_RHS->evaldouble();
                
            case MULTIPLY:
                if (m_LHS->get_gType() == INT && m_RHS->get_gType() == INT)
                    return m_LHS->evalint() * m_RHS->evalint();
                else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == INT)
                    return (int) (m_LHS->evaldouble() * m_RHS->evalint());
                else if (m_LHS->get_gType() == INT && m_RHS->get_gType() == DOUBLE)
                    return m_LHS->evalint() * m_RHS->evaldouble();
                else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == DOUBLE)
                    return m_LHS->evaldouble() * m_RHS->evaldouble();
                
            case DIVIDE:
                if (m_LHS->get_gType() == INT && m_RHS->get_gType() == INT)
                    return m_LHS->evalint() / m_RHS->evalint();
                else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == INT)
                    return m_LHS->evaldouble() / m_RHS->evalint();
                else if (m_LHS->get_gType() == INT && m_RHS->get_gType() == DOUBLE)
                    return m_LHS->evalint() / m_RHS->evaldouble();
                else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == DOUBLE)
                    return m_LHS->evaldouble() / m_RHS->evaldouble();
            case MOD:
                return m_LHS->evalint() % m_RHS->evalint();
            case ABS:
                if(m_RHS->get_gType() == INT)
                    return abs(m_RHS->evalint());
                else
                    return fabs(m_RHS->evaldouble());
            case FLOOR:
                if(m_RHS->get_gType() == DOUBLE){
                    return (int)floor(m_RHS->evaldouble());
                }
                return floor(m_RHS->evalint());
            case UNARY_MINUS:
                if(m_RHS->get_gType()== DOUBLE){
                    return m_RHS->evaldouble();
                }
                else if(m_RHS->get_gType()==INT){
                    return m_RHS->evalint() * -1;
                }
            case RANDOM:
                return rand() % m_RHS->evalint();
            case NOT:
                if(m_RHS->get_gType() == DOUBLE){
                    return !m_RHS->evaldouble();
                }
                return !m_RHS->evalint();
            case NEAR:
                return m_RHS->evalint();
            case TOUCHES:
                return m_RHS->evalint();
            default:
                return m_iValue;
        }
    }
}
double Expression::evaldouble()
{
    if(m_gType == INT)
        return (double) evalint();
    
    if(m_kind == "VARIABLE")
        return m_Variable->getdValue();
    else if(m_kind == "DOUBLE_CONSTANT")
        return m_dValue;
        //    else if(m_kind == "")
        //        return m_RHS->evaldouble();
    switch (m_oType) {
        case SIN:
            if(m_RHS->get_gType() == INT)
                return (double) (sin(m_RHS->evalint() * (M_PI / 180)));
            else
                return  (double) (sin(m_RHS->evaldouble()* (M_PI / 180)));
        case COS:
            if(m_RHS->get_gType() == INT)
                return (double) (cos(m_RHS->evalint() * (M_PI / 180)));
            else
                return (double) (cos(m_RHS->evaldouble()* (M_PI / 180)));
        case TAN:
            if(m_RHS->get_gType() == INT)
                return tan(m_RHS->evalint() * (M_PI / 180));
            else
                return tan(m_RHS->evaldouble()* (M_PI / 180));
        case ASIN:
            if(m_RHS->get_gType() == INT)
                return asin(m_RHS->evalint()) * (180 / M_PI);
            else
                return asin(m_RHS->evaldouble()) * (180 / M_PI);
        case ACOS:
            if(m_RHS->get_gType() == INT)
                return acos(m_RHS->evalint()) * (180 / M_PI);
            else
                return acos(m_RHS->evaldouble()) * (180 / M_PI);
        case ATAN:
            if(m_RHS->get_gType() == INT)
                return atan(m_RHS->evalint()) * (180 / M_PI);
            else
                return atan(m_RHS->evaldouble()) * (180 / M_PI);
        case SQRT:
            if(m_RHS->get_gType() == DOUBLE){
                return sqrt(m_RHS->evaldouble());
            }
            else if(m_RHS->get_gType() == INT){
                return sqrt(m_RHS->evalint());
            }
        case ABS:
            if(m_RHS->get_gType() == DOUBLE)
                return abs(m_RHS->evaldouble());
            else
                return abs(m_RHS->evalint());
            
        case FLOOR:
            return floor(m_RHS->evaldouble());
        case UNARY_MINUS:
            return m_RHS->evaldouble() * -1;
        case NOT:
            return !m_RHS->evaldouble();
        case PLUS:
            if (m_LHS->get_gType() == INT && m_RHS->get_gType() == INT)                         //Left is INT right is INT
                return (double)m_LHS->evalint() + (double)m_RHS->evalint();
            else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == INT)                 //Left is DOUBLE right is INT
                return m_LHS->evaldouble() + m_RHS->evalint();
            else if (m_LHS->get_gType() == INT && m_RHS->get_gType() == DOUBLE)                 //Left is INT right is DOUBLE
                return (double)m_LHS->evalint() + m_RHS->evaldouble();
            else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == DOUBLE)              //Left is DOUBLE right is DOUBLE
                return m_LHS->evaldouble() + m_RHS->evaldouble();
            return m_LHS->evaldouble() + m_RHS->evaldouble();
        case MINUS:
            if (m_LHS->get_gType() == INT && m_RHS->get_gType() == INT)                         //Left is INT right is INT
                return (double)m_LHS->evalint() - (double)m_RHS->evalint();
            else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == INT)                 //Left is DOUBLE right is INT
                return m_LHS->evaldouble() - m_RHS->evalint();
            else if (m_LHS->get_gType() == INT && m_RHS->get_gType() == DOUBLE)                 //Left is INT right is DOUBLE
                return (double)m_LHS->evalint() - m_RHS->evaldouble();
            else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == DOUBLE)              //Left is DOUBLE right is DOUBLE
                return m_LHS->evaldouble() - m_RHS->evaldouble();
            return m_LHS->evaldouble() - m_RHS->evaldouble();
        case MULTIPLY:
            if (m_LHS->get_gType() == INT && m_RHS->get_gType() == INT)                         //Left is INT right is INT
                return (double)m_LHS->evalint() * (double)m_RHS->evalint();
            else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == INT)                 //Left is DOUBLE right is INT
                return m_LHS->evaldouble() * m_RHS->evalint();
            else if (m_LHS->get_gType() == INT && m_RHS->get_gType() == DOUBLE)                 //Left is INT right is DOUBLE
                return (double)m_LHS->evalint() * m_RHS->evaldouble();
            else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == DOUBLE)              //Left is DOUBLE right is DOUBLE
                return m_LHS->evaldouble() * m_RHS->evaldouble();
            return m_LHS->evaldouble() * m_RHS->evaldouble();
        case DIVIDE:
            if (m_LHS->get_gType() == INT && m_RHS->get_gType() == INT)                         //Left is INT right is INT
                return (double)m_LHS->evalint() / (double)m_RHS->evalint();
            else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == INT)                 //Left is DOUBLE right is INT
                return m_LHS->evaldouble() / m_RHS->evalint();
            else if (m_LHS->get_gType() == INT && m_RHS->get_gType() == DOUBLE)                 //Left is INT right is DOUBLE
                return (double)m_LHS->evalint() / m_RHS->evaldouble();
            else if (m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == DOUBLE)              //Left is DOUBLE right is DOUBLE
                return m_LHS->evaldouble() / m_RHS->evaldouble();
            return m_LHS->evaldouble() / m_RHS->evaldouble();
        default:
            return m_dValue;
    }
}
std::string Expression::evalstring()
{
    if(m_gType == INT)
      {
        stringstream ss;
        ss << evalint();
        return ss.str();
      }
    else if(m_gType == DOUBLE)
      {
        stringstream ss;
        ss << evaldouble();
        return ss.str();
      }
    else //you are a string
        if(m_kind == "VARIABLE")
            return m_Variable->getsValue();
        else if(m_oType == GARBAGE)
            return m_sValue;
        else
          {
            switch (m_oType) {
                case NOT:
                    if(m_RHS->get_gType() == INT)
                      {
                        ostringstream ss;
                        ss << !m_RHS->evalint();
                        return ss.str();
                      }
                    else if(m_RHS->get_gType() == DOUBLE)
                      {
                        ostringstream ss;
                        ss << !m_RHS->evaldouble();
                        return ss.str();
                      }
                case UNARY_MINUS:
                    if(m_RHS->get_gType() == INT)
                      {
                        ostringstream ss;
                        ss << m_RHS->evalint() * -1;
                        return ss.str();
                      }
                    else if(m_RHS->get_gType() == DOUBLE)
                      {
                        ostringstream ss;
                        ss << m_RHS->evaldouble() * -1;
                        return ss.str();
                      }
                case SIN:
                    if(m_RHS->get_gType() == INT)
                      {
                        ostringstream ss;
                        ss << (sin(m_RHS->evalint() * (M_PI / 180)));
                        return ss.str();
                      }
                    else
                      {
                        ostringstream ss;
                        ss << (sin(m_RHS->evaldouble() * (M_PI / 180)));
                        return ss.str();
                      }
                case COS:
                    if(m_RHS->get_gType() == INT)
                      {
                        ostringstream ss;
                        ss << (cos(m_RHS->evalint() * (M_PI / 180)));
                        return ss.str();
                      }
                    else
                      {
                        ostringstream ss;
                        ss << (cos(m_RHS->evaldouble() * (M_PI / 180)));
                        return ss.str();
                      }
                case TAN:
                    if(m_RHS->get_gType() == INT)
                      {
                        ostringstream ss;
                        ss << (tan(m_RHS->evalint() * (M_PI / 180)));
                        return ss.str();
                      }
                    else
                      {
                        ostringstream ss;
                        ss << (tan(m_RHS->evaldouble() * (M_PI / 180)));
                        return ss.str();
                      }
                case ASIN:
                    if(m_RHS->get_gType() == INT)
                      {
                        ostringstream ss;
                        ss << asin(m_RHS->evalint()) * (180 / M_PI);
                        return ss.str();
                      }
                    else
                      {
                        ostringstream ss;
                        ss << asin(m_RHS->evaldouble()) * (180 / M_PI);
                        return ss.str();
                      }
                case ACOS:
                    if(m_RHS->get_gType() == INT)
                      {
                        ostringstream ss;
                        ss << acos(m_RHS->evalint()) * (180 / M_PI);
                        return ss.str();
                      }
                    else
                      {
                        ostringstream ss;
                        ss << acos(m_RHS->evaldouble()) * (180 / M_PI);
                        return ss.str();
                      }
                case ATAN:
                    if(m_RHS->get_gType() == INT)
                      {
                        ostringstream ss;
                        ss << atan(m_RHS->evalint()) * (180 / M_PI);
                        return ss.str();
                      }
                    else
                      {
                        ostringstream ss;
                        ss << atan(m_RHS->evaldouble()) * (180 / M_PI);
                        return ss.str();
                      }
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
                        return ss.str();
                      }
                    else if(m_LHS->get_gType() == STRING && m_RHS->get_gType() == INT)          // LEFT IS A STRING RIGHT IS A STRING
                      {
                        ostringstream ss;
                        ss << m_LHS->evalstring();
                        ss << m_RHS->evalint();
                        return ss.str();
                      }
                    else if(m_LHS->get_gType() == STRING && m_RHS->get_gType() == DOUBLE)       // LEFT IS A STRING RIGHT IS A DOUBLE
                      {
                        ostringstream ss;
                        ss << m_LHS->evalstring();
                        ss << m_RHS->evaldouble();
                        return ss.str();
                      }
                    else if(m_LHS->get_gType() == INT && m_RHS->get_gType() == STRING)          // LEFT IS AN INT RIGHT IS A STRING
                      {
                        ostringstream ss;
                        ss << m_LHS->evalint();
                        ss << m_RHS->evalstring();
                        return ss.str();
                      }
                    else if(m_LHS->get_gType() == DOUBLE && m_RHS->get_gType() == STRING)       // LEFT IS A DOUBLE RIGHT IS A STRING
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
        return m_gType; //your a constant hopefully
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
std::string Expression::get_Kind()
{
    if(m_kind == "VARIABLE")
      {
        
      }
    return m_kind;
}
Animation_block* Expression::get_Animation()
{
    return m_Variable->getAnimate();
}
Expression* Expression::getLHS()
{
    return m_LHS;
}
Expression* Expression::getRHS()
{
    return m_RHS;
}
