#include "expression.h"
#include "variable.h"

iExpression::iExpression(Gpl_type type, Expression *LHS, Expression *RHS) : Expression(m_Type, LHS, RHS)
{
    m_Type = type;
    m_LHS = NULL;
    m_RHS = NULL;
}

dExpression::dExpression(Gpl_type type, Expression *LHS, Expression *RHS) : Expression(type, LHS, RHS)
{
    m_LHS = NULL;
    m_RHS = NULL;
    m_Type = type;
}

sExpression::sExpression(Gpl_type gType, Expression *LHS, Expression *RHS) : Expression (gType, LHS, RHS)
{
    m_LHS = NULL;
    m_RHS = NULL;
    m_Type = gType;    
}

uExpression::uExpression(Operator_type type, Expression *LHS, Expression *RHS) : Expression (type, LHS, RHS)
{
    m_LHS = LHS;
    m_RHS = NULL;
    m_oType = type;
}

bExpression::bExpression(Operator_type oType, Expression *LHS, Expression *RHS) : Expression (oType, LHS, RHS)
{
    m_LHS = LHS;
    m_RHS = RHS;
    m_oType = oType;
}
