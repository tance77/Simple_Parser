#ifndef EXIT_STATEMENT_H
#define EXIT_STATEMENT_H

#include "statement.h"

class Exit_Statement : public Statement
{
public:
    Exit_Statement(Expression*, int);
  virtual void execute();
private:
    int m_line;
    Expression* m_expression;
};

#endif