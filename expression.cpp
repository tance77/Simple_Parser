#include "expression.h"
#include "variable.h"

iExpression::iExpression(int a, Gpl_type type)
{
    mValue = a;
    m_Type = type;
}

dExpression::dExpression(double d, Gpl_type type)
{
    mValue = d;
    m_Type = type;
}

sExpression::sExpression(std::string *s, Gpl_type gType)
{
    mValue = s;
    m_Type = gType;    
}

uExpression::uExpression(Operator_type type, Expression *RHS)
{
    m_LHS = NULL;
    m_RHS = RHS;
    m_oType = type;
}

bExpression::bExpression(Operator_type oType, Expression *LHS, Expression *RHS)
{
    m_LHS = LHS;
    m_RHS = RHS;
    m_oType = oType;
}
vExpression::vExpression(Variable *var)
{
    m_Variable = var;
}
