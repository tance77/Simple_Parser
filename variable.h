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
        Variable(){m_Symbol = NULL, m_Expression = NULL;};
        Variable(string value, Expression *expression){};
        Gpl_type gettype();
        void evaluate();
        int getiValue();
        double getdValue();
        string getsValue();
        void setSymbol();
    private:
        Gpl_type m_Type;
        Symbol *m_Symbol;
        Variable *m_Variable;
        Expression *m_Expression;
};
#endif
