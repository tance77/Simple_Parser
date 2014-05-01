#ifndef PRINT_STATEMENT_H
#define PRINT_STATEMENT_H

#include "statement.h"
#include "expression.h"

class Print_Statement : public Statement
{
public:
  Print_Statement(int linenumber, Expression *exp);
  virtual void execute();
private:
  int m_line_number;
  Expression *m_expression;
};

#endif