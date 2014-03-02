#include "expression.h"
#include "variable.h"

iExpression::iExpression(int a, Gpl_type type)
{
    mValue = a;
    m_Type = type;
}

dExpression::dExpression(double d, Gpl_type type)
{
    m_Value = d;
    m_Type = type;
}

sExpression::sExpression(std::string s, Gpl_type gType)
{
    m_Value = s;
    m_Type = gType;    
}

uExpression::uExpression(Operator_type type, Expression *LHS, Expression *RHS)
{
    m_LHS = LHS;
    m_RHS = NULL;
    m_oType = type;
}

bExpression::bExpression(Operator_type oType, Expression *LHS, Expression *RHS)
{
    m_LHS = LHS;
    m_RHS = RHS;
    m_oType = oType;
}
