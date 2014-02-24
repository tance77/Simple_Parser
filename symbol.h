#ifndef SYMBOL_H
#define SYMBOL_H

#include "gpl_type.h"
#include <string>
using namespace std;

class Symbol
{
public:
    Symbol(){};
    Symbol(Gpl_type turtle, string name, int value){m_gType = turtle; m_ID = name; m_iValue = value;};
    Symbol(Gpl_type turtle, string name, double value){m_gType = turtle; m_ID = name; m_dValue = value;};
    Symbol(Gpl_type turtle, string name, string value){m_gType = turtle; m_ID = name; m_sValue = value;};
    int getintValue();
    double getdoubleValue();
    string getstringValue();
    string getID();
    Gpl_type getType();
    
private:
    Gpl_type m_gType;
    int m_iValue;
    double m_dValue;
    string m_sValue;
    string m_ID;
};

#endif
