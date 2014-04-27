#include "assignment_statement.h"

Assignment_Statement::Assignment_Statement(Expression *expr, Operator_type oType, Variable* var) : Statement()
{
    m_expression = expr;
    m_variable = var;
    m_oType = oType;
    m_gType = expr->get_gType();
}
void Assignment_Statement::execute()
{
    if(m_gType == INT)
      {
        switch(m_oType)
        {
            case ASSIGN:
              if(m_variable->get_symbol()) //Means you are just a variable like int x
                  m_variable->set(m_expression->evalint());
              else if(m_variable->get_symbol() == false) //Means you have an expression attached to you
                {
                  
                }
              break;
              
            case PLUS_ASSIGN:
                  //  m_variable->set(m_variable->getiValue() + m_expression->evalint());
              break;
              
            case MINUS_ASSIGN:
                  //  m_variable->set(m_variable->getiValue() - m_expression->evalint());
              break;
              
            default:
              break;
              
        }
      }
    else if(m_gType == DOUBLE)
      {
        switch(m_oType)
        {
            case ASSIGN:
                  //    m_variable->set(m_expression->evaldouble());
              break;
              
            case PLUS_ASSIGN:
                  //   m_variable->set(m_variable->getdValue() + m_expression->evaldouble());
              break;
              
            case MINUS_ASSIGN:
                  //   m_variable->set(m_variable->getdValue() - m_expression->evaldouble());
              break;
              
            default:
              break;
              
        }
      }
    else if(m_gType == STRING)
      {
        switch(m_oType)
        {
            case ASSIGN:
                  //m_variable->set(m_expression->evalstring());
              break;
              
            case PLUS_ASSIGN:
                  // m_variable->set(m_variable->getsValue() + m_expression->evalstring());
              break;
              
            case MINUS_ASSIGN:
                  //error
              break;
              
            default:
              break;
              
        }
      }
    else if(m_gType == GAME_OBJECT)
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