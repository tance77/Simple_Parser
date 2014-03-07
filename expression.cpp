#include "expression.h"
#include "variable.h"
#include <assert.h>
#include <math.h>

//expression base area
int Expression::evalint()
{
    return 7;
}
double Expression::evaldouble()
{
    return 42;
}
std::string Expression::evalstring()
{
    return "hello";
}
Gpl_type Expression::getType()
{
    return m_gType;
}
//integer expression area
iExpression::iExpression(int a, Gpl_type type)
{
    mValue = a;
    m_Type = type;
}
//double expression area
dExpression::dExpression(double d, Gpl_type type)
{
    mValue = d;
    m_Type = type;
}
//string expression area
sExpression::sExpression(std::string *s, Gpl_type gType)
{
    mValue = s;
    m_Type = gType;
}
//unary expression area
uExpression::uExpression(Operator_type type, Expression *RHS)
{
    m_LHS = NULL;
    m_RHS = RHS;
    m_oType = type;
}
//binary expression area
bExpression::bExpression(Operator_type oType, Expression *LHS, Expression *RHS)
{
    m_LHS = LHS;
    m_RHS = RHS;
    m_oType = oType;
}
int bExpression::evalint()
{
    assert(m_gType == INT);
    switch (m_oType) {
        case OR:
            return m_LHS->evalint() || m_RHS->evalint();
        case AND:
            return m_LHS->evalint() && m_RHS->evalint();
        case LESS_THAN_EQUAL:
        {
            if (m_LHS->getType() == STRING || m_RHS->getType() == STRING)
                return m_LHS->evalstring() <= m_RHS->evalstring();
            else if (m_LHS->getType() == INT || m_RHS->getType() == INT)
                return (m_LHS->evalint() <= m_RHS->evalint());
            else return (m_LHS->evaldouble() <= m_RHS->evaldouble());
        }
        case LESS_THAN:
        {
            if (m_LHS->getType() == STRING || m_RHS->getType() == STRING)
                return m_LHS->evalstring() < m_RHS->evalstring();
            else if (m_LHS->getType() == INT || m_RHS->getType() == INT)
                return (m_LHS->evalint() < m_RHS->evalint());
            else return (m_LHS->evaldouble() < m_RHS->evaldouble());
        }
        case GREATER_THAN_EQUAL:
        {
            if (m_LHS->getType() == STRING || m_RHS->getType() == STRING)
                return m_LHS->evalstring() >= m_RHS->evalstring();
            else if (m_LHS->getType() == INT || m_RHS->getType() == INT)
                return (m_LHS->evalint() >= m_RHS->evalint());
            else return (m_LHS->evaldouble() >= m_RHS->evaldouble());        }
        case GREATER_THAN:
        {
            if (m_LHS->getType() == STRING || m_RHS->getType() == STRING)
                return m_LHS->evalstring() > m_RHS->evalstring();
            else if (m_LHS->getType() == INT || m_RHS->getType() == INT)
                return (m_LHS->evalint() > m_RHS->evalint());
            else return (m_LHS->evaldouble() > m_RHS->evaldouble());
        }
        case EQUAL:
        {
            if (m_LHS->getType() == STRING || m_RHS->getType() == STRING)
                return m_LHS->evalstring() != m_RHS->evalstring();
            else if (m_LHS->getType() == INT || m_RHS->getType() == INT)
                return (m_LHS->evalint() != m_RHS->evalint());
            else return (m_LHS->evaldouble() != m_RHS->evaldouble());
        }
        case NOT_EQUAL:
        {
            if (m_LHS->getType() == STRING || m_RHS->getType() == STRING)
                return m_LHS->evalstring() == m_RHS->evalstring();
            else if (m_LHS->getType() == INT || m_RHS->getType() == INT)
                return (m_LHS->evalint() == m_RHS->evalint());
            else return (m_LHS->evaldouble() == m_RHS->evaldouble());
        }
        case PLUS:
            return m_LHS->evalint() + m_RHS->evalint();
        case MINUS:
            return m_LHS->evalint() - m_RHS->evalint();
        case MULTIPLY:
            return m_LHS->evalint() * m_RHS->evalint();
        case DIVIDE:
            return m_LHS->evalint() * m_RHS->evalint();
        case MOD:
            return m_LHS->evalint() % m_RHS->evalint();
            break;
        default:
            //probabaly an error message here or something
            break;
    }
    return 0;
}
double bExpression::evaldouble()
{
    assert(m_gType == DOUBLE);
    switch (m_oType) {
        case SIN:
            return sin(m_RHS->evaldouble());
        case COS:
            return cos(m_RHS->evaldouble());
        case TAN:
            return tan(m_RHS->evaldouble());
        case ASIN:
            return asin(m_RHS->evaldouble());
        case ACOS:
            return acos(m_RHS->evaldouble());
        case ATAN:
            return atan(m_RHS->evaldouble());
        default:
            //probably error here
            break;
    }
    return 0;
}
std::string bExpression::evalstring()
{
    return "bye";
}
//variable expression area
vExpression::vExpression(Variable *var)
{
    m_Variable = var;
}
