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
Game_object *Symbol::getgameobjectValue()
{
    return m_Gameobject;
}
Animation_block *Symbol::getanimationValue()
{
    return m_Animation_block;
}
bool Symbol::is_int()
{
    if(m_gType == INT)
        return true;
    else return false;
}
void Symbol::set(int value)
{
    m_iValue = value;
}
void Symbol::set(double value)
{
    m_dValue = value;
}
void Symbol::set(std::string value)
{
    m_sValue = value;
}
void Symbol::set(Game_object *value)
{
    m_Gameobject = value;
}