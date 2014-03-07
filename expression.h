#ifndef expression_h
#define expression_h

#include <string>
#include "gpl_type.h"
#include "symbol.h"

class Variable;
class Expression
{
public:
    Expression(int value , Gpl_type type){m_iValue = value, m_gType = type, m_kind = "INT_CONSTANT";}; //T_INT_CONSTANT
    Expression(double value, Gpl_type type){m_dValue = value, m_gType = type, m_kind = "DOUBLE_CONSTANT";};//T_DOUBLE_CONSTANT
    Expression(std::string *value, Gpl_type type){m_sValue = value, m_gType = type, m_kind = "STRING_CONSTANT";};//T_STRING_CONSTANT
    Expression(Variable *variable){};//T_VARIABLE
    Expression(Operator_type type, Expression *LHS, Expression *RHS){m_oType = type, m_LHS = LHS, m_RHS = RHS;}; //BINARY_OPERATOR
    Expression(Operator_type type, Expression *RHS){m_oType = type; m_LHS = NULL, m_RHS = RHS;};
    int getiValue();
    double getdValue();
    std::string* getsValue();
    int evalint();
    double evaldouble();
    std::string* evalstring();
    Gpl_type get_gType();
    Operator_type get_oType();
private:
    int m_iValue;
    double m_dValue;
    std::string *m_sValue;
    std::string m_kind;
    Expression *m_LHS;
    Expression *m_RHS;
    Variable *m_Variable;
    Expression *m_Expression;
    Gpl_type m_gType;
    Operator_type m_oType;
};
#endif
