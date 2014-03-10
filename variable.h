#ifndef variable_h
#define variable_h

#include <string>
#include "gpl_type.h"
#include "symbol.h"

class Expression;
class Variable
{
public:
    ~Variable();
    Variable();
    Variable(Symbol *s);
    Variable(string value, Expression *e){m_sValue = value, m_Expression = e;};
    Gpl_type gettype();
    void evaluate();
    int getiValue();
    double getdValue();
    string getsValue();
    void setSymbol();
private:
    int m_iValue;
    double m_dValue;
    string m_sValue;
    Gpl_type m_Type;
    Symbol *m_Symbol;
    Variable *m_Variable;
    Expression *m_Expression;
};
#endif
