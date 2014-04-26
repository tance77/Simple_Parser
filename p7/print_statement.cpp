#include "print_statement.h"

Print_Statement::Print_Statement(int linenumber, Expression *expr) : Statement()
{
  m_line_number = linenumber;
  m_expression = expr;
}

void Print_Statement::execute()
{
  cout << "gpl[" << m_line_number << "]: " << m_expression->evalstring() << endl;
}