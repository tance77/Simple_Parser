#ifndef SYMBOL_H
#define SYMBOL_H

#include "gpl_type.h"
#include "game_object.h"
#include <string>
using namespace std;

class Symbol
{
public:
  Symbol(){};
  Symbol(Gpl_type type, string name, int value){m_gType = type; m_ID = name; m_iValue = value;};
  Symbol(Gpl_type type, string name, double value){m_gType = type; m_ID = name; m_dValue = value;};
  Symbol(Gpl_type type, string name, string value){m_gType = type; m_ID = name; m_sValue = value;};
  Symbol(string name, Game_object *value){m_gType = GAME_OBJECT; m_ID = name; m_Gameobject = value;};
//  Symbol(Gpl_type type, string name, Circle value){m_gType = type; m_ID = name; m_Circle = value;};
//  Symbol(Gpl_type type, string name, Rectangle value){m_gType = type; m_ID = name; m_Rectangle = value;};
//  Symbol(Gpl_type type, string name, Pixmap value){m_gType = type; m_ID = name; m_Pixmap = value;};
//  Symbol(Gpl_type type, string name, Textbox value){m_gType = type; m_ID = name; m_Textbox = value;};
//  Symbol(Gpl_type type, string name, Triangle value){m_gType = type; m_ID = name; m_Triangle = value;};
//  const Symbol &operator=(const Symbol &);
//  static Symbol *instance();
  int getintValue();
  double getdoubleValue();
  string getstringValue();
  Game_object *getgameobjectValue();
  string getID();
  Gpl_type getType();
  
private:
  static Symbol *m_instance;
  Gpl_type m_gType;
  int m_iValue;
  double m_dValue;
  std::string m_sValue;
  std::string m_ID;
  Game_object *m_Gameobject;
//  Circle m_Circle;
//  Rectangle m_Rectangle;
//  Pixmap m_Pixmap;
//  Textbox m_Textbox;
//  Triangle m_Triangle;
};

#endif
