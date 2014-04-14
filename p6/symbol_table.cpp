#include "symbol_table.h"
#include "gpl_type.h"
#include <assert.h>


Symbol_table *Symbol_table::m_instance = 0;

Symbol_table *Symbol_table::instance()
{
  if(m_instance == 0)
    m_instance = new Symbol_table();
  return m_instance;
}
void Symbol_table::print(ostream &os)
{
  it = mTable.begin();
  while (it != mTable.end())
    {
    if (it->second->getType() == INT)
      {
      
      os << "int" << " "
      << it->second->getID() << " "
      << it->second->getintValue()
      << endl;
      }
    if(it->second->getType() == DOUBLE)
      {
      os << "double" << " "
      << it->second->getID() << " "
      << it->second->getdoubleValue() << endl;
      }
    if(it->second->getType() == STRING)
      {
      os << "string" << " "
      << it->second->getID() << " \""
      << it->second->getstringValue() << "\"" << endl;
      }
    if(it->second->getType() == GAME_OBJECT)
      (it->second->getgameobjectValue())->print(os);
    it++;
    }
}
Symbol* Symbol_table::lookup(string target)
{
  if(mTable.find(target) == mTable.end() ) // &&   mTable.find(target + "[0]") == mTable.end())
    return NULL;
  else return mTable.find(target)->second;
}
void Symbol_table::insert(string ID, Symbol *symbol)
{
  mTable.insert(pair<string, Symbol*>(ID, symbol));
}
bool Symbol_table::get(string name, int &value)
{
  Symbol *cur = lookup(name);
  if (!cur /*|| !cur->is_int()*/)
    return false;
  
  value = cur->getintValue();
  return true;
}
bool Symbol_table::get(string name, double &value)
{
  Symbol *cur = lookup(name);
  if (!cur /*|| !cur->is_int()*/)
    return false;
  
  value = cur->getdoubleValue();
  return true;
}
bool Symbol_table::get(string name, string &value)
{
  Symbol *cur = lookup(name);
  if (!cur /*|| !cur->is_int()*/)
    return false;
  
  value = cur->getstringValue();
  return true;
}
bool Symbol_table::get_type (string name, Gpl_type &value)
{
  Symbol *cur = lookup(name);
  if (!cur /*|| !cur->is_int()*/)
    return false;
  
  value = cur->getType();
  return true;
}
bool Symbol_table::set(string name, int value){ // used for mouse_x, mouse_y
  return true;
}