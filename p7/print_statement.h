#ifndef PRINT_STATEMENT_H
#define PRINT_STATEMENT_H

#include "statement.h"
#include "expression.h"

class Print_Statement : public Statement
{
public:
  Print_Statement();
  virtual void execute();
  void print(int linenumber, Expression *exp);
private:
  int m_line_number;
  Expression m_expression;
};

#endif