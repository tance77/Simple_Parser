#ifndef expression_h
#define expression_h

#include <string>
#include "gpl_type.h"
#include "symbol.h"
#include <sstream>
#include <cmath>

class Variable;
class Expression
{
public:
    Expression(int value , Gpl_type type){ //T_INT_CONSTANT
        m_iValue = value,
        m_gType = type,
        m_Variable = NULL,
        m_kind = "INT_CONSTANT",
        m_oType = GARBAGE,
        m_LHS = NULL,
        m_RHS = NULL,
        m_dValue = 0.0,
        m_sValue = "";
    };
    Expression(double value, Gpl_type type){ //T_DOUBLE_CONSTANT
        m_dValue = value,
        m_gType = type,
        m_Variable = NULL,
        m_kind = "DOUBLE_CONSTANT",
        m_oType = GARBAGE,
        m_LHS = NULL,
        m_RHS = NULL,
        m_iValue = 0,
        m_sValue = "";
    };
    Expression(std::string value, Gpl_type type){ //T_STRING_CONSTANT
        m_sValue = value,
        m_gType = type,
        m_Variable = NULL,
        m_kind = "STRING_CONSTANT",
        m_oType = GARBAGE,
        m_LHS = NULL,
        m_RHS = NULL,
        m_dValue = 0.0,
        m_iValue = 0;
    };
    Expression(Variable *variable){ //T_VARIABLE
        m_Variable = variable,
        m_kind = "VARIABLE",
        m_oType = GARBAGE,
        m_LHS = NULL,
        m_RHS = NULL,
        m_iValue = 0,
        m_dValue = 0.0,
        m_sValue = "",
        m_gType = m_Variable->gettype();;
    };
    
    Expression(Operator_type type, Expression *LHS, Expression *RHS); //BINARY_OPERATOR
    Expression(Operator_type type, Expression *RHS); //UNARY OPERATOR
    int getiValue();
    double getdValue();
    std::string getsValue();
    int evalint();
    double evaldouble();
    std::string evalstring();
    Gpl_type get_gType();
    Operator_type get_oType();
    Animation_block* get_Animation();
    std::string get_Kind();
    Expression* getLHS();
    Expression* getRHS();
private:
    int m_iValue;
    double m_dValue;
    std::string m_sValue;
    std::string m_kind;
    Expression *m_LHS;
    Expression *m_RHS;
    Variable *m_Variable;
    Expression *m_Expression;
    Gpl_type m_gType;
    Operator_type m_oType;
};
#endif
