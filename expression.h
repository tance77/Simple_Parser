#ifndef expression_h
#define expression_H

#include <string>
#include "variable.h"
#include "gpl_type.h"

class Expression
{
    public:
    Expression(Variable *variable){};
    Expression(int value){};
    Expression(Operator_type oType, Expression *lhs, Expression *rhs){m_oType = oType, m_lhs = lhs, m_rhs = rhs};
    //Expression(){Operator_type oType, Expression *lhs, Expression *rhs };
   // Expression(){Operator_type oType, Expression *lhs, Expression *rhs };
    private:
    Variable *m_vVariable;
    int m_iValue;
    Operator_type m_oType;
    Expression *m_lhs;
    Expression *m_rhs;
};

#define
