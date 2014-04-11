#include "symbol.h"
#include "gpl_type.h"
int Symbol::getintValue()
{
        return m_iValue;
}
double Symbol::getdoubleValue()
{
        return m_dValue;
}
string Symbol::getstringValue()
{
        return m_sValue;
}
string Symbol::getID()
{
    return m_ID;
}
Gpl_type Symbol::getType()
{
    return m_gType;
}
