#ifndef ASSIGNMENT_STATEMENT_H
#define ASSIGNMENT_STATEMENT_H

#include "statement.h"

class Assignment_Statement : public Statement
{
public:
    Assignment_Statement(Expression*, Operator_type, Variable*);
  virtual void execute();
private:
    Variable *m_variable;
    Expression *m_expression;
    Operator_type m_oType;
    Gpl_type m_gType;
};

#endif