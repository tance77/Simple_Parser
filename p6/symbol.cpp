#include "symbol.h"
#include "gpl_type.h"
//
//Symbol *Symbol::m_instance = 0;
//
//Symbol *Symbol::instance()
//{
//  if(m_instance == 0)
//    m_instance = new Symbol();
//  return m_instance;
//}
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
