#ifndef SYMBOL_H
#define SYMBOL_H

#include "gpl_type.h"
#include "game_object.h"
#include "variable.h"
#include <string>
using namespace std;

class Symbol
{
public:
  Symbol(){};
  /*INT*/Symbol(Gpl_type type, string name, int value){
    m_gType = INT;
    m_ID = name;
    m_iValue = value;
    m_Gameobject = NULL;
    m_Animation_block = NULL;
  };
  /*DOUBLE*/Symbol(Gpl_type type, string name, double value){
    m_gType = DOUBLE;
    m_ID = name;
    m_dValue = value;
    m_Gameobject = NULL;
    m_Animation_block = NULL;
  };
  /*STRING*/Symbol(Gpl_type type, string name, string value){
    m_gType = STRING;
    m_ID = name;
    m_sValue = value;
    m_Gameobject = NULL;
    m_Animation_block = NULL;
  };
  /*GAME OBJECT*/Symbol(string name, Game_object *value){
    m_gType = GAME_OBJECT;
    m_ID = name;
    m_Gameobject = value;
    m_Animation_block = NULL;
  };
  /*ANIMATION BLOCK*/Symbol(string name, Animation_block *value){
    m_gType = ANIMATION_BLOCK;
    m_ID = name;
    m_Animation_block = value;
    m_Gameobject = NULL;
  };
  int getintValue();
  double getdoubleValue();
  string getstringValue();
  Game_object *getgameobjectValue();
  Animation_block *getanimationValue();
  string getID();
  Gpl_type getType();
  bool is_int();
  
private:
  static Symbol *m_instance;
  Gpl_type m_gType;
  int m_iValue;
  double m_dValue;
  std::string m_sValue;
  std::string m_ID;
  Game_object *m_Gameobject;
  Animation_block *m_Animation_block;
};

#endif
