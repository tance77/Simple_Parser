#ifndef STATEMENT_H
#define STATEMENT_H

#include "expression.h"

class Statement
{
public:
  Statement();
  virtual void execute() = 0;
private:
};

#endif