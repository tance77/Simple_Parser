#include <stdlib.h>
#include "exit_statement.h"

Exit_Statement::Exit_Statement(Expression* expr, int line) : Statement()
{
    m_expression = expr;
    m_line = line;
}
void Exit_Statement::execute()
{

    if(m_expression->get_gType() == INT)
      {
        cout << "gpl[" << m_line << "]: exit(" << m_expression->evalint() << ")" << endl;
        exit(m_expression->evalint());
      }
            //if not an int probably error
}
