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
              break;
              
              case PLUS_ASSIGN:
              break;
              
              case MINUS_ASSIGN:
              break;
              
              default:
              break;
              
        }
      }
    if(m_expression->get_gType() == DOUBLE)
      {
        switch(m_oType)
        {
            case ASSIGN:
              break;
              
            case PLUS_ASSIGN:
              break;
              
            case MINUS_ASSIGN:
              break;
              
            default:
              break;
              
        }
      }
    if(m_expression->get_gType() == STRING)
      {
        switch(m_oType)
        {
            case ASSIGN:
              break;
              
            case PLUS_ASSIGN:
              break;
              
            case MINUS_ASSIGN:
              break;
              
            default:
              break;
              
        }
      }
    if(m_expression->get_gType() == GAME_OBJECT)
      {
        switch(m_oType)
        {
            case ASSIGN:
              break;
              
            case PLUS_ASSIGN:
              break;
              
            case MINUS_ASSIGN:
              break;
              
            default:
              break;
              
        }
      }
}