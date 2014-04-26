#ifndef IF_STATEMENT_H
#define IF_STATEMENT_H

#include "statement.h"
#include "statement_block.h"

class If_Statement : public Statement
{
public:
    If_Statement(Expression*, Statement_block*);
  virtual void execute();
private:
    Expression *m_expression;
    Statement_block *m_stmtblock;
};

#endif