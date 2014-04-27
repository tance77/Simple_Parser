#include "for_statement.h"

For_Statement::For_Statement(Statement_block *first_condition,
                             Expression* second_condition,
                             Statement_block *third_condition,
                             Statement_block* junk_in_loop) : Statement()
{
    m_first_condition = first_condition;
    m_second_condition = second_condition;
    m_third_condition = third_condition;
    m_stuff_in_for_loop = junk_in_loop;
}
void For_Statement::execute()
{
    for(m_first_condition; m_second_condition->evalint(); m_third_condition)
      {
        m_stuff_in_for_loop->execute();
      }
}