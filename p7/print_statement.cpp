#include "print_statement.h"

Print_Statement::Print_Statement() : Statement()
{
  m_line_number = 0;
  m_expression = NULL;
}

void Print_Statement::print(int line_number, Expression *expression)
{
  cout << "gpl[" << line_number << "]: " << expression->evalstring() << endl;
}