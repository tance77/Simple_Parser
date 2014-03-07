#include "expression.h"
#include "variable.h"
#include "gpl_assert.h"
#include <math.h>

//expression base area
int Expression::evalint()
{
    assert(m_gType == INT);
    switch (m_oType) {
        case OR:
            return m_LHS->evalint() || m_RHS->evalint();
        case AND:
            return m_LHS->evalint() && m_RHS->evalint();
        case LESS_THAN_EQUAL:
        {
            if (m_LHS->m_gType == STRING || m_RHS->m_gType == STRING)
                return m_LHS->evalstring() <= m_RHS->evalstring();
            else if (m_LHS->m_gType == INT || m_RHS->m_gType == INT)
                return (m_LHS->evalint() <= m_RHS->evalint());
            else return (m_LHS->evaldouble() <= m_RHS->evaldouble());
        }
        case LESS_THAN:
        {
            if (m_LHS->m_gType == STRING || m_RHS->m_gType == STRING)
                return m_LHS->evalstring() < m_RHS->evalstring();
            else if (m_LHS->m_gType == INT || m_RHS->m_gType == INT)
                return (m_LHS->evalint() < m_RHS->evalint());
            else return (m_LHS->evaldouble() < m_RHS->evaldouble());
        }
        case GREATER_THAN_EQUAL:
        {
            if (m_LHS->m_gType == STRING || m_RHS->m_gType == STRING)
                return m_LHS->evalstring() >= m_RHS->evalstring();
            else if (m_LHS->m_gType == INT || m_RHS->m_gType == INT)
                return (m_LHS->evalint() >= m_RHS->evalint());
            else return (m_LHS->evaldouble() >= m_RHS->evaldouble());        }
        case GREATER_THAN:
        {
            if (m_LHS->m_gType == STRING || m_RHS->m_gType == STRING)
                return m_LHS->evalstring() > m_RHS->evalstring();
            else if (m_LHS->m_gType == INT || m_RHS->m_gType == INT)
                return (m_LHS->evalint() > m_RHS->evalint());
            else return (m_LHS->evaldouble() > m_RHS->evaldouble());
        }
        case EQUAL:
        {
            if (m_LHS->m_gType == STRING || m_RHS->m_gType == STRING)
                return m_LHS->evalstring() == m_RHS->evalstring();
            else if (m_LHS->m_gType == INT || m_RHS->m_gType == INT)
                return (m_LHS->evalint() == m_RHS->evalint());
            else return (m_LHS->evaldouble() == m_RHS->evaldouble());
        }
        case NOT_EQUAL:
        {
            if (m_LHS->m_gType == STRING || m_RHS->m_gType == STRING)
                return m_LHS->evalstring() != m_RHS->evalstring();
            else if (m_LHS->m_gType == INT || m_RHS->m_gType == INT)
                return (m_LHS->evalint() != m_RHS->evalint());
            else return (m_LHS->evaldouble() != m_RHS->evaldouble());
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
        default:
            //error message probably
            break;
    }
    return m_iValue;

}
double Expression::evaldouble()
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
    return m_dValue;
}
std::string* Expression::evalstring()
{
    return m_sValue;
}
Gpl_type Expression::get_gType()
{
    return m_gType;
}
Operator_type Expression::get_oType()
{
    return m_oType;
}
int Expression::getiValue()
{
    return m_iValue;
}
double Expression::getdValue()
{
    return m_dValue;
}
std::string* Expression::getsValue()
{
    return m_sValue;
}