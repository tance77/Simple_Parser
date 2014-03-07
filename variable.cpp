#include "variable.h"
#include "expression.h"

int Variable::getiValue()
{
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
