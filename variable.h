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
        Variable(){m_sSymbol = NULL, m_eExpression = NULL;};
        Variable(string value, Expression *expression){};
        Gpl_type gettype();
        void evaluate();
        int getiValue();
        double getdValue();
        string getsValue();
    private:
        Gpl_type m_gType;
        Symbol *m_sSymbol;
        Expression *m_eExpression;
};
#endif
