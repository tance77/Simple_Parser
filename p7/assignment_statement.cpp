#include "assignment_statement.h"

Assignment_Statement::Assignment_Statement(Expression *expr, Operator_type oType, Variable* var) : Statement()
{
    m_expression = expr;
    m_variable = var;
    m_oType = oType;
}
void Assignment_Statement::execute()
{
    if(m_expression->get_gType() == INT)
      {
        switch(m_oType)
        {
            case ASSIGN:
              m_variable->set(m_expression->evalint());
              break;
              
            case PLUS_ASSIGN:
              m_variable->set(m_variable->getiValue() + m_expression->evalint());
              break;
              
            case MINUS_ASSIGN:
              m_variable->set(m_variable->getiValue() - m_expression->evalint());
              break;
              
            default:
              break;
              
        }
      }
    else if(m_expression->get_gType() == DOUBLE)
      {
        switch(m_oType)
        {
            case ASSIGN:
              m_variable->set(m_expression->evaldouble());
              break;
              
            case PLUS_ASSIGN:
              m_variable->set(m_variable->getdValue() + m_expression->evaldouble());
              break;
              
            case MINUS_ASSIGN:
              m_variable->set(m_variable->getdValue() - m_expression->evaldouble());
              break;
              
            default:
              break;
              
        }
      }
    else if(m_expression->get_gType() == STRING)
      {
        switch(m_oType)
        {
            case ASSIGN:
              m_variable->set(m_expression->evalstring());
              break;
              
            case PLUS_ASSIGN:
              m_variable->set(m_variable->getsValue() + m_expression->evalstring());
              break;
              
            case MINUS_ASSIGN:
                  //error
              break;
              
            default:
              break;
              
        }
      }
    else if(m_expression->get_gType() == GAME_OBJECT)
      {
        switch(m_oType)
        {
            case ASSIGN:
                  // m_variable->set(m_expression->get_Animation());
              break;
              
            case PLUS_ASSIGN:
                  //   m_variable->set(m_variable->getAnimate() + m_expression->get_Animation());
              break;
              
            case MINUS_ASSIGN:
                  // m_variable->set(m_variable->getAnimate() - m_expression->get_Animation());
              break;
              
            default:
              break;
              
        }
      }
}