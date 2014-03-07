#ifndef expression_h
#define expression_h

#include <string>
#include "gpl_type.h"
#include "symbol.h"

class Variable;
class Expression
{
public:
    //Expression(Variable *variable){};
    //Expression(Gpl_type gType, Expression *LHS, Expression *RHS);
    // Expression(Operator_type oType, Expression *LHS, Expression *RHS);
    virtual int evalint();
    virtual double evaldouble();
    virtual std::string evalstring();
    Gpl_type getType();
protected:
    Expression *m_LHS;
    Expression *m_RHS;
private:
    Gpl_type m_gType;
    Operator_type m_oType;
};

class iExpression : public Expression
{
public:
    iExpression(int i, Gpl_type gType);
    //Gpl_type getType();
    int getValue();
private:
    int mValue;
    Gpl_type m_Type;
};

class dExpression : public Expression
{
public:
    // virtual void evaluate();
    double getValue();
    dExpression(double d, Gpl_type gType);
private:
    double mValue;
    Gpl_type m_Type;
};

class sExpression : public Expression
{
public:
    //virtual void evaluate();
    std::string getString();
    sExpression(std::string *s, Gpl_type gType);
private:
    std::string *mValue;
    Gpl_type m_Type;
};

class uExpression : public Expression
{
public:
    uExpression(Operator_type type, Expression *LHS);
    
private:
    Operator_type m_oType;
};

class bExpression : public Expression
{
public:
    bExpression(Operator_type oType, Expression *LHS, Expression *RHS);
    virtual int evalint();
    virtual double evaldouble();
    virtual std::string evalstring();
private:
    Operator_type m_oType;
    Gpl_type m_gType;
};

class vExpression : public Expression
{
public:
    vExpression(Variable *expr);
    vExpression(Symbol *symbol);
private:
    Variable *m_Variable;
    Expression *m_Expression;;
};
#endif
