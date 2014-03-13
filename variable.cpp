#include "variable.h"
#include "expression.h"

int Variable::getiValue()
{
   // cout << "i = " << m_Symbol->getintValue() << endl;
 return m_Symbol->getintValue();
}
double Variable::getdValue()
{
    return m_Symbol->getdoubleValue();
}
std::string Variable::getsValue()
{
    return m_Symbol->getstringValue();
}

Variable::Variable(Symbol *target)
{
    m_Symbol = target;
    m_iValue = getiValue();
    m_dValue = getdValue();
    m_sValue = getsValue();
}
Gpl_type Variable::gettype()
{
    return m_Symbol->getType();
}
