#include "for_statement.h"

For_Statement::For_Statement(Statement_block *first_condition, Expression* second_condition, Statement_block *third_condition) : Statement()
{
    m_first_condition = first_condition;
    m_second_condition = second_condition;
    m_third_condition = third_condition;
}
void For_Statement::execute()
{
    for(m_first_condition; m_second_condition; m_third_condition)
      {
        
      }
}